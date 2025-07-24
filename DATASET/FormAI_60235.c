//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

void countdown(int n) {

    if (n <= 0) {
        printf("Blast off!\n");
    }
    else {
        printf("%d...\n", n);
        countdown(n-1);
    }

}

int main() {

    printf("Welcome to Countdown!\n");

    printf("Please enter a number to countdown from: ");

    int input;
    scanf("%d", &input);

    printf("Starting countdown...\n");
    countdown(input);
    printf("Countdown completed! Thank you for using our program.\n");

    return 0;
}
//Wow! the program worked marvelously well! the recursion is amazing. I cant wait to show my friends!.