*This project has been created as part of the 42 curriculum by mkaradas, acakici.*

# 42 - push_swap

İki yığıt (Stack A ve Stack B) ve kısıtlı bir komut kümesi kullanarak verilen tamsayı dizisini minimum operasyonla küçükten büyüğe sıralayan sistem programlama projesi. 42 standartlarına ve Norminette kurallarına uygun olarak C dilinde sıfırdan geliştirilmiştir.

---

## 📌 Proje Mimarisi ve Mantığı

- **Stack A:** Başlangıçta rastgele sırayla girilen tamsayıları tutar.
- **Stack B:** Sıralama sırasında ara depo olarak kullanılan boş yığıt.
- **Normalizasyon (Indexing):** Diziye alınan elemanlar, negatif veya çok büyük sayılardan bağımsız çalışabilmek adına sıralamadaki bağıl büyüklüklerine göre `0` ile `N - 1` aralığında indekslenir.

---

## ⚙️ İzin Verilen Komutlar

| Komut | Açıklama |
| :--- | :--- |
| `sa` / `sb` / `ss` | Yığıtın en üstündeki ilk iki elemanın yerini değiştirir (Swap). |
| `pa` / `pb` | Bir yığıtın tepesindeki elemanı diğer yığıtın tepesine aktarır (Push). |
| `ra` / `rb` | Tüm elemanları 1 adım yukarı kaydırır; en baştaki eleman en sona geçer (Rotate). |
| `rr` | `ra` ve `rb` komutlarını senkronize çalıştırır. |
| `rra` / `rrb` | Tüm elemanları 1 adım aşağı kaydırır; en sondaki eleman en başa geçer (Reverse rotate). |
| `rrr` | `rra` ve `rrb` komutlarını senkronize çalıştırır. |

---

## 🧠 Stratejiler ve Algoritmalar

Program bünyesinde matematiksel karmaşıklıklarına göre farklı sıralama algoritmaları barındırır:

- **Small Sort (2 - 5 Eleman):** Minimum hamle kombinasyonlarıyla hard-coded çözümler.
- **Simple ($O(n^2)$):** Minimum elemanı sürekli tepeye çekip aktaran temel sıralama yaklaşımı.
- **Medium ($O(n\sqrt{n})$ - Chunk / Kelebek):** Sayıları dilimlere (chunk) ayırıp Stack B üzerinde kum saati/kelebek yapısı kurarak A'ya sıralı geri toplayan optimize algoritma.
- **Complex ($O(n \log n)$ - Radix Sort):** Sayıların normalize edilmiş indekslerinin bit basamaklarına (0 ve 1) göre çalışan deterministik ikili taban algoritması.
- **Adaptive Mod (Varsayılan):** Dizideki hatalı ikili (inversion) sayısına göre `disorder` (düzensizlik) oranını ölçer ve veriye en uygun algoritmayı otomatik seçer.

---

## 🛠️ Kurulum ve Derleme

```bash
# push_swap çalıştırılabilir dosyasını derler
make

# Nesne (.o) dosyalarını temizler
make clean

# Tam temizlik yapar
make fclean

# Sıfırdan yeniden derler
make re
```

---

## 🚀 Kullanım ve Bayraklar

Program tekil argümanları veya tırnak içinde verilen metin bloklarını kabul eder:

```bash
# Standart kullanım
./push_swap 3 2 1 5 4
./push_swap "3 2 1 5 4"

# İstatistik ve Benchmark raporu ile çalıştırma
./push_swap --bench 3 2 1 5 4

# Belirli bir algoritmayı manuel olarak zorlama
./push_swap --bench --simple 4 3 2 1
./push_swap --bench --medium 4 3 2 1
./push_swap --bench --complex 4 3 2 1
```

Hamle sayısını saymak ve doğrulama yapmak için:

```bash
# Hamle adedi
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Checker ile doğrulama (Linux/Mac checker binary'si ile)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

---

## ⚠️ Hata Yönetimi

Aşağıdaki senaryolarda program tüm tahsis edilmiş belleği (heap) temizler, standart hata akışına (`stderr`, fd `2`) `Error\n` basar ve `1` çıkış koduyla sonlanır:

- Rakam harici geçersiz karakterler veya biçim bozuklukları
- Integer sınırlarını (`INT_MIN`, `INT_MAX`) aşan değerler (Overflow/Underflow)
- Yinelenen (duplicate) tamsayılar

---

## 👥 Ekip & AI Beyanı

- **Geliştiriciler:** `<mkaradas>`, `<acakici>` (Pair-programming / 42)
- **AI Kullanımı:** README dokümantasyonu, kavramsal algoritma pekiştirmeleri ve görselleştirici web arayüzünün ("Molinet") tasarım süreçlerinde destekleyici araç olarak yapay zekadan faydalanılmıştır.
- **Görselleştirici (Molinet):** https://push-swap-six.vercel.app/
