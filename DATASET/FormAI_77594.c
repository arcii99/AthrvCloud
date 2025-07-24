//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("What?! A public-key algorithm implementation in C? That's crazy!\n");
  
  // Let's generate some random prime numbers
  int prime1 = 11;
  int prime2 = 13;
  printf("Generated two prime numbers: %d and %d\n", prime1, prime2);

  // Now let's calculate the modulus and Euler's totient function
  int modulus = prime1 * prime2;
  int phi = (prime1 - 1) * (prime2 - 1);
  printf("Modulus is %d and Euler's totient function is %d\n", modulus, phi);

  // Let's find an encryption key (e) that is coprime with phi and less than phi
  int e = 7;
  while (e < phi) {
    int gcd = findGCD(e, phi);
    if (gcd == 1)
      break;
    else
      e++;
  }
  printf("Encryption key (e) is %d\n", e);

  // Now let's find the decryption key (d) using the extended Euclidean algorithm
  int d = inverseModulo(e, phi);
  printf("Decryption key (d) is %d\n", d);

  // Finally, let's test the algorithm by encrypting and decrypting a message
  int message = 9;
  printf("Message to be encrypted is %d\n", message);
  int encrypted = powerModulo(message, e, modulus);
  printf("Encrypted message is %d\n", encrypted);
  int decrypted = powerModulo(encrypted, d, modulus);
  printf("Decrypted message is %d\n", decrypted);
  
  return 0;
}

int findGCD(int a, int b) {
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int inverseModulo(int a, int m) {
  int m0 = m;
  int y = 0;
  int x = 1;
  if (m == 1)
    return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0)
    x += m0;
  return x;
}

int powerModulo(int a, int b, int m) {
  int result = 1;
  a = a % m;

  while (b > 0) {
    if (b % 2 == 1)
      result = (result * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return result;
}