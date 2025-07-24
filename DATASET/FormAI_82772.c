//FormAI DATASET v1.0 Category: Educational ; Style: artistic
#include <stdio.h>

// Function to draw a smiley face using ASCII characters
void draw_smiley() {
    printf("\n\n");
    printf("         / \\   \n");
    printf("        {   }  \n");
    printf("        !   !  \n");
    printf("        !   !  \n");
    printf("        ;@ - @; \n");
    printf("       /      \\ \n");
    printf("      (        )\n");
    printf("       \\      / \n");
    printf("        `----'  \n");
}

// Function to prompt user for their age and return it
int get_age() {
    int age;
    printf("\n\n");
    printf("Enter your age: ");
    scanf("%d", &age);
    return age;
}

// Function to convert a decimal number to binary
void decimal_to_binary() {
    int decimal_num, remainder, base = 1, binary = 0;
    printf("\n\n");
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    while (decimal_num > 0) {
        remainder = decimal_num % 2;
        binary += remainder * base;
        decimal_num /= 2;
        base *= 10;
    }
    printf("The binary equivalent is: %d\n", binary);
}

int main() {
    draw_smiley();
    int age = get_age();
    printf("Your age is: %d\n", age);
    decimal_to_binary();
    return 0;
}