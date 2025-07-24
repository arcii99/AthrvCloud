//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/statvfs.h>

void print_usage(long total_size, long used_size, long free_size) {
    printf("\n---------------------------------------\n");
    printf("Total disk space: %.2ldGB\n", total_size/(1024*1024*1024));
    printf("Used disk space: %.2ldGB\n", used_size/(1024*1024*1024));
    printf("Free disk space: %.2ldGB\n", free_size/(1024*1024*1024));
    printf("---------------------------------------\n\n");
}

int main() {
    
    struct statvfs buf;
    int status = statvfs("/", &buf);
    
    if(status != 0) {
        printf("Error getting disk space stats.\n");
        return 1;
    }

    long total_size = buf.f_blocks * buf.f_frsize;
    long free_size = buf.f_bfree * buf.f_frsize;
    long used_size = total_size - free_size;

    print_usage(total_size, used_size, free_size);

    return 0;
}