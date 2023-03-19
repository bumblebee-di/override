#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// gcc -std=c99 -m32 -static -mabi=sysv -o a.out source.c

void decrypt(int pass) {
    char str[17] = "Q}|u`sfg~sf{}|a3";

    for (int i = 0; i < 16; i++) {
        str[i] = str[i] ^ pass;
    }

    if (strncmp(str, "Congratulations!", 17) == 0)
        puts("Here is the system call occurs: system(\"/bin/sh\");\n");
        // system("/bin/sh");
    else
        puts("\nInvalid Password");
}

void test(int arg1, int arg2) {
    int var = arg2 - arg1;

    if (21 > var )
        decrypt(var);
    else
        decrypt(rand());
    return;
}

int main(void) {

    time_t seconds;

    seconds = time(NULL);

    srand(0);
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    puts("Password:");

    int pass = 0;
    scanf("%d", &pass);
    
    test(pass, 322424845);
    return 0;

}