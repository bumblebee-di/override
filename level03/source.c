#include <time.h>
#include <stdio.h>
#include <string.h>

void decrypt(int pass) {
    char str[17] = "Q}|u`sfg~sf{}|a3";

    for (int i = 0; i < 16; i++) {
        str[i] = str[i] ^ pass;
    }

    if (strncmp(str, "Congratulations!", 17) == 0)
        puts("Congratulations!\n");
        // system("/bin/sh");
    else
        puts("\nInvalid Password");
}

void test(int arg1, int arg2) {
    int var = arg2 - arg1;

    if (21 > var )
        decrypt(var);
    // rand(arg2);
    // decrypt(rand());
    return;
}

int main(void) {

    // time_t seconds;

    // seconds = time(NULL);

    // srand(0);
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    puts("Password:");

    int pass = 0;
    scanf("%d", &pass);
    
    test(pass, 322424845);
    return 0;

}