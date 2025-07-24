//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>

int main() {
    int num, i, j, flag;
    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter any positive integer: ");
    scanf("%d",&num);

    if(num <= 1) {
        printf("Wow, interesting choice! Sadly, %d is not a prime number.\n", num);
        return 0;
    }

    printf("The prime numbers between 2 and %d are:\n", num);

    for(i=2; i<=num; i++) {
        flag = 0;
        for(j=2; j<=i/2; j++) {
            if(i%j==0) {
                flag = 1;
                break;
            }
        }
        if(flag==0) {
            printf("%d ", i);
        }
    }
    printf("\nHope this was helpful! Have a Prime-tastic day! ;)\n");
    return 0;
}