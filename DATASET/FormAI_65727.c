//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char mount_point[20] = "/dev/hda1"; // default mount point
    int size = 1024*1024*1024; // maximum size in bytes of C drive
    int used = 600*1024*1024; // used space in bytes of C drive

    printf("Analyzing C drive disk space...\n");

    printf("Mount point: %s\n", mount_point);
    printf("Total size: %d GB\n", size / (1024*1024*1024));
    printf("Used space: %d GB\n", used / (1024*1024*1024));
    printf("Free space: %d GB\n", (size - used) / (1024*1024*1024));

    printf("Generating visual display...\n\n");

    int percent_used = used * 100 / size;
    int percent_free = 100 - percent_used;
    int bar_width = 50;
    int used_bar = percent_used * bar_width / 100;
    int free_bar = bar_width - used_bar;

    printf("[");
    for (int i = 0; i < used_bar; i++) {
        printf("*");
    }
    for (int i = 0; i < free_bar; i++) {
        printf("_");
    }
    printf("] %d%% used\n", percent_used);

    printf("\nDisplaying biggest files...\n\n");

    system("sudo ls -Slh / | awk 'FNR <= 10 {print $5, $9}'");

    printf("\nAnalyzing complete. Program exiting...\n");

    return 0;
}