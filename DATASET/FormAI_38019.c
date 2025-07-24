//FormAI DATASET v1.0 Category: Movie Rating System ; Style: real-life
#include <stdio.h>

int main()
{
    int rating;
    char movie[50];
    
    printf("Welcome to the C Movie Rating System!\n");
    
    printf("Please enter the name of the movie: \n");
    fgets(movie, 50, stdin);
    
    printf("Please rate the movie out of 10: \n");
    scanf("%d", &rating);
    
    if(rating < 0 || rating > 10)
    {
        printf("Invalid rating. Please rate the movie out of 10.\n");
        scanf("%d", &rating);
    }
    
    printf("Thank you for rating %s a %d/10!", movie, rating);
    
    return 0;
}