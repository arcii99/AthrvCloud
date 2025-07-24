//FormAI DATASET v1.0 Category: Funny ; Style: active
#include <stdio.h>

int main() {
    int count = 0;
    printf("Welcome to the counting game!\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &count);

    while(count > 0) {
        if(count == 1) {
            printf("1 bottle of beer on the wall, 1 bottle of beer!\n");
        } else {
            printf("%d bottles of beer on the wall, %d bottles of beer!\n", count, count);
        }
        printf("Take one down, pass it around...\n");
        count--;
        if(count == 1) {
            printf("1 bottle of beer on the wall!\n\n");
        } else if(count == 0) {
            printf("No more bottles of beer on the wall!\n\n");
        } else {
            printf("%d bottles of beer on the wall!\n\n", count);
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}