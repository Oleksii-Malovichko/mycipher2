#ifndef UNSHUFFLE_H
#define UNSHUFFLE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../get_next_line/get_next_line.h"

#define CIPHERED	"ciphered.txt"	// the file, where will be the key for cipher

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_data(char *filename);

#endif