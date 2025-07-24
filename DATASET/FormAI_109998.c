//FormAI DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h> 

int main() 
{ 
    int rating, numRatings, totalRatings = 0, averageRating; 
    
    printf("Welcome to the C Movie Rating System\n"); 
    printf("Please enter the number of ratings for the movie: "); 
    scanf("%d", &numRatings); 

    for(int i = 0; i < numRatings; i++)
    {
        printf("Please enter a rating between 1-10 for the movie: ");
        scanf("%d", &rating);
        while(rating < 1 || rating > 10)
        {
            printf("Invalid rating. Please enter a rating between 1-10: ");
            scanf("%d", &rating);
        }
        totalRatings += rating;
    }

    averageRating = totalRatings / numRatings;
    printf("The average rating for the movie based on %d ratings is %d\n", numRatings, averageRating);

    if(averageRating > 8)
    {
        printf("This movie is a must-see!\n");
    }
    else if(averageRating > 5)
    {
        printf("This movie is worth checking out.\n");
    }
    else
    {
        printf("This movie may not be worth your time.\n");
    }

    return 0; 
}