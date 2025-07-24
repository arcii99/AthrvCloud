//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_T 50 // Maximum Amount of Time
#define MAX_B 100 // Maximum Number of Bags

int main() {

    srand(time(NULL)); // Initialize Random Number Generator

    int num_bags= rand() % MAX_B + 1; // Random Number of Bags
    int conveyor[20]; // Conveyor Array with Length 20
    int num_bags_on_conveyor= 0; // Number of Bags on Conveyor Belt

    printf("Number of Bags: %d\n\n", num_bags);

    int t;
    for(t= 0; t<= MAX_T; t++) { // Loop for MAX_T Seconds

        printf("Time: %d sec\n", t);

        if(num_bags_on_conveyor== 0) { // If No Bags are on Conveyor Belt
            conveyor[0]= rand() % 100 + 1; // Add a Random Bag to the Conveyor Belt
            num_bags_on_conveyor++; // Increase Number of Bags on Conveyor Belt
            printf("Bag #%d added to conveyor belt.\n", conveyor[0]);
        }

        else if(num_bags_on_conveyor== 20) { // If Conveyor Belt is Full
            printf("Conveyor belt is full. Waiting for bags to be removed.\n");
        }

        else { // If Conveyor Belt has Less than 20 Bags
            int add_bag= rand() % 2; // Random Number Generator to Add Bag or Not

            if(add_bag== 1) { // Add a Bag to the Conveyor Belt
                conveyor[num_bags_on_conveyor]= rand() % 100 + 1; // Add a Random Bag to the Conveyor Belt
                num_bags_on_conveyor++; // Increase Number of Bags on Conveyor Belt
                printf("Bag #%d added to conveyor belt.\n", conveyor[num_bags_on_conveyor-1]);
            }
            else { // Do Not Add a Bag to the Conveyor Belt
                printf("No bag added to conveyor belt.\n");
            }
        }

        int remove_bag= rand() % 2; // Random Number Generator to Remove Bag or Not

        if(remove_bag== 1) { // Remove a Bag from the Conveyor Belt
            printf("Bag #%d removed from conveyor belt.\n", conveyor[0]);
            int i;

            for(i=0; i<num_bags_on_conveyor-1; i++) { // Shift All Bags to the Left
                conveyor[i]= conveyor[i+1];
            }

            num_bags_on_conveyor--; // Decrease Number of Bags on Conveyor Belt
        } 

        else { // Do Not Remove a Bag from the Conveyor Belt
            printf("No bag removed from conveyor belt.\n");
        }

        printf("\n");
    }

    return 0;
}