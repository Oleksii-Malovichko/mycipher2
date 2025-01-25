#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// It's important, cause the unshuffle will need to get access to these files
#define CIPHERED	"ciphered.txt"	// the file, where will be the key for cipher
#define KEY			"key.txt"		// the file, where will be the ciphered text

char				*ft_itoa(int n);

#endif