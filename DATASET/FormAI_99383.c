//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>

int main()
{
    // bitwise OR
    unsigned int a = 5;
    unsigned int b = 9;
    unsigned int c;
 
    c = a | b;      
    printf("%u | %u = %u\n", a, b, c);
    
    // bitwise AND
    unsigned int d = 12;
    unsigned int e = 15;
    unsigned int f;
 
    f = d & e;      
    printf("%u & %u = %u\n", d, e, f);

    // bitwise XOR
    unsigned int g = 16;
    unsigned int h = 19;
    unsigned int i;
 
    i = g ^ h;      
    printf("%u ^ %u = %u\n", g, h, i);

    // bitwise complement
    unsigned int j = 25;
    unsigned int k; 
    k = ~j;
    printf("The Ones Complement of %u is %u\n", j, k);

    // bitwise left shift
    unsigned int l = 6; 
    unsigned int m;
    unsigned int n;
 
    m = l << 1;     
    n = l << 2;     
    printf("%u << 1 = %u\n", l, m);
    printf("%u << 2 = %u\n", l, n);

    // bitwise right shift
    unsigned int o = 20;
    unsigned int p;
    unsigned int q;
 
    p = o >> 1;     
    q = o >> 2;     
    printf("%u >> 1 = %u\n", o, p);
    printf("%u >> 2 = %u\n", o, q);

    return 0;
}