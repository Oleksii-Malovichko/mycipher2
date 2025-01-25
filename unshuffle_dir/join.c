#include "unshuffle.h"

char	*join_str(char *s1, char *s2, char *result)
{
	unsigned int	index;
	unsigned int	len_s;

	index = 0;
	len_s = 0;
	while (s1[len_s] != '\0')
	{
		result[len_s] = s1[len_s];
		len_s++;
	}
	while (s2[index] != '\0')
	{
		result[len_s] = s2[index];
		index++;
		len_s++;
	}
	result[len_s] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*result;
	unsigned int	len_s;
	unsigned int	general_len;

	if (!s1 || !s2)
		return (NULL);
	general_len = 0;
	len_s = 0;
	while (s1[len_s] != '\0')
		len_s++;
	while (s2[general_len] != '\0')
		general_len++;
	general_len = len_s + general_len;
	result = (char *)malloc(sizeof(char) * (general_len + 1));
	if (!result)
		return (NULL);
	return (join_str(s1, s2, result));
}
