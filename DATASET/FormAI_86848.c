//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

// Function to check if the number is prime
int isPrime(int n) {
   int i;
   if (n<=1) return 0;
   for (i=2;i<=sqrt(n);i++) {
      if (n%i==0) {
         return 0;
      }
   }
   return 1;
}

// Function to generate a prime number
int generatePrime() {
   int num;
   do {
      num=rand()%1000; //max limit has reduced due to apocalypse
   } while (!isPrime(num)); //loop until prime number is generated
   return num;
}

int main() {
   srand(time(NULL)); //seed for random function
   printf("Welcome to the Prime Number Generator program!\n");
   printf("In this post-apocalyptic world, finding prime numbers is more important than ever!\n");
   printf("We here at the generator program can help you in generating primes to rebuild the world.\n");
   printf("How many prime numbers do you want to generate? "); //user input for number of prime numbers
   int n;
   scanf("%d",&n);
   printf("\n");
   printf("Alright! Here are your %d prime numbers:\n", n);
   for (int i=1;i<=n;i++) {
      printf("%d ", generatePrime()); //generate and print the prime numbers
   }
   printf("\n");
   printf("Remember, the world is counting on you. Use these primes wisely!\n");
   return 0;
}