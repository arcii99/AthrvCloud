//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

int main(){
    int prime_limit;

    printf("Welcome to the prime number generator! Please enter a number up to which to generate prime numbers: ");
    scanf("%d", &prime_limit);

    if(prime_limit < 2){ // prime numbers start from 2, so if user input is less than 2 then exit
        printf("No prime numbers to generate!");
        return 0; 
    }

    int *prime_check = (int*) calloc(prime_limit+1, sizeof(int)); // allocate array and set all elements to 0 to start
    int current_num = 2; // start with the first prime number

    while(current_num <= sqrt(prime_limit)){ // loop through all numbers up to the square root of the user-defined limit
        if(prime_check[current_num] != 1){ // skip to the next iteration if the current number is already marked as non-prime
            int multiple = 2 * current_num; // set the multiple to be twice the current number
            while(multiple <= prime_limit){
                prime_check[multiple] = 1; // mark all multiples of the current number as non-prime
                multiple += current_num; // add the current number to get the next multiple
            }
        }
        current_num++; // move to the next number to check
    }

    printf("\nPrime numbers up to %d:\n", prime_limit);

    // loop through all array elements and output the prime numbers
    for(int i=2; i<=prime_limit; i++){
        if(prime_check[i] != 1){
            printf("%d ", i);
        }
    }
    free(prime_check); // free the allocated memory

    return 0; 
}