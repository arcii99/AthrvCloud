//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int temp;
    printf("Welcome to the Medieval Temperature Monitor\n");
    printf("Enter the temperature in Celsius: ");
    scanf("%d", &temp);
    printf("The temperature is %d Celsius\n", temp);
    
    if (temp < 0) {
        printf("It's chilly outside!\n");
    } else if (temp >= 0 && temp <= 15) {
        printf("It's a bit cold, better grab a cloak!\n");
    } else if (temp > 15 && temp <= 25) {
        printf("Perfect weather for a jousting match!\n");
    } else if (temp > 25 && temp <= 35) {
        printf("It's quite warm, loosen up that armor!\n");
    } else {
        printf("It's scorching hot, time to take off that armor!\n");
    }

    sleep(2);
    printf("\nThank you for using the Medieval Temperature Monitor.\n");
    return 0;
}