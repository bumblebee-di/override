#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {

    int i = 0;
    char format[100];

    fgets(format, 100, stdin);

    while (i < strlen(format)) {

        if (format[i] <= 64 && fromat[i] > 90)
                format[i]  = format[i] ^ 32; 

        i++;
    }

    printf(format);
    exit (0);
}

