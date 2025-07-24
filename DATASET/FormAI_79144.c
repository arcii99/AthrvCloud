//FormAI DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include<stdio.h>

int main()
{
    int a=10, b=20, c=30;
    float x=2.5, y=3.5, z=4.5;
    char p='A', q='B', r='C';
    long int i=1000000, j=2000000, k=3000000;
    double m=3.14159, n=4.56789, o=9.87654;

    printf("a+b+c=%d\n", a+b+c);
    printf("x+y+z=%f\n", x+y+z);
    printf("p+q+r=%d\n", p+q+r);
    printf("i+j+k=%ld\n", i+j+k);
    printf("m+n+o=%.5lf\n", m+n+o);

    printf("\na-b-c=%d\n", a-b-c);
    printf("x-y-z=%f\n", x-y-z);
    printf("p-q-r=%d\n", p-q-r);
    printf("i-j-k=%ld\n", i-j-k);
    printf("m-n-o=%.5lf\n", m-n-o);

    printf("\na*b*c=%d\n", a*b*c);
    printf("x*y*z=%f\n", x*y*z);
    printf("p*q*r=%d\n", p*q*r);
    printf("i*j*k=%ld\n", i*j*k);
    printf("m*n*o=%.5lf\n", m*n*o);

    printf("\nb/a*c=%d\n", b/a*c);
    printf("y/x*z=%f\n", y/x*z);
    printf("q/p*r=%d\n", q/p*r);
    printf("j/i*k=%ld\n", j/i*k);
    printf("n/m*o=%.5lf\n", n/m*o);

    printf("\na%%b%%c=%d\n", a%b%c);
    printf("x>y && y>z=%d\n", x>y && y>z);
    printf("p<q || q<r=%d\n", p<q || q<r);
    printf("i>=j && j<=k=%d\n", i>=j && j<=k);
    printf("m!=n && n!=o=%d\n", m!=n && n!=o);

    return 0;
}