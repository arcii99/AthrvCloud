//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int total_ram, free_ram;
    char command[50];
    FILE *fp;

    while (1) {
        fp = popen("free -m | grep Mem", "r");
        while (fgets(command, sizeof(command), fp) != NULL) {
            sscanf(command, "%*s %d %d", &total_ram, &free_ram);
            printf("\nTotal RAM: %dMB\n", total_ram);
            printf("RAM Used: %dMB\n", total_ram - free_ram);
            printf("RAM Free: %dMB\n\n", free_ram);
        }
        pclose(fp);

        sleep(1);
        system("clear"); // To clear the terminal and display updated stats
    }

    return 0;
}