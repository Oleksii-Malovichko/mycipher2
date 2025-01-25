#include "unshuffle.h"

int	tab[128];

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int	get_tab(char *filename)
{
	int	fd = open(filename, O_RDONLY);
	int	i = 0;
	
	if (fd < 0)
		return -1;
	FILE *file = fdopen(fd, "r");
	if (!file)
	{
		close(fd);
		return -1;
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	while (i < 128 && (read = getline(&line, &len, file)) != -1)
	{
		tab[i] = atoi(line);
		i++;
	}
	free(line);
	fclose(file);
	return (0);

}

char	*make_unshuffle(char *ciphered)
{
	char	*result;
	int		len;
	int		i;
	int		index_ascii;

	len = ft_strlen(ciphered);
	result = malloc(len + 1);
	if (!result)
		return NULL;
	result[len] = '\0';
	i = 0;
	while (ciphered[i] != '\0')
	{
		index_ascii = 0;
		while (index_ascii < 128)
		{
			if (ciphered[i] == tab[index_ascii])
			{
				result[i] = index_ascii;
				break;
			}
			index_ascii++;
		}
		i++;
	}
	return (result);
}

char	*get_data(char *filename)
{
	int fd;
	char *line = NULL;
	char *result = "";

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return NULL;
	line = get_next_line(fd);
	while (line)
	{
		result = ft_strjoin(result, line);
		free(line);
		line = get_next_line(fd);
	}
	return (result);
}

int main(int n, char **args)
{
	char	*filename;
	// if (n != 2)
		// return 1;
	// else
		// filename = args[1];
	filename = CIPHERED;
	if (get_tab("key.txt") != 0)
		return 1;

	char	*ciphered = get_data(filename);
	// if (ciphered)
		// printf("%s\n", ciphered);
	char *unciphered = make_unshuffle(ciphered);
	if (unciphered)
		printf("%s\n", unciphered);
}// ./unshuffle $(./shuffle "Hello, world")