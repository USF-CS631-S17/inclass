#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

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
        close(fds[0]);
        write(fds[1], "hello", 5);
        close(fds[1]);
        exit(0);
    }

    /* Fork second process */

    id = fork();

    if (id < 0) {
        printf("fork() for second process failed\n");
        exit(-1);
    }

    if (id == 0) {
        close(fds[1]);
        while (read(fds[0], &buf[i], 1) > 0) {
            i += 1;
        }
        close(fds[0]);
        buf[i] = '\0';
        printf("Second process pipe data: %s\n", buf);
        exit(0);
    }

    close(fds[0]);
    close(fds[1]);
    
    id = wait(NULL);
    id = wait(NULL);
    
    return 0;
}
