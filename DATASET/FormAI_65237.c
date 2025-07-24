//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void random_generator(unsigned char *s, int len)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < len; i++) {
        s[i] = rand() % 256;
    }
}

void print_string(unsigned char *s, int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("%02x", s[i]);
    }
    printf("\n");
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int prime_check(int num)
{
    if (num == 2 || num == 3)
        return 1;
    if (num == 1 || num % 2 == 0)
        return 0;

    int i;
    for (i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int extended_euclid(int a, int b, int *x, int *y)
{
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_euclid(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main()
{
    // Generate public and private keys
    unsigned char p[8];
    unsigned char q[8];
    unsigned char n[16];
    unsigned char phi[16];
    unsigned char e[8];
    unsigned char d[16];

    random_generator(p, 8);
    random_generator(q, 8);

    while (!prime_check(p[0]) || !prime_check(q[0]) || memcmp(p, q, 8) == 0) {
        random_generator(p, 8);
        random_generator(q, 8);
    }

    memset(n, 0, 16);
    int i;
    for (i = 0; i < 8; i++) {
        n[i] = p[i];
        n[8 + i] = q[i];
    }

    memset(phi, 0, 16);
    phi[7] = 0x01;

    unsigned char p_minus[8];
    memset(p_minus, 0, 8);
    p_minus[7] = 0x01;

    unsigned char q_minus[8];
    memset(q_minus, 0, 8);
    q_minus[7] = 0x01;

    memset(e, 0, 8);
    e[7] = 0x01;
    int x, y;
    while (gcd(e[7], phi[7]) != 1) {
        while (1) {
            random_generator(e, 8);
            if (e[7] % 2 == 1 && prime_check(e[0])) {
                break;
            }
        }
        extended_euclid(e[7], phi[7], &x, &y);
    }

    memset(d, 0, 16);
    int d_int;
    i = 1;
    while (1) {
        d_int = (i * phi[7] + 1) / e[7];
        if (d_int * e[7] == i * phi[7] + 1) {
            break;
        }
        i++;
    }
    d[0] = d_int & 0xFF;
    d[1] = (d_int >> 8) & 0xFF;
    d[2] = (d_int >> 16) & 0xFF;
    d[3] = (d_int >> 24) & 0xFF;

    // Print keys
    printf("Public key: (n=%s, e=%s)\n", n, e);
    printf("Private key: (p=%s, q=%s, d=%s)\n", p, q, d);

    return 0;
}