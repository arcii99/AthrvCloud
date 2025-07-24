//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: satisfied
#include<stdio.h> 
#include<math.h> 

// Function to calculate gcd 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 

// Function to find least common multiple 
int lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

// Function to calculate power of number using modulus 
int power(int a, int b, int m) 
{ 
    int res = 1; 
    a = a % m; 
    while (b > 0) { 
        if (b & 1) 
            res = (res * a) % m; 
        b = b >> 1; 
        a = (a * a) % m; 
    } 
    return res; 
} 

// Function to perform RSA encryption 
void RSA_Encrypt(int msg, int n, int e) 
{ 
    int cipher = power(msg, e, n); 
    printf("Encrypted Message: %d\n", cipher); 
} 

// Function to perform RSA decryption 
void RSA_Decrypt(int cipher, int n, int d) 
{ 
    int decrypt = power(cipher, d, n); 
    printf("Decrypted Message: %d\n", decrypt); 
} 

// Driver code 
int main() 
{ 
    int p = 3; 
    int q = 7; 
    int n = p * q; 
    int phi = lcm(p - 1, q - 1); 
    int e = 2; 
    while (e < phi) { 
        if (gcd(e, phi) == 1) 
            break; 
        e++; 
    } 
    int k = 2; 
    int d = (1 + (k * phi)) / e; 
    int msg = 12; 

    RSA_Encrypt(msg, n, e); 
    RSA_Decrypt(34, n, d); 

    return 0; 
}