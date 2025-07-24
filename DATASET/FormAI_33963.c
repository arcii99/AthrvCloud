//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include<stdio.h>

int main() {

    int rating;

    printf("Enter movie rating (1 - 5): ");
    scanf("%d", &rating);

    switch(rating) {

        case 1:
            printf("Catastrophic!");
            break;

        case 2:
            printf("Didn't Expect Much!");
            break;

        case 3:
            printf("Average!");
            break;

        case 4:
            printf("Good, Worth Watching!");
            break;

        case 5:
            printf("Stunning!");
            break;

        default:
            printf("Invalid Input, Try Again.");
    }

    return 0;
}