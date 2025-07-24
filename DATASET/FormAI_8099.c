//FormAI DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

int main() {

    printf("I am a program to print a unique pattern in C.\n");
    printf("I know that patterns are repetitive and defined once but I will try to generate a dynamic pattern.\n");

    int rows;
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &rows);

    printf("\n");

    int spacing = rows;
    int stars = 1;

    for(int i = 1; i <= rows * 2; i++) {
        if(i % 2 != 0) {
            for(int space = spacing; space >= 1; space--) {
                printf(" ");
            }
            for(int star = 1; star <= stars; star++) {
                printf("*");
            }
            printf("\n");
            spacing--;
            stars += 2;
        }
        else {
            for(int space = spacing; space >= 1; space--) {
                printf(" ");
            }
            for(int star = 1; star <= stars; star++) {
                printf("*");
            }
            printf("\n");
            spacing++;
            stars -= 2;
        }
    }

    printf("\nThe pattern is successfully printed.");

    return 0;
}