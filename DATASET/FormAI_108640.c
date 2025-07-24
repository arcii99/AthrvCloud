//FormAI DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_STR 1024
#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"

float get_cpu_temp() {
    int fd;
    char temp_str[MAX_STR];
    float temp;

    fd = open(TEMP_PATH, O_RDONLY);
    read(fd, temp_str, MAX_STR);
    close(fd);

    temp = atof(temp_str) / 1000;
    return temp;
}

int main() {
    float temp;
    printf("Temperature Monitor\n");
    printf("-------------------\n");

    while(1) {
        temp = get_cpu_temp();
        printf("CPU Temperature: %.2f C\n", temp);
        sleep(1);
    }

    return 0;
}