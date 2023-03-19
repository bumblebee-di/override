#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *a_user_name; // (gdb) info variables 

int verify_user_name(void) {
    puts("verifying username....\n");
    return strncmp(a_user_name, "dat_wil", 7);
}

int verify_user_pass(char *password) {
    return strncmp(a_user_name, "admin", 5);
}

int main(void) {
    char buffer[16];

    bzero(buffer, 16);

    int check;

    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");

    fgets(a_user_name, 256, stdin);

    check = verify_user_name();
    if (check != 0) {
        puts("nope, incorrect username...\n");
        return 1;
    }

    puts("Enter Password: ");

    fgets(&buffer, 100, stdin);

    check = verify_user_pass(buffer);
    if (check == 0) {
        puts("nope, incorrect password...\n");
        return 1;
    }
    if (check == 0) {
        return 0;
    }
    return 0;
}