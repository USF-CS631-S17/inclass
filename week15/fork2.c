/* fork2.c - example of using the fork and execl system calls */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        pid_t id;

        id = fork();

        if (id == 0) {
                /* we are in the child */
                execl("/bin/date", "date", NULL);
                printf("Child: WE DON'T SEE THIS\n");
                exit(0);
        } else {
                /* we are in the parent */
                id = wait(NULL);
                printf("Parent: child terminated\n");
        }

        return 0;
}


