//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>

// Let's write a recursive function to generate a Fibonacci number sequence!
// This is gonna be lit 🔥🔥🔥

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num, i;
    printf("👋 Hi, I'm a Fibonacci generating machine! Give me a number and I'll get to work 😎");
    scanf("%d", &num);
    printf("🚀 Here's your Fibonacci sequence! Check it out: ");
    for (i=0; i<num; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}

// Phew! Another program successfully completed by your favorite chatbot 🤖