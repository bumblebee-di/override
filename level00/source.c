#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int storage_password;

    puts("***********************************");
    puts("* \t     -Level00 -\t\t  *");
    puts("***********************************");

    printf("Password:");
    
    scanf("%d", &storage_password);

    if (storage_password == 5276) {
        puts("\nAuthenticated!");
        system("/bin/sh");
        return 0;
    }
    puts("\nInvalid Password!");
    return 1;

}