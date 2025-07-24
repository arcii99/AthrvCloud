//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    printf("Enter two numbers: ");
    if(scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input.\n");
        exit(0);
    }
    if(b == 0) {
        printf("Cannot divide by 0.\n");
        exit(0);
    }
    c = a / b;
    printf("%d / %d = %d\n", a, b, c);
    return 0;
}