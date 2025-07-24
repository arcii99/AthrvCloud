//FormAI DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating_system[10][10][10] = {0}; //initialize the rating system as empty
    int movie_id, rating, user_id;
    char choice;

    do
    {
        printf("Enter movie ID (1-10): ");
        scanf("%d", &movie_id);
        printf("Enter user ID (1-10): ");
        scanf("%d", &user_id);
        printf("Enter rating (1-10): ");
        scanf("%d", &rating);

        rating_system[movie_id-1][user_id-1][0] = movie_id; //store movie ID
        rating_system[movie_id-1][user_id-1][1] = user_id; //store user ID
        rating_system[movie_id-1][user_id-1][2] = rating; //store rating

        printf("Rating saved successfully.\n");
        printf("Do you want to rate another movie? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("\nMovie Rating System\n\n");
    printf("Movie ID    User ID    Rating\n");
    printf("--------------------------------\n");

    //display the ratings for each movie and user combination
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (rating_system[i][j][0] != 0) //check if rating is not empty
            {
                printf("%d          %d          %d\n", rating_system[i][j][0], rating_system[i][j][1], rating_system[i][j][2]);
            }
        }
    }

    return 0;
}