#include "shuffle.h"

int tab[128];

int random_number(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

char	*ft_strcpy(char *src)
{
	int i = 0;
	int len = ft_strlen(src);
	char *result = NULL;

	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len && src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*make_shuffle(char *message)
{
	char	*result;
	int 	index_ascii;
	int 	i;

	i = 0;
	result = ft_strcpy(message);
	if (!result)
		return NULL;
	while (message[i] != '\0')
	{
		index_ascii = message[i];
		result[i] = (unsigned char)tab[index_ascii];
		i++;
	}
	return (result);
}

void	send_key(char *filename)
{
	int		fd = open(filename, O_WRONLY | O_CREAT, 0666);
	char	*num;
	int 	i = 0;

	if (fd < 0)
		return ;
	while (i < 128)
	{
		num = ft_itoa(tab[i]);
		write(fd, num, ft_strlen(num));
		write(fd, "\n", 1);
		i++;
	}	
}

void	send_ciphered(char *filename, char *ciphered)
{
	int		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	char	*num;
	int 	i = 0;

	if (fd < 0)
		return ;
	num = ft_itoa(tab[i]);
	write(fd, ciphered, ft_strlen(ciphered));
	i++;
}

int main(int n, char **args)
{
	int 	len;
	int		i;
	char	*filename = KEY; // the file, where will be the key
	char	*filename2 = CIPHERED; // the one, where will be the ciphered text
	char	*message;

	if (n != 2)
		message = "Hello, mazafaka!";
	else
		message = args[1];
	srand((unsigned int)time(NULL));
	for (i = 0; i < 128; i++) // init of tab
	{
        tab[i] = i;
    }
    for (i = 127; i > 0; i--)
	{
        int j = rand() % (i + 1);
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
	char *ciphered = make_shuffle(message);
	send_key(filename);
	send_ciphered(filename2, ciphered);
	printf("%s\n", ciphered);
}