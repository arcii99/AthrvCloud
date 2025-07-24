//FormAI DATASET v1.0 Category: Temperature monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int temp = 0;

    printf("Welcome to the curious temperature monitor!🌡️\n\n");

    while(1) {

        printf("What is the temperature today? ");
        scanf("%d", &temp);

        if(temp < 0) { // Freezing temperature
            printf("\nIt's freezing outside! You might want to wear a jacket.❄️\n\n");
        }
        else if(temp >= 0 && temp <= 30) { // Moderate temperature
            printf("\nIt's a moderate temperature today. Perfect weather for a walk outside.☀️\n\n");
        } 
        else if(temp > 30 && temp <= 50) { // Hot temperature
            printf("\nIt's getting hot in here!🔥 Better grab a cold drink and stay in the shade.☀️\n\n");
        } 
        else if(temp > 50) { // Extreme temperature
            printf("\nWait, that can't be right! Please check your thermometer.☀️🔥\n\n");
        }
        else {
            printf("\nSorry, I did not understand your input. Please try again.🙁\n\n");
            continue;
        }

        printf("Checking temperature again in 5 seconds...\n");
        sleep(5);
    }

    return 0;
}