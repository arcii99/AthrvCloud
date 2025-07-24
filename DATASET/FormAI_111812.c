//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50
#define MIN_TEMP 0

int main() {
    srand(time(NULL)); // initialize random seed
    char answer;
    int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // generating a random temperature between 0 and 50
    printf("Current Temperature: %dC\n", temperature);
    do {
        printf("Would you like to update the temperature? (y/n): ");
        scanf(" %c", &answer);
        if(answer == 'y') {
            int new_temp;
            do {
                printf("Enter a new temperature between %dC and %dC: ", MIN_TEMP, MAX_TEMP);
                scanf("%d", &new_temp);
            } while(new_temp < MIN_TEMP || new_temp > MAX_TEMP);
            temperature = new_temp;
            printf("Temperature has been set to %dC!\n", temperature);
        } else if(answer == 'n') {
            printf("Ok, good bye!\n");
            break;
        } else {
            printf("Invalid input, please try again\n");
        }
    } while(1);

    return 0;
}