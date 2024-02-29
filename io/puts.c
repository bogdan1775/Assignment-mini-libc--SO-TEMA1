#include <stdio.h>
#include<unistd.h>
#include<string.h>

int puts(const char *s) {
    int len = strlen(s);
    write(1, s, len);
    write(1, "\n", 1);

    len++;
    return len;
}
