//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

void printRecursive(int count) {
    if(count == 0) {
        printf("Blast off!!");
        return;
    }
    else if(count < 0) {
        printf("Invalid input!");
        return;
    }
    else {
        printf("Countdown: %d\n", count);
        printRecursive(count-1);
    }
}

int main() {
    int n;
    printf("Enter the starting number: ");
    scanf("%d", &n);
    printf("Let's begin the countdown:\n");
    printRecursive(n);
    return 0;
}