//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include<stdio.h>

int main()
{
    int rating;
    printf("Enter the movie rating out of 10: ");
    scanf("%d", &rating);
    
    if(rating >= 8)
    {
        printf("This is an excellent movie!\n");
    }
    else if(rating >= 6)
    {
        printf("This is a good movie.\n");
    }
    else if(rating >= 4)
    {
        printf("This is an average movie.\n");
    }
    else
    {
        printf("This is a below average movie.\n");
    }
    return 0;
}