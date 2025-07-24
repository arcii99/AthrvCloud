//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    FILE* f;
    char buffer[1024], command[128];
    int used, total = 0;

    while (1) {
        sprintf(command, "ps aux | grep %d | awk '{print $3}'", getpid());
        f = popen(command, "r");

        if (f == NULL) {
            printf("Error: Failed to open pipe.\n");
            exit(1);
        }

        fgets(buffer, sizeof(buffer), f);
        used = atoi(buffer);
        total += used;

        printf("Current CPU usage: %d%%\n", used);
        printf("Total CPU usage: %d%%\n\n", total);

        pclose(f);
        sleep(1);
    }

    return 0;
}