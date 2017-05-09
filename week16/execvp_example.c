#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char **argv)
{
    pid_t id;
    char *args[] = {"date", NULL};

    id = fork();

    if (id == 0) {
        if (execvp("date", args) < 0) {
            printf("execvp() failed\n");
            exit(-1);
        }
    }

    id = wait(NULL);

    return 0;
}
