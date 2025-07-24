//FormAI DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include<stdio.h>

int main(){
    int rating;
    char movie[50];
    printf("What movie do you want to rate?\n");
    scanf("%s", movie);
    printf("How would you rate %s on a scale of 1-10?\n", movie);
    scanf("%d", &rating);

    if(rating >= 1 && rating <= 10){
        printf("Thank you for rating %s a %d out of 10!\n", movie, rating);
    }else{
        printf("Invalid rating. Please rate %s on a scale of 1-10\n", movie);
    }

    return 0;
}