#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void log_wrapper(FILE *fp, char *msg, char *file)
{
    char buffer[255];

    strcpy(buffer, msg);
    snprintf(buffer + strlen(buffer), 255 - strlen(buffer) - 1, file);
    buffer[strcspn(buffer, "\n")] = '\0';
    fprintf(fp, "LOG: %s\n", buffer);
}

int main(int argc, char *argv[])
{
    char ch = -1;
    char path[100];
    FILE *file, *backup;
    int fp = -1;

    if (argc != 2)
        printf("Usage: %s filename\n", argv[0]);
    
    backup = fopen("./backups/.log", "w");
    if (backup == NULL){
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }

    log_wrapper(backup, "Starting back up: ", argv[1]);
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }

    strcpy(path, "./backups/");
    strncat(path, argv[1], 100 - strlen(path) - 1);
    fp = open(path, O_CREAT | O_EXCL | O_WRONLY, 0660);
    if (fp < 0) {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }

    while ((ch = fgetc(file)) != EOF)
        write(fp, &ch, 1);
    log_wrapper(backup, "Finished back up ", argv[1]);
    fclose(file);
    close(fp);
    return 0;
}