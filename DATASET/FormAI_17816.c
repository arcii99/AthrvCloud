//FormAI DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp[7];
    int i, j;
    int min, max, sum;
    float avg;

    // generate random temperatures for the week
    srand(time(NULL));
    for(i = 0; i < 7; i++) {
        temp[i] = rand() % 40;
    }

    // print the temperatures
    printf("The temperatures for the week are:\n");
    for(i = 0; i < 7; i++) {
        printf("%d ", temp[i]);
    }

    // find the minimum temperature
    min = temp[0];
    for(i = 1; i < 7; i++) {
        if(temp[i] < min) {
            min = temp[i];
        }
    }
    printf("\nThe lowest temperature is %d\n", min);

    // find the maximum temperature
    max = temp[0];
    for(i = 1; i < 7; i++) {
        if(temp[i] > max) {
            max = temp[i];
        }
    }
    printf("The highest temperature is %d\n", max);

    // calculate the average temperature
    sum = 0;
    for(i = 0; i < 7; i++) {
        sum += temp[i];
    }
    avg = (float) sum / 7;
    printf("The average temperature is %.2f\n", avg);

    // display a puzzling message based on the average temperature
    printf("Based on these temperatures, ");

    if(avg < 20) {
        printf("it might snow soon!");
    } else if(avg >= 20 && avg < 30) {
        printf("it seems like a nice day outside.");
    } else {
        printf("it's getting really hot out there!");
    }
    
    return 0;
}