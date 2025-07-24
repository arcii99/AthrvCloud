//FormAI DATASET v1.0 Category: Random ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, count, num;
    printf("Welcome to Brave Random Generator!\n\n");
    printf("Enter the number of values you want to generate: ");
    scanf("%d", &count);
    printf("\nRandomly generating %d values...\n\n", count);
    srand(time(0));
    for (i = 0; i < count; i++) {
        num = rand() % 1000;
        printf("%d ", num);
    }
    printf("\n\nThank you for using Brave Random Generator!\n");
    return 0;
}