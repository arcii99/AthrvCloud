//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i < num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int count = 0;
    int num = 2;
    while(true) {
        if(isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        if(count == 50) {
            break;
        }
        num++;
    }
    return 0;
}