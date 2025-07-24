//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 500

int gcd(int a, int b) {
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

int main() {
    // Generate two prime numbers
    int p = 3, q = 7;
    srand(time(0));
    
    while (p == q || gcd(p, q) != 1) {
        p = rand() % MAX + 1;
        q = rand() % MAX + 1;
        
        int i, flag_p = 0, flag_q = 0;
        for (i = 2; i <= sqrt(p); i++)
            if (p % i == 0) {
                flag_p = 1;
                break;
            }
        for (i = 2; i <= sqrt(q); i++)
            if (q % i == 0) {
                flag_q = 1;
                break;
            }   
        if (flag_p || flag_q)
            continue;
    }
    
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e = 2;
    int coprime_count = 1;
    while (e < phi_n) {
        if (gcd(e, phi_n) == 1) {
            coprime_count++;
            if (rand() % coprime_count == 0) {
                break;
            }
        }
        e++;
    }
    
    int i, k = 2;
    while (1) {
        int d = (k * phi_n + 1) / e;
        if (d * e == k * phi_n + 1) {
            printf("p: %d, q: %d\n", p, q);
            printf("n: %d, phi_n: %d, e: %d, d: %d\n", n, phi_n, e, d);
            break;
        }
        k++;
        if (k > phi_n)
            break;
    }
    
    return 0;
}