#include <sys/types.h> 
#include <sys/wait.h>

int main() {

    pid_t pid = fork();

    char buffer[32];

    bzero(buffer, 32);

    int status = 0;
    int ret = 0;

    if (pid == 0) {
        prctl(1, 1);

        ptrace(0, 0, 0, 0);

        puts("Give me some shellcode, k");
        gets(buffer);
        return 0;
    }
    do {
        wait(&status);
        if ((status & 127) == 0 || (((status & 127) + 1) / 2) > 0) {
            puts("child is exiting...");
            return 0;
        }
        ret = ptrace(3, pid, 44, 0);
    } while (ret != 11)

    puts("no exec() for you");
    kill(pid, 9);
    return 0;
}
