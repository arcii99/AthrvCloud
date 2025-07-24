//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void print_bar(float usage) {
    int bar_width = 30;
    int filled_width = bar_width * usage;
    printf("[");
    for (int i = 0; i < filled_width; i++) {
        printf("#");
    }
    for (int i = filled_width; i < bar_width; i++) {
        printf("-");
    }
    printf("] %.2f%%\n", usage * 100);
}

int main() {
    struct sysinfo info;
    while (1) {
        if (sysinfo(&info) != 0) {
            printf("Error: Failed to load sysinfo!");
            return -1;
        }
        float used_ram = (float)(info.totalram - info.freeram) / (float)info.totalram;
        printf("RAM usage: ");
        print_bar(used_ram);
        sleep(1);
    }
    return 0;
}