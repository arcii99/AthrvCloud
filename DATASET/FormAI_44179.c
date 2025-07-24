//FormAI DATASET v1.0 Category: Temperature monitor ; Style: romantic
#include <stdio.h>

int main() {
    float temp;
    printf("Enter the current temperature: ");
    scanf("%f", &temp);
    if (temp < 0) {
        printf("It's freezing outside! Bundle up!\n");
    }
    else if (temp < 10) {
        printf("It's pretty chilly out there! Don't forget your jacket!\n");
    }
    else if (temp < 20) {
        printf("It's a bit cool outside. Take a sweater with you!\n");
    }
    else if (temp < 30) {
        printf("It's a lovely and comfortable temperature. Enjoy the weather!\n");
    }
    else if (temp < 40) {
        printf("It's getting rather warm outside. Consider wearing something lighter!\n");
    }
    else {
        printf("It's HOT outside! Stay indoors and cool off!\n");
    }
    return 0;
}