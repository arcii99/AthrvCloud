//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i = 0, j = 0, k = 0;
    time_t t;
    srand((unsigned) time(&t));
    char message[256];

    printf("Welcome to the Surrealist Intrusion Detection System.\n");
    printf("Please enter your username:\n");

    fgets(message, sizeof(message), stdin);
    printf("Thank you, %s. Initiating intrusion analysis...\n", message);

    for(i = 0; i < 10; i++) {
        for(j = 0; j < 5; j++) {
            for(k = 0; k < 3; k++) {
                int random_num = rand() % 100 + 1;
                if(random_num < 30) {
                    printf("ERROR: Intrusion detected.\n");
                    printf("Shutting down.\n");
                    exit(0);
                } else {
                    printf("Analyzing...");
                    for(int l = 0; l < random_num; l++) {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            int random_sleep = rand() % 5 + 1;
            printf("Sleeping for %d seconds...\n", random_sleep);
            sleep(random_sleep);
        }
        printf("Analyzing complete. Moving to next stage.\n");
    }

    printf("Intrusion analysis complete. No intrusions detected.\n");
    printf("Thank you for using the Surrealist Intrusion Detection System.\n");

    return 0;
}