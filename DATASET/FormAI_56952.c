//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int temperature[7][24]; // array to store temperature for each hour over 7 days
    
    // generate random temperature values for each hour over 7 days
    srand(time(NULL));
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 24; j++) {
            temperature[i][j] = rand() % (40 - (-10) + 1) + (-10);
        }
    }
    
    printf("\n*** Weather Simulation for 7 Days in Celsius ***\n");
    printf("------------------------\n");
    
    // display temperature values for each hour over 7 days
    for (int i = 0; i < 7; i++) {
        switch(i) {
            case 0:
                printf("Monday:\n");
                break;
            case 1:
                printf("Tuesday:\n");
                break;
            case 2:
                printf("Wednesday:\n");
                break;
            case 3:
                printf("Thursday:\n");
                break;
            case 4:
                printf("Friday:\n");
                break;
            case 5:
                printf("Saturday:\n");
                break;
            case 6:
                printf("Sunday:\n");
                break;
            default:
                printf("Invalid day.\n");
                break;
        }
        printf("------------------------\n");
        for (int j = 0; j < 24; j++) {
            printf("%02d:00 - %02d:00 : %d°C\n", j, j+1, temperature[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}