//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Cryptic
#include<stdio.h>

int main() {

    int num;
    int flag = 0;

    printf("Enter the last number to find the prime numbers before it: ");
    scanf("%d", &num);

    for(int i=2; i<=num; i++) {
        for(int j=2; j<i; j++) {
            if(i % j == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("%d ", i);
        }
        flag = 0;
    }

    return 0;
}