#include<stdio.h>
#include<sys/times.h>
#include<unistd.h>

#define ITERS 100000
#define ITERS2 10000

int main(void)
{
    int ticks_per_second;
    struct tms t1, t2;
    int i, j;
    unsigned x = 0;
    double total_secs = 0.0;
    
    ticks_per_second = sysconf(_SC_CLK_TCK);

    printf("ticks_per_second = %d\n", ticks_per_second);

    times(&t1);
    for (i = 0; i < ITERS; i++) {
        for (j = 0; j < ITERS2; j++) {
            x += 1;
        }
    }
    times(&t2);
    
    printf("t1.tms_utime = %d\n", t1.tms_utime);
    printf("t2.tms_utime = %d\n", t2.tms_utime);

    total_secs = ((double) (t2.tms_utime - t1.tms_utime)) / ((double) ticks_per_second);

    printf("total_secs = %lf\n", total_secs);
    
    return 0;
}
