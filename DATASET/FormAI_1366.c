//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int puzzling(int number) {
    printf("Starting with number: %d\n", number);

    if(number <= 1) {
        printf("The puzzling answer is 1\n");
        return 1;
    } else if(number % 2 == 0) {
        int result = puzzling(number / 2);
        printf("The puzzling answer is: %d * 2 = %d\n", result, result * 2);
        return result * 2;
    } else {
        int result = puzzling(3 * number + 1);
        printf("The puzzling answer is: (%d * 3) + 1 = %d\n", number, result);
        return result;
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int answer = puzzling(number);

    printf("The final puzzling answer for %d is %d\n", number, answer);
    return 0;
}