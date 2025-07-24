//FormAI DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*This program will generate 10 random numbers and display the square root of the largest number and the cube of the smallest number*/

int main()
{
    int i;
    double max, min, randNum;

    srand(time(0)); //Seed the random number generator

    //Generate 10 random numbers between -50 and 50
    for(i = 0; i < 10; i++) {
        randNum = ((double)rand() / (double)(RAND_MAX)) * 100 - 50;

        if(i == 0) { //First number will be assigned to both max and min
            max = randNum;
            min = randNum;
        }
        else {
            if(randNum > max)
                max = randNum;
            if(randNum < min)
                min = randNum;
        }
    }

    printf("The largest number is: %.2lf\n", max);
    printf("The square root of the largest number is: %.2lf\n", sqrt(max));
    printf("The smallest number is: %.2lf\n", min);
    printf("The cube of the smallest number is: %.2lf\n", pow(min, 3));
    
    return 0;
}