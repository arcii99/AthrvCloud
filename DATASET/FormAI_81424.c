//FormAI DATASET v1.0 Category: Weather simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {
    int days, i, temp;
    srand(time(0)); //Seed for random number generation based on time
    printf("Enter the number of days you want to simulate the weather for: ");
    scanf("%d", &days);
    int temps[days]; //Array to hold temperature values for each day
    printf("Here is the weather for the next %d days:\n", days);
    printf("---------------------------------------\n");
    for(i=0; i<days; i++) {
        temp = rand() % 51 - 10; //Generate random temperature values between -10 and 40 degrees Celsius
        temps[i] = temp; //Store temperature value in array
        printf("Day %d: %d degrees Celsius\n", i+1, temps[i]);
    }
    printf("---------------------------------------\n");
    int min_temp = temps[0], max_temp = temps[0], sum_temp = 0;
    float avg_temp;
    for(i=0; i<days; i++) {
        if(temps[i] < min_temp) {
            min_temp = temps[i]; //Find minimum temperature value in array
        }
        if(temps[i] > max_temp) {
            max_temp = temps[i]; //Find maximum temperature value in array
        }
        sum_temp += temps[i]; //Calculate sum of temperature values in array
    }
    avg_temp = (float) sum_temp / days; //Calculate average temperature value
    printf("The minimum temperature over the next %d days is %d degrees Celsius.\n", days, min_temp);
    printf("The maximum temperature over the next %d days is %d degrees Celsius.\n", days, max_temp);
    printf("The average temperature over the next %d days is %.2f degrees Celsius.\n", days, avg_temp);
}