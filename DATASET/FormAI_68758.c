//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Welcome to the RAM usage monitor!\n");
    printf("Sit back, relax, and let's see what's going on in your memory...\n");

    while(1) {
        FILE *fp;
        char path[1035];

        fp = popen("free", "r");
        if (fp == NULL) {
            printf("Failed to run command\n");
            exit(1);
        }

        int total, used, free;
        int count = 0;

        while (fgets(path, sizeof(path)-1, fp) != NULL) {
            count++;
            if (count == 2) {
                sscanf(path, "%*s %d %d %d", &total, &used, &free);
            }
        }

        pclose(fp);

        float used_percentage = ((float)used/total)*100;
        printf("Current RAM usage: %.2f%%\n", used_percentage);

        sleep(1);
    }

    return 0;
}