//FormAI DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include<stdio.h>

int main(){
    int rating;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter your rating between 1-10: ");
    scanf("%d", &rating);

    if(rating < 1 || rating > 10){
        printf("Invalid rating entered. Please enter a rating between 1-10.\n");
        return 0;
    }

    printf("You have given a rating of %d\n", rating);
    
    // Displaying emoji based on rating
    switch(rating){
        case 1:
        case 2:
        case 3:
            printf("👎🏽\n");
            break;
        case 4:
        case 5:
            printf("🤔\n");
            break;
        case 6:
        case 7:
            printf("👍🏽\n");
            break;
        case 8:
        case 9:
            printf("👏🏽\n");
            break;
        case 10:
            printf("👑\n");
            break;
    }

    // Displaying message based on rating
    if (rating >= 1 && rating <= 3) {
        printf("We are sorry that you did not enjoy the movie. Please provide us with feedback on what we can improve.\n");
    } else if (rating >= 4 && rating <= 7) {
        printf("Thank you for your rating. We hope you enjoyed the movie and look forward to seeing you again soon.\n");
    } else {
        printf("Congratulations, you loved the movie! Thank you for your support and we hope to see you again soon.\n");
    }
    return 0;
}