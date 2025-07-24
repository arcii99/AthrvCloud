//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

// Function to check if the system is under attack
int isUnderAttack(){
    // Get the current system time
    time_t currentTime;
    time(&currentTime);

    // Check if the system time is odd or even
    if(currentTime%2 == 0){
        return 0; // If the time is even then the system is safe
    }else{
        return 1; // If the time is odd then the system is under attack
    }
}

int main(){
    int userInput;

    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please select an option from the menu below:\n");
    printf("1. Check if the system is under attack\n");
    printf("2. Exit the program\n");

    while(1){
        // Get user input
        scanf("%d",&userInput);

        // Check if the input is valid
        if(userInput<1 || userInput>2){
            printf("Invalid Input! Please select a valid option.\n");
        }else{
            if(userInput==1){
                // Call the function to check if the system is under attack
                int status = isUnderAttack();

                // Check the status and print the appropriate message
                if(status==0){
                    printf("System is safe and secure.\n");
                }else{
                    printf("System is under attack! Evacuate immediately!\n");
                }
            }else{
                printf("Exiting the program. Thank you for using the Intrusion Detection System.\n");
                break;
            }
        }
    }

    return 0;
}