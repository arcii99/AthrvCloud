//FormAI DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <math.h>

int main() {

    int numbers[5] = {3, 4, 5, 6, 7}; // an array of 5 integers

    float result = 0; // the result of the calculations

    for(int i = 0; i < 5; i++) {

        float temp = sqrt(numbers[i]); // calculate the square root of each number
        temp = pow(temp, 2); // square the result

        if((int)temp == numbers[i]) { // check if the result is equal to the original number
            
            result += log(numbers[i]); // if it is, add the logarithm of the number to the result
        }
    }

    // print out the result
    printf("The sum of the logarithms of the perfect squares in the array is: %.2f", result);

    return 0;
}