/* caps.c - convert user input to caps and write to a file */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
        char buffer[2];
        int fd;
        int count;
        long total = 0;

        if (argc != 2) {
                printf("usage: caps filename\n");
                exit(1);
        }
        
        if ( (fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0600)) < 0) {
                printf("Cannot open %s\n", argv[1]);
                exit(1);
        }

        while ( (count = read(0, buffer, 1)) > 0 ) {
                buffer[0] = toupper(buffer[0]);
                write(fd, buffer, 1);
        }

        close(fd);
        return(0);
}
