//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int signalStrength;
    int counter = 0;
    char response[20];
    
    srand(time(NULL));
    signalStrength = rand() % 101;
    
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    printf("Your current signal strength is: %d%%\n\n", signalStrength);
    
    while (1) {
        printf("Would you like to test the signal strength again? (yes/no)\n");
        scanf("%s", response);
        
        if (strcmp(response, "yes") == 0) {
            signalStrength = rand() % 101;
            printf("\nYour current signal strength is: %d%%\n\n", signalStrength);
            counter++;
        } else if (strcmp(response, "no") == 0) {
            printf("\nThank you for using the Wi-Fi Signal Strength Analyzer!\n");
            printf("You tested your signal strength %d times.\n", counter);
            printf("Have a great day!\n");
            break;
        } else {
            printf("\nI'm sorry, I didn't understand your response. Please try again.\n\n");
        }
    }
    
    return 0;
}