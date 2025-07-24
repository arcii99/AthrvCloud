//FormAI DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    float temp = 0;
    float sum = 0;
    int count = 0;
    bool isRunning = true;

    printf("Welcome to the Temperature Monitor\n");

    while(isRunning) {
        printf("Enter temperature in Celsius (press q to quit): ");
        
        if (scanf("%f", &temp) != 1) {
            char quitConfirm;
            scanf("%c", &quitConfirm);
            
            if (quitConfirm == 'q') {
                printf("Exiting Temperature Monitor...\n");
                break;
            } else {
                printf("Invalid input detected.\n");
                continue;
            }
        }
        
        sum += temp;
        count++;
        printf("Temperature recorded.\n");
    }

    if (count > 0) {
        float avg = sum / count;
        printf("Total temperature recorded: %d\n", count);
        printf("Average temperature: %.2fC\n", avg);
    } else {
        printf("No temperature recorded!\n");
    }
    
    return 0;
}