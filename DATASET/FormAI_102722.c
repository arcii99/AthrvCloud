//FormAI DATASET v1.0 Category: Math exercise ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));

    int a = rand() % 10;
    int b = rand() % 10;
    int c = rand() % 10;
    int ans1, ans2, ans3;

    printf("Solve the following equation to uncover the secret code:\n\n");
    printf("%d x + %d y + %d z = 0\n\n", a, b, c);

    printf("Enter the value of x: ");
    scanf("%d", &ans1);

    printf("Enter the value of y: ");
    scanf("%d", &ans2);

    printf("Enter the value of z: ");
    scanf("%d", &ans3);

    int result = a * ans1 + b * ans2 + c * ans3;

    if (result == 0) {
        printf("\n\nCongratulations! You've found the secret code. Here it is:\n");
        char code[16] = "58RdJ9N2sGc4LhQp";
        printf("%s", code);
    } else {
        printf("\n\nSorry, that's not quite right. Try again.");
    }

    return 0;
}