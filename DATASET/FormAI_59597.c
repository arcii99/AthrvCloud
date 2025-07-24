//FormAI DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    float temperature;
    srand(time(NULL));
    int count = 0;

    printf("Welcome to Temperature Monitor!\n");
    printf("Press Ctrl^C to exit\n");

    while(1){
        temperature = (rand() % (100 - 0 + 1)) + 0; // Generate random temperature between 0 and 100

        if(temperature <= 0.0){
            printf("Error reading temperature. Please check sensor!");
            continue;
        }

        printf("Temperature: %.2f C\n", temperature);
        count++;

        if(count % 5 == 0){ // Once every 5 readings, alert the user
            printf("***ALERT: Temperature may be unstable. Please take necessary action!***\n");
        }

        if(count % 10 == 0){ // Once every 10 readings, ask the user to confirm action taken
            char action;
            printf("Have you taken necessary action (Y/N)?\n");
            scanf(" %c", &action);

            if(action == 'Y' || action == 'y'){
                printf("Thank you! Temperature monitor will continue.\n");
            }
            else if(action == 'N' || action == 'n'){
                printf("Exiting temperature monitor.\n");
                break;
            }
            else{
                printf("Invalid input. Exiting temperature monitor.\n");
                break;
            }
        }
    }

    return 0;
}