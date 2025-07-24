//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include <stdio.h>

int main() {
    printf("Welcome to the Prime Number Generator!\n\n");

    int num, i, flag, count = 0;

    printf("Enter the maximum number up to which you want to generate prime numbers: ");
    scanf("%d", &num);

    printf("Prime numbers up to %d are: \n", num);

    //Logic for generating prime numbers
    for(i=2; i<=num; i++) {
        flag = 0;

        for(int j=2; j<=i/2; j++) {
            if(i%j == 0) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            printf("%d ", i);
            count++;
        }
    }

    printf("\n\nTotal number of prime numbers generated: %d", count);

    return 0;
}