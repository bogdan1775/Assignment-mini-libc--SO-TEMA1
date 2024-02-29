// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
	int i = 0;

	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
	size_t i = 0;
	while (i <= len) {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';

	return destination;
}

char *strcat(char *destination, const char *source) {
	int len = strlen(destination);
	int i = 0;

	while (source[i] != '\0')
		destination[len++] = source[i++];

	destination[len] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
	int len_dest = strlen(destination);
	size_t i = 0;

	while (i < len)
		destination[len_dest++] = source[i++];

	destination[len_dest] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2) {
	size_t len = strlen(str1);
	if (strlen(str2) > len)
		len = strlen(str2);

	size_t i = 0;

	while (i < len) {
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] < str2[i])
			return -1;

		i++;
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len) {
	size_t i = 0;

	while (i < len) {
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] < str2[i])
			return -1;

		i++;
	}

	return 0;
}

size_t strlen(const char *str) {
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c) {
	int len = strlen(str);
	int i = 0;

	while (i < len) {
		if (str[i] == c)
			return (char *)str + i;
		i++;
	}

	return NULL;
}

char *strrchr(const char *str, int c) {
	int i = strlen(str) - 1;

	while (i >= 0) {
		if (str[i] == c)
			return (char *)str + i;
		i--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle) {
	size_t i = 0, j = 0;
	int poz = 0;

	while (haystack[i] != '\0') {
		if (j == 1)
			poz = i - 1;

		if (j < strlen(needle) && haystack[i] == needle[j])
			j++;
		else
			j = 0;

		if (j == strlen(needle))
			return (char *)haystack + poz;
		i++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
	int i = strlen(haystack) - 1, j = strlen(needle) - 1;

	if (strlen(haystack) < strlen(needle))
		return NULL;

	while (i >= 0) {
		if (j >= 0 && haystack[i] == needle[j])
			j--;
		else
			j = strlen(needle) - 1;

		i--;

		if (j < 0)
			return (char *)haystack + i + 1;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
	char *dest = destination;
	char *source2 = (char *)source;

	for (size_t i = 0; i < num; i++)
		dest[i] = source2[i];

	return destination;
}

// inspiratie memmove https://www.equestionanswers.com/c/memcpy-vs-memmove.php
void *memmove(void *destination, const void *source, size_t num) {
	char *dest = destination;
	char *source2 = (char *)source;

	if (destination < source) {
		for (size_t i = 0; i < num; i++)
			dest[i] = source2[i];
	} else {
		for (size_t i = num; i > 0; i--)
			dest[i - 1] = source2[i - 1];
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
	char *ptr_1 = (char *)ptr1;
	char *ptr_2 = (char *)ptr2;

	for (size_t i = 0; i < num; i++)
		if (ptr_1[i] < ptr_2[i])
			return -1;
		else if (ptr_1[i] > ptr_2[i])
			return 1;

	return 0;
}

void *memset(void *source, int value, size_t num) {
	char *ptr = source;

	for (size_t i = 0; i < num; i++)
		ptr[i] = (char)value;

	return source;
}
