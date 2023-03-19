void auth(char *login, unsigned int serial)
{
    login[strcspn(login, "\n")] = 0;
    size_t length = strnlen(login, 32);

    if (length > 5)
    {
        if (ptrace(0, 0, 1, 0) == -1)
        {
            puts("\033[32m.----------------------------.");
            puts("\033[31m| !! TAMPERING DETECTED !!  |");
            puts("\033[32m'----------------------------'");
            return 1;
        }
        int pass = (login[3] ^ 4919) + 6221293
        int i = 0;
        while (i < length)
        {
            if (login[i] <= 31)
                return 1;
            pass += modify_pass(login[i]);
            i++;
        }
        if (serial != pass)
            return 1;
        return 0;
    }
    return 1;
}

unsigned int get_unum() { // not used
    unsigned int num;
    fflush(STDIN);
    scanf("%u", &num);
    return num;
}

int main(int argc, char **argv)
{

    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");

    printf("-> Enter Login: ");

    char buffer[32];
    fgets(buffer, 32, stdin);

    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial: ");

    unsigned int serial;
    scanf("%u", &serial);

    if (auth(buffer, serial) != 0) {
        return 1;
    }
    puts("Authenticated!");
    system("/bin/sh");
    return 0;
}