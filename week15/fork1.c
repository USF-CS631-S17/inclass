/* fork1.c - example of using the fork system call */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        pid_t id;
        int x = 3;

        printf("Parent: x = %d\n", x);

        id = fork();

        if (id == 0) {
                /* we are in the child */
                printf("Child: id = %d\n", id);
                printf("Child PID = %d\n", getpid());
                printf("Child: x = %d\n", x);
                x = 99;
                printf("Child: x = %d\n", x);
                printf("Child: &x = 0x%8X\n", &x);
                exit(0);
        } else {
                /* we are in the parent */
                printf("Parent PID = %d\n", getpid());
                printf("Parent: id = %d\n", id);
                printf("Parent: wait for child\n");
                id = wait(NULL);
                printf("Parent: child terminated pid = %d\n", id);
                printf("Parent: x = %d\n", x);
                printf("Parent: &x = 0x%8X\n", &x);
        }

        return 0;
}

