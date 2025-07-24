//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main() {
    int total_ram = 2048;
    int used_ram = 0;
    bool is_warning_given = false;

    printf("Welcome to the RAM usage monitor! Let's see how much RAM we have left.\n");
    printf("Total RAM: %d MB\n", total_ram);

    while (true) {
        int ram_usage = rand() % 200 + 1;
        used_ram += ram_usage;

        printf("Used RAM: %d MB\n", used_ram);

        if (used_ram >= total_ram) {
            printf("Oh no, we've run out of RAM! Quick, delete your browser history before the computer crashes!\n");
            break;
        } else if (used_ram >= total_ram * 0.9 && !is_warning_given) {
            printf("Warning: RAM usage is at %d%%. Please save your work before the computer explodes.\n", used_ram * 100 / total_ram);
            is_warning_given = true;
        }

        sleep(1);
    }

    printf("Phew, crisis averted. You can stop deleting your browser history now.\n");

    return 0;
}