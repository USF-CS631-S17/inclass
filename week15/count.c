/* count.c - count the number of bytes in a file */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


#define BUFSIZE 512  /* number of bytes to read at a time */

int main(int argc, char *argv[])
{
        char buffer[BUFSIZE];
        int fd;
        int count;
        long total = 0;

        if ( (fd = open(argv[1], O_RDONLY)) < 0) {
                printf("Cannot open %s\n", argv[1]);
                exit(1);
        }

        printf("fd = %d\n", fd);

        while ( (count = read(fd, buffer, BUFSIZE)) > 0 ) {
                total += count;
        }
        
        printf("Total bytes in %s is %ld\n", argv[1], total);

        close(fd);
        return(0);
}
