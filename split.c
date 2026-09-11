#include "push_swap.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	if (!s)
		return (0);
	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char	*letter_word(const char *s, char c)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len] && s[len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_all(char **dest, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**dest;

	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			dest[j] = letter_word(s, c);
			if (!dest[j])
				return (free_all(dest, j));
			j++;
			while (*s && *s != c)
				s++;
		}
	}
	dest[j] = NULL;
	return (dest);
}