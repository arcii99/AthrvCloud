//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/sysinfo.h>

int main(void) {
    struct sysinfo info;
    sysinfo(&info);
    printf("This system has %lu bytes of RAM.\n", info.totalram);
    printf("Free RAM %lu bytes\n", info.freeram);

    float used_percentage = 100 - (100 * (float) info.freeram / (float) info.totalram);
    printf("RAM used: %.1f%%\n", used_percentage);

    return 0;
}