//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include<stdio.h>

//Function to check whether a number is prime or not
int isPrime(int num)
{
    int i;
    for(i=2;i<num;i++) //Loop through all the numbers less than num
    {
        if(num%i==0) //If num is divisible by any number other than 1 or itself, it is not a prime
            return 0; //Return false
    }
    return 1; //If no divisor found, it is a prime number
}

int main()
{
    int n,i;
    printf("Welcome to Prime Number Generator Program!\n\n");
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d",&n);
    if(n<1) //If invalid input
    {
        printf("\nYou entered an invalid number! Please enter a positive integer greater than zero.\n");
        return 0;
    }
    printf("\nGenerating %d prime numbers for you...\n",n);
    printf("2 "); //2 is the first prime number, so we print it
    int count=1; //Initialize count to 1, since we have already printed 2
    for(i=3;count<n;i+=2) //Loop through all odd numbers starting from 3
    {
        if(isPrime(i)) //If i is a prime number
        {
            printf("%d ",i); //Print it
            count++; //Increment count
        }
    }
    printf("\n\nHope you had fun generating prime numbers with me! Take care :)\n");
    return 0;
}