//FormAI DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>

int main() {
    int rating;
    
    // taking input for movie rating
    printf("Enter your movie rating (1-10): ");
    scanf("%d", &rating);
    
    // validating movie rating input
    if (rating < 1 || rating > 10) {
        printf("Invalid movie rating. Please enter a rating between 1 and 10.\n");
        return 0;
    }
    
    // displaying appropriate message according to movie rating
    switch (rating) {
        case 1:
            printf("Terrible movie. Avoid at all costs!\n");
            break;
        case 2:
            printf("Very bad movie. Not worth watching.\n");
            break;
        case 3:
            printf("Disappointing movie. Could have been better.\n");
            break;
        case 4:
            printf("Average movie. Nothing great but still watchable.\n");
            break;
        case 5:
            printf("Good movie. Can give it a watch.\n");
            break;
        case 6:
            printf("Very good movie. Definitely worth watching.\n");
            break;
        case 7:
            printf("Great movie. Must watch!\n");
            break;
        case 8:
            printf("Excellent movie. A must watch for everyone!\n");
            break;
        case 9:
            printf("Outstanding movie. One of the best I have ever watched!\n");
            break;
        case 10:
            printf("Perfection! Absolutely amazing movie!\n");
            break;
    }
    
    return 0;
}