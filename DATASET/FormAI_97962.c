//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    // Check for the RAM usage of the process
    pid_t pid = getpid();
    char command[50];
    sprintf(command, "ps -p %d -o %%mem | tail -n 1", pid);

    // Loop to run indefinitely
    while(1) {
        system(command);
        printf("WHEEEE!!! Look at me go!! I'm watching RAM usage!\n");
        sleep(1);
    }
    
    // Just in case we somehow break out of the while loop...
    printf("Oops, something went wrong! Better exit...");
    return 0;
}