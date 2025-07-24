//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>

int recursive_puzzle(int num) {
    if (num == 0) {
        return 0;
    } else if (num % 2 == 0) {
        printf("%d is even. Dividing by 2...\n", num);
        return recursive_puzzle(num / 2);
    } else if (num % 3 == 0) {
        printf("%d is divisible by 3. Subtracting 1...\n", num);
        return recursive_puzzle(num - 1);
    } else if (num % 5 == 0) {
        printf("%d is divisible by 5. Adding 5...\n", num);
        return recursive_puzzle(num + 5);
    } else {
        printf("Encountered a prime number, %d. Subtracting 1...\n", num);
        return recursive_puzzle(num - 1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    int result = recursive_puzzle(num);
    printf("Result: %d\n", result);
    return 0;
}