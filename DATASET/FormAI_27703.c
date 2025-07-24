//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>

int main(){

    //declaring variables
    int i, j, n, flag; 

    printf("Hey there, I am your friendly Prime Number Generator! \n");
    printf("Give me an integer and I'll generate all prime numbers from 2 up to that number: \n");

    //taking user input
    scanf("%d", &n);

    printf("\nGenerating.. Please Wait... \n\n");

    //iterating through all numbers from 2 to n
    for (i = 2; i <= n; i++) {

        //assuming number is prime
        flag = 1;

        //checking for factors
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        //printing prime numbers
        if (flag == 1) {
            printf("%d is a Prime Number! \n", i);
        }
    }

    printf("\nThanks for using me! Hope you enjoyed my prime numbers! \n");
    
    return 0;
}