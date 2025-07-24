//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: unmistakable
#include <stdio.h>
#include <math.h>

/*
 * Function that checks if a given number is prime or not
 */
int isPrime(int num) {
    int i, flag = 1;
    for(i = 2; i <= num / 2; ++i) {
        if(num % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

/*
 * Function that generates a unique digital watermark
 */
void generateWatermark(int num) {
    int i, j, watermark = 0;
    for(i = 2; i <= num; ++i) {
        if(isPrime(i)) {
            for(j = 0; j < i; ++j) {
                watermark += pow(2, j);
            }
        }
    }
    printf("The generated digital watermark is %X\n", watermark);
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    generateWatermark(num);
    return 0;
}