//FormAI DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

int main() {

    int rating;
    printf("Welcome to our unique movie rating system!\n\n");
    printf("Please rate the movie you watched on a scale of 1 to 10: ");
    scanf("%d", &rating);

    if(rating < 1){
        printf("Oops! Invalid rating. Please rate the movie between 1 to 10\n");
    }
    else if(rating >= 1 && rating <= 3){
        printf("Your movie rating is %d!\n", rating);
        printf("We are sorry to know that you didn't enjoy the movie\n");
    }
    else if(rating >= 4 && rating <= 6){
        printf("Your movie rating is %d!\n", rating);
        printf("Glad to know that you found the movie just average\n");
    }
    else if(rating >= 7 && rating <= 9){
        printf("Your movie rating is %d!\n", rating);
        printf("Wow! You really enjoyed the movie, didn't you?\n");
    }
    else{
        printf("Your movie rating is %d!\n", rating);
        printf("Congratulations! You have rated the movie among the best ones out there!\n");
    }

    return 0;
}