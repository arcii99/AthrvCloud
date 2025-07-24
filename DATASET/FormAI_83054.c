//FormAI DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>

void countDown(int n) {
    if(n == 0) {
        printf("Blast off!\n");
        return;
    }
    printf("%d...\n", n);
    countDown(n - 1);
}

int main() {
    printf("Hello! Welcome to the countdown program!\n");
    printf("Enter a number greater than or equal to 0 to begin the countdown: ");
    int num;
    scanf("%d", &num);
    countDown(num);
    printf("Thank you for using the countdown program!\n");
    return 0;
}

/* 
    This program is a simple recursive countdown 
    that will take a positive integer value and
    count down to 0. Once it reaches 0, it will 
    print "Blast off!" and return control to the main 
    program. 
*/