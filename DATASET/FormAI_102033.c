//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {

    int current_temp, limit_temp;

    printf("Welcome to the temperature monitor program!\n");
    printf("Enter the current temperature: ");
    scanf("%d", &current_temp);
    printf("Enter the temperature limit: ");
    scanf("%d", &limit_temp);

    if(current_temp > limit_temp) {
        printf("Warning! Temperature has exceeded the limit.\n");
        printf("Current temperature: %d\n", current_temp);
    }
    else {
        printf("The current temperature is within the limit.\n");
        printf("Current temperature: %d\n", current_temp);
    }

    return 0;
}