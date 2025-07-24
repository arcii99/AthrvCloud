//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: lively
#include <stdio.h>

int main()
{
    int number, i, flag; // initialization of variables
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (number > 1)
    {
        printf("The prime numbers up to %d are:\n", number);
        printf("2 "); // 2 is the first prime number
    }
    else if (number < 1)
    {
        printf("Invalid input! Please enter a positive integer.\n");
        return 0;
    }
    else
    {
        printf("There are no prime numbers up to %d.\n", number);
        return 0;
    }

    for (i = 3; i <= number; i+=2) // start from 3 and increment by 2 to skip even numbers
    {
        flag = 1; // flag to indicate if a number is prime or not

        for (int j = 3; j <= i / 2; j+=2) // start from 3 and increment by 2 to skip even divisors
        {
            if (i % j == 0) // if i is divisible by j, then it is not prime
            {
                flag = 0; // set flag to 0
                break; // exit inner loop
            }
        }

        if (flag == 1) // if flag is still 1 after inner loop, then i is prime
            printf("%d ", i); // print i as a prime number
    }

    printf("\n"); // print new line
    return 0; // end of program
}