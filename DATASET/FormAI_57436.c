//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <unistd.h>
#include <stdio.h>

#define MB_TO_BYTES 1024 * 1024

int main(void) {
    while (1) {
        // Get the current RAM usage
        long long current_ram = (long long) (sysconf(_SC_PAGE_SIZE) * sysconf(_SC_PHYS_PAGES));
        // Convert to MB
        int current_ram_mb = (int) (current_ram / MB_TO_BYTES);

        // Print the current RAM usage
        printf("Current RAM usage: %d MB\n", current_ram_mb);

        // Wait a second before checking again
        sleep(1);
    }

    return 0;
}