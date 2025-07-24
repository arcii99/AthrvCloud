//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int isPrime(int n) {
    int i;
    for(i=2;i<=sqrt(n);i++) {
        if(n%i==0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, i, count=0;
    srand(time(0));
    
    printf("Enter the minimum number range: ");
    scanf("%d", &num);
    
    printf("\nSearching for prime numbers in the range %d - %d\n", num, num+200);
    
    for(i=num; i<num+200; i++) {
        if(isPrime(i)) {
            printf("%d is a prime number.\n", i);
            count++;
            //Random event
            int random_num = rand()%100;
            if(random_num>80) {
                printf("The Prime Number generator is malfunctioning... ERROR: 404\n");
                return 0;
            }
        }
    }
    
    if(count == 0) {
        printf("Sorry, no prime numbers found in the range %d - %d\n", num, num+200);
    }
    
    printf("Program terminated.\n");
    return 0;
}