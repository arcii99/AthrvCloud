//FormAI DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>

//Function for getting user input and validating it
int getUserInput()
{
    int rating;
    printf("Enter the movie rating (1-5): ");
    scanf("%d", &rating);
    while (rating < 1 || rating > 5)
    {
        printf("Invalid rating. Please enter a rating between 1 and 5: ");
        scanf("%d", &rating);
    }
    return rating;
}

//Function for printing the rating
void printRating(int rating)
{
    printf("The movie rating is: ");
    switch (rating)
    {
        case 1:
            printf("*");
            break;
        case 2:
            printf("**");
            break;
        case 3:
            printf("***");
            break;
        case 4:
            printf("****");
            break;
        case 5:
            printf("*****");
            break;
    }
    printf("\n");
}

int main()
{
    int rating = getUserInput();
    printRating(rating);
    return 0;
}