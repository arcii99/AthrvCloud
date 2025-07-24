//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIGITS 10

// Function to calculate greatest common divisor
long gcd(long a, long b){
   if (b == 0)
      return a;
   return gcd(b, a % b);
}

int main(){

    // Generate two random prime numbers
    int p = 17;
    int q = 19;

    // Calculate n and phi(n)
    int n = p * q;
    int phi_n = (p-1) * (q-1);

    // Find e such that gcd(e, phi_n) = 1 and 1 < e < phi_n
    int e;
    for(e = 2; e < phi_n; e++){
        if(gcd(e, phi_n) == 1){
            break;
        }
    }

    // Find d such that d * e mod phi_n = 1
    int d;
    int k = 1;
    while(1){
        k += phi_n;
        if(k % e == 0){
            d = k / e;
            break;
        }
    }

    // Encrypt a message
    int message = 7;
    int encrypted_message = pow(message, e);
    encrypted_message %= n;

    // Decrypt the message
    int decrypted_message = pow(encrypted_message, d);
    decrypted_message %= n;

    // Print the results
    printf("p = %d\nq = %d\nn = %d\nphi(n) = %d\ne = %d\nd = %d\n", p, q, n, phi_n, e, d);
    printf("Original Message: %d\nEncrypted Message: %d\nDecrypted Message: %d\n", message, encrypted_message, decrypted_message);

    return 0;
}