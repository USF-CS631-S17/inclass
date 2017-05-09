/* pipe-exec.c - use a pipe to send "input" to another program */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
        pid_t id;
        int count;
        int fildes[2];

        pipe(fildes);

        if ((id = fork()) == 0) {
                /* we are in the child */
                close(0);         /* close stdin */
                dup(fildes[0]);   /* put read end of pipe into stdin index */
                close(fildes[1]); /* close "write" end of pipe */

                if (execlp("sort", "sort", NULL) < 0) {
                        printf("execl failed\n");
                        exit(1);
                }
        } else {
                /* we are in the parent */
                /* close "read" end of pipe */
                close(fildes[0]);
                /* send some data to sort */
                write(fildes[1], "bbb\n", 4);
                write(fildes[1], "ttt\n", 4);
                write(fildes[1], "aaa\n", 4);
                /* close write end to tell sort we are done */
                close(fildes[1]);
                id = wait(NULL); /* wait for child */
        }

        return(0);
}
