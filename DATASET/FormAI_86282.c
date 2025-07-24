//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>

int main() {
    int num;

    printf("Surprise! I am a prime number generator!\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The prime numbers from 1 to %d are:\n", num);

    for(int i = 2; i <= num; i++) {
        int flag = 0;

        for(int j = 2; j <= i/2; j++) {
            if(i % j == 0) {
                flag = 1;
                break;
            }
        }

        if(flag == 0 && i != 1) {
            printf("%d ", i);
        }
    }

    printf("\nTadaaa! Generating prime numbers is done!");
    return 0;
}