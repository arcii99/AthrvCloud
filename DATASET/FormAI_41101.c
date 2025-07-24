//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 1000000

// function to check if a number is prime
int is_prime(int num)
{
    int i;
    for(i = 2; i <= sqrt(num); i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

// function to generate a random prime number
int generate_prime_number()
{
    int prime = 0;
    while(!prime){
        int num = rand()%MAX + 1;
        if(is_prime(num)){
            prime = num;
        }
    }
    return prime;
}

// function to calculate GCD of two numbers
int gcd(int a, int b)
{
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

// function to find a primitive root for a prime number
int find_primitive_root(int prime)
{
    int phi = prime - 1;
    int phi_factors[phi], i, j, k = 0;
    for(i = 2; i <= phi; i++){
        if(gcd(i, phi) == 1){
            phi_factors[k++] = i;
        }   
    }
    for(i = 2; i <= prime; i++){
        int flag = 0;
        for(j = 0; j < k; j++){
            int power = pow(i, phi/phi_factors[j]);
            power = power % prime;
            if(power == 1){
                flag = 1;
                break;
            }
        }
        if(!flag){
            return i;
        }
    }
}

// function to calculate modular exponentiation
int modular_exponentiation(long long a, int b, int m)
{
    long long result = 1;
    while(b > 0){
        if(b%2 == 1){
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

int main()
{
    srand(time(NULL));
    int p = generate_prime_number();
    int g = find_primitive_root(p);
    int a = rand()%p;
    int A = modular_exponentiation(g, a, p);
    printf("p = %d\ng = %d\na = %d\n", p, g, a);
    printf("Public key (p, g, A): (%d, %d, %d)\n", p, g, A);
    return 0;
}