//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    int currentTemp = 0;
    int desiredTemp = 0;
    printf("Good sir, what doth thee desire as thy temperature preference? ");
    scanf("%d", &desiredTemp);
    printf("Thy desired temperature has been set to %d degrees Celsius. \n", desiredTemp);
    while (1) {
        printf("\nPray tell, what is thy current temperature reading in Celsius? ");
        scanf("%d", &currentTemp);
        if (currentTemp == desiredTemp) {
            printf("Ah! The temperature hath reached thy desired preference. \n");
            break;
        }
        else if (currentTemp < desiredTemp) {
            printf("My lord, it is too cold. Please turn up the heat! \n");
        }
        else {
            printf("Alas! It is far too hot in here. Please turn down the heat! \n");
        }
    }
    return 0;
}