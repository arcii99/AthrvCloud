//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>

int main(){

    struct rusage usage;

    for(int i=0;i<10;i++){
        void* ptr = malloc(10*1024*1024); //allocating memory
        memset(ptr,0,10*1024*1024); //clearing the allocated memory
        getrusage(RUSAGE_SELF,&usage); //storing the resource usage 
        printf("CPU usage: %ld.%06ld sec, Memory usage: %ld KB\n",usage.ru_utime.tv_sec,usage.ru_utime.tv_usec,usage.ru_maxrss);
        sleep(1); //pausing for a second
    }
    return 0;
}