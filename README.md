*This project has been created as part of the 42 curriculum by <mkaradas>, <acakici>.*
# 42 - push_swap

İki stack (A ve B) ve sınırlı bir komut seti kullanarak, verilen integer dizisini minimum hamle sayısıyla küçükten büyüğe sıralama projesi. Proje 42 normlarına uygun şekilde C dilinde sıfırdan geliştirilmiştir.

---

## 📌 Proje Mantığı

Elimizde iki adet stack var:
- **Stack A:** Başlangıçta rastgele sırayla verilen sayıları tutar.
- **Stack B:** Sıralama sırasında ara depo olarak kullanılan boş stack.

Amaç, sadece izin verilen stack manipülasyon komutlarını kullanarak **Stack A**'yı en az işlemle artan sırada sıralamaktır.

---

## ⚙️ İzin Verilen Komutlar

| Komut | Açıklama |
| :--- | :--- |
| `sa` / `sb` / `ss` | İlk iki elemanın yerini değiştirir (Swap). |
| `pa` / `pb` | Bir stack'in en üstündeki elemanı diğer stack'in en üstüne atar (Push). |
| `ra` / `rb` | Stack'teki tüm elemanları bir yukarı kaydırır; ilk eleman en sona geçer (Rotate). |
| `rr` | `ra` ve `rb` komutlarını aynı anda çalıştırır. |
| `rra` / `rrb` | Stack'teki tüm elemanları bir aşağı kaydırır; son eleman en başa geçer (Reverse rotate). |
| `rrr` | `rra` ve `rrb` komutlarını aynı anda çalıştırır. |

---

## 🧠 Algoritma & Yaklaşım

Projede girdi boyutuna göre optimize edilmiş mantıklar kullanıldı:

- **2 & 3 Eleman:** Basit hard-coded koşullarla maksimum 2–3 hamlede sıralanır.
- **4 & 5 Eleman:** En küçük sayılar Stack B'ye itilip kalan 3 sayı sıralanır, ardından geri alınır.
- **Büyük Veri (100 & 500 Eleman):** 
  - Sayılar önce indexlenerek normalize edildi.
  - Elemanlar maliyet hesabı (cost/mechanical turk) veya chunk/radix tabanlı yöntemle Stack B'ye aktarıldı.
  - En uygun komut kombinasyonları (`rr`, `rrr` optimizasyonları dahil) hesaplanarak minimum adımla Stack A'da toplandı.

---

## 🛠️ Kurulum ve Derleme

Projeyi derlemek için terminalde ana dizine gidip `make` çalıştırmanız yeterlidir:

```bash
# Projeyi derler ve push_swap binary dosyasını üretir
make

# Nesne dosyalarını (.o) temizler
make clean

# Tüm derleme çıktılarını siler
make fclean

# Sıfırdan temiz derleme yapar
make re
```

---

## 🚀 Kullanım

Program argüman olarak integer listesi alır:

```bash
./push_swap 2 1 3 6 5 8
```

Tırnak içinde tek argüman olarak da verilebilir:

```bash
./push_swap "2 1 3 6 5 8"
```

Hamle sayısını test etmek için:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

Checker ile kontrol etmek için (OS X / Linux checker binary'si ile):

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

---

## ⚠️ Hata Yönetimi

Aşağıdaki durumlarda program ekrana `Error\n` yazdırır ve bellek sızıntısı (leak) bırakmadan güvenli bir şekilde sonlanır:
- Sayı harici karakter girildiğinde
- Integer sınırlarını (`INT_MIN`, `INT_MAX`) aşan değerlerde
- Tekrarlanan (duplicate) sayı varlığında

---

## 👥 Ekip

Bu proje iki arkadaş olarak pair-programming / collaborative mantıkla, 42 Okulu standartlarına ve Norminette kurallarına uygun şekilde geliştirilmiştir.


## AI Kullanımı
- readme dosyası direk yapay zekadan alındı.
- projede bilmediğimiz yerlerde konuyu daha iyi kavramak için kullandık.
- molinet tasarladık ve bu tasarım da çoğunluka yapay zeka kullandık.

molinet linki : https://push-swap-six.vercel.app/
