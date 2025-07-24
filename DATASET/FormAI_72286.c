//FormAI DATASET v1.0 Category: Temperature monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp = 0; //initialize the temperature to zero
    int count = 0; //initialize the count to zero
    srand((unsigned)time(NULL)); //seed the random number generator

    while (count < 10) { //loop 10 times to get 10 temperature readings
        temp = (rand() % 30) - 10; //generate a random temperature between -10 and 20
        printf("Temperature reading %d: %d degrees Celsius\n", count+1, temp); //print the temperature reading
        count++; //increment the count
    }

    return 0; //exit the program
}