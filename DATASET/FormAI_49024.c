//FormAI DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>

int main() {
    int rating;
    
    printf("Welcome to the Retro Movie Rating System!\n");
    printf("Please rate the movie you just watched (out of 10):\n");
    scanf("%d", &rating);
    
    switch(rating) {
        case 10:
            printf("This movie was an absolute masterpiece!\n");
            break;
        case 9:
            printf("This movie was really amazing!\n");
            break;
        case 8:
            printf("This movie was really good!\n");
            break;
        case 7:
            printf("This movie was good, but could have been better.\n");
            break;
        case 6:
            printf("This movie was average.\n");
            break;
        case 5:
            printf("This movie was below average.\n");
            break;
        case 4:
            printf("This movie was not very good.\n");
            break;
        case 3:
            printf("This movie was bad!\n");
            break;
        case 2:
            printf("This movie was really bad!\n");
            break;
        case 1:
            printf("This movie was a complete disaster!\n");
            break;
        default:
            printf("Please enter a rating between 1 and 10.\n");
            break;
    }
    
    return 0;
}