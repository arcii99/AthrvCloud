//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

void recursive_func(int num) {
    if(num == 0) {
        printf("Thank you for trying out my program!\n");
        return;
    }
    printf("I am grateful for %d!\n", num);
    recursive_func(num-1);
}

int main() {
    printf("Welcome to my program!\n");
    printf("Please enter a positive integer: ");
    int num;
    scanf("%d", &num);
    printf("Starting recursive function...\n\n");
    recursive_func(num);
    return 0;
}