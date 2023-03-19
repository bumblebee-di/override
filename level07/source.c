#include <stdio.h>

int get_unum() {

    unsigned int num = 0;

    fflush(stdout);

    scanf("%u", num);

    clear_stdin();

    return (num);
}

int store_number(int *array) {

    unsigned int num = 0;
    unsigned int index = 0;

    printf(" Number: ");
    num = get_unum();

    printf(" Index: ");
    index = get_unum();

    if ( index % 3 == 0 || (num >> 24) == 183 ) {

        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return 1;
    }

    array[index] = num;
    return 0;
}

int read_number(int *array) {

    unsigned int index = 0;

    printf(" Index: ");
    index = get_unum();

    printf(" Number at data[%u] is %u\n",  index, array[index]);
    return 0;
}

int main (int argc, char **argv, char **envp) {
    
    char **program_argv = argv;
    char **program_env = envp;
    
    char buffer[20];
    
    int number = 0;
    size_t i = 0;
    size_t j = 0;


    int arr[100];

    while (program_argv[i] != 0) {
        memset(program_argv[i], 0, strlen(program_argv[i]));
        i++;
    }

    while (program_env[j] != 0) {
        memset(program_env[j], 0, strlen(program_env[j]));
        j++;
    }

    puts("----------------------------------------------------\
        \n  Welcome to wil's crappy number storage service!   \
        \n----------------------------------------------------\
        \n Commands:                                          \
        \n    store - store a number into the data storage    \
        \n    read  - read a number from the data storage     \
        \n    quit  - exit the program                        \
        \n----------------------------------------------------\
        \n   wil has reserved some storage :>                 \
        \n----------------------------------------------------\n");
    

    while (1) {
        printf("Input command: ");
        
        fgets(buffer, 20 , stdin);
        buffer[strlen(buffer) - 1] = 0;

        if (strncmp(cmd, "store", 5) == 0)
            number = store_number(arr);
        else if (strncmp(cmd, "read", 4) == 0)
            number = read_number(arr);
        else if (strncmp(cmd, "quit", 4) == 0)
            break ;

        if (number == 0)
            printf(" Failed to do %s command\n", buffer);
        else
            printf(" Completed %s command successfully\n", buffer);
        
        bzero(buffer, 20);
    }

    return 0;
}

