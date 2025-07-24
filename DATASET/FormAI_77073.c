//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: complete
#include <stdio.h>    // for standard input/output operations
#include <stdlib.h>   // for memory allocation/freeing
#include <unistd.h>   // for sleep function

int main() {
    int val;
    FILE* file_ptr;
    char path_buf[50];
    const char* cmd = "cat /proc/meminfo | grep 'Active:' | awk '{print $2}'";

    while (1) {
        file_ptr = popen(cmd, "r");    // execute command and get file pointer
        fgets(path_buf, sizeof(path_buf), file_ptr);    // read output from file pointer into buffer
        val = atoi(path_buf) * 1024;   // convert value to bytes from kilobytes
        pclose(file_ptr);    // close the file pointer

        // print the results to console
        printf("Current memory usage: %d bytes.\n", val);

        sleep(1);    // wait 1 second before repeating loop
    }

    return 0;
}