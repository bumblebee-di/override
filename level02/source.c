#include <stdio.h>

int main(void) {

    char username[112];
    char ptr[48];
    char password[100];

    bzero(username, 12);

    bzero(ptr, 5);

    bzero(password, 12);

    FILE *fp;
    size_t size;

    fp = fopen("/home/users/level03/.pass", "r");

    if (fp == 0) {

        fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
        exit(1);

    }

    size = fread(&ptr, 1, 41, fp);
    ptr[strcspn(ptr, "\n")] = '\0';
    if (size != 41) {
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        exit(1);
    }
    fclose(fp);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("--[ Password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = '\0';

    puts("*****************************************");
    if (strncmp(password, ptr, 41) == 0)
    {
        printf("Greetings, %s!\n", username);
        system("/bin/sh");
        return 0;
    }


    printf(username);
    puts(" does not have access!");
    exit(1);

}