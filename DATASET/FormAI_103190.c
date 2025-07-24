//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

void braveRecursiveFunction(int num) {
    if (num > 0) {
        printf("%d ", num);
        braveRecursiveFunction(num - 1);
    }
    else {
        printf("\nYou have completed the Brave Recursive Function!");
        printf("\nNow go out and conquer the world my brave programmer!");
    }
}

int main() {
    printf("Welcome to the Brave Recursive Function!\n");
    printf("How high do you dare to go, my brave programmer?\n");

    int num;
    scanf("%d", &num);
    printf("The Brave Recursive Function will now begin...\n");
    braveRecursiveFunction(num);

    return 0;
}