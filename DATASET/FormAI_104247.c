//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int prime(int n) { // function to check if a given number is prime
  int i;
  if (n==0 || n==1) {
    return 0;
  }
  for(i=2;i<=sqrt(n);i++){
    if(n%i==0)
      return 0;
  }
  return 1;
}

int gcd(int a, int b) { // function to find the greatest common denominator of two numbers
  while(b!=0){
    int temp = b;
    b = a%b;
    a = temp;
  }
  return a;
}

int generate_key(int p, int q) { // function to generate the public and private keys
  int n = p*q; // calculate n
  int phi = (p-1)*(q-1); // calculate phi of n
  int e,d;
  do { // find e
    e = rand() % phi + 2;
  } while(gcd(e,phi)!=1);
  int k = 1; // find d
  do {
    d = (1 + k*phi)/e;
    k++;
  } while(d<=0 || d==e || d>phi);
  printf("Public Key: (%d,%d)\nPrivate Key: (%d,%d)\n", n, e, n, d); // return the keys
  return (n,e,d);
}

int encrypt(int message, int e, int n) { // function to perform encryption
  int i;
  int result = message;
  for(i=1;i<e;i++) {
      result = (result*message) % n; // use modular arithmetic
  }
  return result;
}

int decrypt(int message, int d, int n) { // function to perform decryption
  int i;
  int result = message;
  for(i=1;i<d;i++) {
      result = (result*message) % n; // use modular arithmetic
  }
  return result;
}

int main() { // test the functions
  int p,q;
  srand(time(NULL)); // initialize random seed
  do { // choose two random prime numbers
    p = rand() % 100 + 1;
  } while(!prime(p));
  do {
    q = rand() % 100 + 1;
  } while(!prime(q));
  int n,e,d,key;
  key = generate_key(p,q); // generate the keys
  int message = 1234; // example message to encrypt
  int encrypted = encrypt(message, e, n); // encrypt the message
  int decrypted = decrypt(encrypted, d, n); // decrypt the message
  printf("Original Message: %d\nEncrypted Message: %d\nDecrypted Message: %d\n",message,encrypted,decrypted); // print the results
  return 0;
}