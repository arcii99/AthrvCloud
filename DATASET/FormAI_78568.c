//FormAI DATASET v1.0 Category: Pattern printing ; Style: Claude Shannon
#include <stdio.h>

int main() {
    int size;
    printf("Enter size of the pattern: ");
    scanf("%d", &size);
    int num_spaces = size - 1;
    int num_stars = 1;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= num_spaces; j++) {
            printf(" ");
        }
        for (int j = 1; j <= num_stars; j++) {
            printf("*");
        }
        printf("\n");
        num_spaces--;
        num_stars += 2;
    }
    num_spaces = 1;
    num_stars = size * 2 - 1;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= num_spaces; j++) {
            printf(" ");
        }
        for (int j = 1; j <= num_stars; j++) {
            printf("*");
        }
        printf("\n");
        num_spaces++;
        num_stars -= 2;
    }
    return 0;
}