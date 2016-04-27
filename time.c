#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

#include <signal.h>

static volatile int keepRunning = 1;

void intrHandler(int dummy) {
    keepRunning = 0;
}

int main()
{
    struct timeval start, end;

    long mtime, seconds, useconds;    

	signal(SIGINT, intrHandler);

    while (keepRunning) { 
	
		gettimeofday(&start, NULL);
		usleep(2000);
		gettimeofday(&end, NULL);
		
		 seconds  = end.tv_sec  - start.tv_sec;
		useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds) * 1000 + useconds/1000.0);

    printf("Elapsed time: %ld milliseconds\n", mtime);
		
	}

	printf("Quit\r\n");

    return 0;
}