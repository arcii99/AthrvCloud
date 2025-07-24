//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include<stdio.h>

void happyFunction(int n) {
    if(n < 1) {
        return;
    } else {
        printf("I am so happy! %d more times to go!\n", n-1);
        happyFunction(n-1);
    }
}

int main() {
    int n = 10;
    happyFunction(n);
    printf("Yay! We've completed our happyFunction!\n");
    return 0;
}