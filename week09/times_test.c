#include<stdio.h>
#include<sys/times.h>
#include<time.h>
#include<unistd.h>

#define ITERS 10000000
#define ITERS2 10

void test_loop(void)
{
    int j;
    unsigned x;

    for (j = 0; j < ITERS2; j++) {
        x += 1;
    }
}

void test_times(void)
{
    int ticks_per_second;
    struct tms t1, t2;
    int i;
    double total_secs = 0.0;
    double inner_loop_usecs = 0.0;

    /* technique using times() */
    
    ticks_per_second = sysconf(_SC_CLK_TCK);

    printf("ticks_per_second = %d\n", ticks_per_second);

    times(&t1);
    for (i = 0; i < ITERS; i++) {
        test_loop();
    }
    times(&t2);
    
    printf("t1.tms_utime = %d\n", t1.tms_utime);
    printf("t2.tms_utime = %d\n", t2.tms_utime);

    total_secs = ((double) (t2.tms_utime - t1.tms_utime)) / ((double) ticks_per_second);

    printf("total_secs = %lf\n", total_secs);

    inner_loop_usecs = 1000000.0 * (total_secs / ((double) ITERS));

    printf("inner_loop_usecs = %lf\n", inner_loop_usecs);
}

void test_clock_gettime()
{
    struct timespec t1, t2;
    int i;
    long total_nsecs = 0;
    time_t total_secs = 0;
    double total_time = 0.0;
    double inner_loop_usecs = 0.0;
    
    clock_gettime(CLOCK_MONOTONIC, &t1);
    for (i = 0; i < ITERS; i++) {
        test_loop();
    }
    clock_gettime(CLOCK_MONOTONIC, &t2);    

    total_secs = t2.tv_sec - t1.tv_sec;
    total_nsecs = t2.tv_nsec - t1.tv_nsec;

    printf("total_secs = %ld\n", total_secs);
    printf("total_nsecs = %ld\n", total_nsecs);

    total_time = (double) total_secs + ((double) total_nsecs) / 1000000000.0;
    
    printf("total_time = %lf\n", total_time);
    
    inner_loop_usecs = (((double) total_time) / ((double) ITERS)) * 1000000.0;

    printf("inner_loop_usecs = %lf\n", inner_loop_usecs);
}

int main(void)
{
    test_times();
    test_clock_gettime();
    
    return 0;
}
