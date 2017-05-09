/* redirect.c - example of redirection */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
        pid_t id;
        int fd;

        if ((fd = open("out", O_CREAT | O_WRONLY, 0644)) < 0) {
                printf("cannot open out\n");
                exit(1);
        }
        
        id = fork();

        if (id == 0) {
                /* we are in the child */
                /* close stdout in child */
                close(1);
                dup(fd);   /* replace stdout in child with "out" */
                close(fd);
                execl("/bin/date", "date", NULL);
        }

        /* we are in the parent */
        close(fd);
        id = wait(NULL);

        return 0;
}


