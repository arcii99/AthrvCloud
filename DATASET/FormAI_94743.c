//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the GCD of two numbers
int calculateGCD(int a, int b) {
   if (b == 0) {
      return a;
   }
   return calculateGCD(b, a % b);
}

// Function to check if a number is prime or not
int isPrime(int num) {
   int i;
   if (num == 2 || num == 3) {
      return 1;
   }
   if (num == 1 || num % 2 == 0) {
      return 0;
   }
   for (i = 3; i <= sqrt(num); i+=2) {
      if (num % i == 0) {
         return 0;
      }
   }
   return 1;
}

// Function to generate random prime numbers
int generatePrime(){
   int num = rand() % 100;
   while (!isPrime(num)) {
      num = rand() % 100;
   }
   return num;
}

// Main function
int main() {
   int p, q, phi, n, e, d, message, encrypted, decrypted, gcd;

   // Generate random prime numbers p and q
   p = generatePrime();
   q = generatePrime();

   // Calculate n and phi
   n = p * q;
   phi = (p - 1) * (q - 1);

   // Find a number e such that e and phi are coprime
   do {
      e = rand() % phi;
      gcd = calculateGCD(e, phi);
   } while (gcd != 1);

   // Find d such that (d * e) % phi = 1
   int k = 1;
   while ((k * phi + 1) % e != 0) {
      k++;
   }
   d = (k * phi + 1) / e;

   // Get the message from the user
   printf("Enter a number to encrypt: ");
   scanf("%d", &message);

   // Encrypt the message
   encrypted = fmod(pow(message, e), n);
   printf("Encrypted message: %d\n", encrypted);

   // Decrypt the message
   decrypted = fmod(pow(encrypted, d), n);
   printf("Decrypted message: %d\n", decrypted);

   return 0;
}