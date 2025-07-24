//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: medieval
#include <stdio.h>
#include <unistd.h>

int main() {
    int cpu_usage = 0;
    char c;
    printf("Sir, I present to thee the CPU usage monitor.\n\n");
    printf("Press Ctrl+C to exit at any time.\n\n");
    while (1) {
        printf("Fetching CPU usage information...\n");
        FILE* file = fopen("/proc/stat", "r");
        fscanf(file, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d\n");
        fclose(file);
        printf("CPU usage: %d%%\n\n", cpu_usage);
        printf("Shall I continue, my lord? (y/n)\n");
        scanf("%c", &c);
        if (c == 'n') {
            printf("\nMay thy CPU forever be at low usage. Farewell, my lord!\n");
            break;
        }
        cpu_usage++;
        usleep(100000);
    }
    return 0;
}