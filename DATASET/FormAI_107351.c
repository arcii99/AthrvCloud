//FormAI DATASET v1.0 Category: System boot optimizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to optimize boot time by randomizing the
 * order of processes to be started.
 */ 
void optimize_boot_sequence(char **processes, int num_processes) {
    // Seed random number generator
    srand(time(0));
    
    // Shuffle processes using Fisher-Yates algorithm
    for (int i = num_processes - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char *temp = processes[i];
        processes[i] = processes[j];
        processes[j] = temp;
    }
}

int main() {
    // Example list of processes to start at boot
    char *processes[] = {"NetworkManager", "sshd", "ntpd", "cups", "bluetooth", "avahi-daemon"};
    int num_processes = sizeof(processes) / sizeof(processes[0]);
    
    printf("Existing boot sequence:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\n", processes[i]);
    }
    
    // Optimize boot sequence
    optimize_boot_sequence(processes, num_processes);
    
    printf("\nOptimized boot sequence:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\n", processes[i]);
    }
    
    return 0;
}