//FormAI DATASET v1.0 Category: Game ; Style: random
#include <stdio.h>

/* Function to reverse a string */
void reverseString(char* str, int length) {
    int i;
    char temp;
    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

/* Main function */
int main() {
    char name[20];
    int num, i, j, k;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nEnter a number: ");
    scanf("%d", &num);
    printf("\n");

    // Print name in reverse
    printf("Your name in reverse is: ");
    int length = strlen(name);
    reverseString(name, length);
    printf("%s\n", name);

    // Print the number in a triangle
    for (i = 1; i <= num; i++) {
        for (j = 1; j <= num - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}