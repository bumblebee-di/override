
#include <stdlib.h>
#include <stdio.h>

struct data {
    int length;
    char user[40];
    char msg[140];
};

void secret_backdoor(struct data *data) {
    char buffer[128]; 
    
    fgets(buffer, 128, stdin);

    system(buffer);

}

void set_username (struct data *data) {

    puts(">: Enter your username");
    printf(">>: ");
    fgets(data->user, 128,);

}

void set_msg(struct data *data) {
    char buffer[140];

    bzero(buffer, 128);
    puts(">: Msg @Unix-Dude");
    printf(">>: ");

    fgets(buffer, 1024, stdin);
    strncpy(data->msg, buffer, data->length);

    for (i = 0; i <= 40 && buffer[i]; i++) {
        data->user[i] = buffer[i];
    }

    printf(">: Welcome, %s", data->user);

}

void handle_msg () {

    struct data data;

    bzero(data.user, 0, 40);

    data.length = 140;

    set_username(&data);

    set_msg(&data);

    puts(">: Msg sent!");
}

int main() {
    puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
    handle_msg();
    return 0;
}