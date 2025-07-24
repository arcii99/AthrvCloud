//FormAI DATASET v1.0 Category: Firewall ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Surreal C Firewall Program
int main() {
    srand(time(0));

    printf("Welcome to the Surreal Firewall!\n");

    while(1) {
        int packet = rand() % 100;
        int pass = rand() % 2;

        if(pass) {
            printf("Packet %d allowed through the surrealist firewall.\n", packet);
            continue;
        }
        else {
            printf("Packet %d blocked by the surrealism of the firewall.\n", packet);
            printf("Please enter any surreal code to try again: ");
            char code[100];
            fgets(code, 100, stdin);
            printf("\nEvaluating surreal code '%s'...\n", code);

            if(rand() % 2) {
                printf("Code evaluated successfully.\n");
                continue;
            }
            else {
                printf("Code not surreal enough. Firewall self-destruct activated.\n");
                exit(1);
            }
        }
    }

    return 0;
}