//FormAI DATASET v1.0 Category: Math exercise ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int i;
    float x, y, z, res, avg, sd, diff_sum = 0, dev, rand_num;
    float pi = 3.14159265;

    //Initializing seed for random number generator
    srand(time(0));

    printf("This program will find the standard deviation of x, y, and z\n\n");

    //Taking user input for x, y, and z
    printf("Please enter a value for x: ");
    scanf("%f", &x);

    printf("Please enter a value for y: ");
    scanf("%f", &y);

    printf("Please enter a value for z: ");
    scanf("%f", &z);

    //Finding the mean of x, y, and z
    avg = (x + y + z) / 3;
    printf("\n\nThe mean of x, y, and z is: %.2f\n\n", avg);

    //Finding the difference between each variable and the mean
    float diff_x = x - avg, diff_y = y - avg, diff_z = z - avg;

    //Calculating the sum of the difference of squares
    diff_sum += pow(diff_x, 2);
    diff_sum += pow(diff_y, 2);
    diff_sum += pow(diff_z, 2);

    //Finding the variance of x, y, and z
    sd = sqrt(diff_sum / 3);
    printf("The standard deviation of x, y, and z is: %.2f\n\n", sd);

    //Generating a random number between 1 and 10
    rand_num = (float)(rand() % 10 + 1);
    printf("The random number generated between 1 and 10 is: %.2f\n\n", rand_num);
    
    //Finding the sine of the random number in radians
    res = sin(rand_num * (pi / 180));
    printf("The sine of %.2f radians is: %.2f\n\n", rand_num * (pi / 180), res);

    //Finding the deviation from the sine of the random number
    dev = fabs(res - sd);
    printf("The deviation from the standard deviation of x, y, and z and the sine of %.2f radians is: %.2f\n\n", rand_num * (pi / 180), dev);

    //Printing a multiplication table from 1 to 10
    printf("Multiplication table from 1 to 10:\n\n");
    for(i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", i, rand() % 10 + 1, i * (rand() % 10 + 1));
    }

    return 0;
}