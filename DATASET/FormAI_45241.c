//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int ram_prev = 0, ram_current;
    while (1) {
        FILE *fp = popen("free -t -m | grep Total | awk '{print $2}'", "r");
        char result[10];
        fgets(result, sizeof(result), fp);
        ram_current = atoi(result);
        pclose(fp);
        if (ram_current != ram_prev) {
            printf("RAM Usage: %d MB\n", ram_current);
            ram_prev = ram_current;
        }
        sleep(1);
    }
    return 0;
}