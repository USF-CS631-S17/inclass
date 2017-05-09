#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

char *prog1 = "ls";
char *prog2 = "wc";

int main(int argc, char **argv)
{
    pid_t id;
    int fds[2];
    int i = 0;
    char buf[32];

    pipe(fds);

    /* Fork first process */
    id = fork();

    if (id < 0) {
        printf("fork() for first process failed\n");
        exit(-1);
    }

    if (id == 0) {
        /* Close read end of pipe */
        close(fds[0]);

        /* Close stdout */
        close(1);

        /* Dup write end of pipe */
        dup(fds[1]);

        /* Close extra write end of pipe */
        close(fds[1]);

        if (execlp(prog1, prog1, NULL) < 0) {
            write(2, "execlp() failed for prog1\n", 27);
            exit(-1);
        }

        /* We will never reach this point */
    }

    /* Fork second process */

    id = fork();

    if (id < 0) {
        printf("fork() for second process failed\n");
        exit(-1);
    }

    if (id == 0) {
        /* Close write end of pipe */
        close(fds[1]);

        /* Close stdin */
        close(0);

        /* Dup read end of pipe */
        dup(fds[0]);

        /* Close extra read end of pipe */
        close(fds[0]);

        if (execlp(prog2, prog2, NULL) < 0) {
            write(2, "execlp() failed for prog2\n", 27);
            exit(-1);
        }
    }

    /* Need to close both ends of pipe in parent */
    close(fds[0]);
    close(fds[1]);
    
    id = wait(NULL);
    id = wait(NULL);
    
    return 0;
}
