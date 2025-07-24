//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    float temperature;
    printf("Enter the current temperature in Celsius: ");
    scanf("%f", &temperature);

    if(temperature < -273.15) {
        printf("\nThis temperature is not possible!\n");
    } else if(temperature < 0) {
        printf("\nIt's freezing outside!\n");
    } else if(temperature > 100) {
        printf("\nIt's boiling outside!\n");
    } else {
        printf("\nThe temperature is %0.2f degrees Celsius.\n", temperature);
    }
    return 0;
}