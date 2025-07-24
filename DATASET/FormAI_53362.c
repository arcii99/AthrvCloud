//FormAI DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rating;
  
    // Displaying the options to the user
    printf("Welcome to C Movie Rating System\n");
    printf("Enter your rating out of 10: ");
    scanf("%d",&rating);
  
    // Evaluating the rating and displaying the output
    if(rating >= 9)
    {
        printf("Wow! You gave a fantastic rating of %d out of 10. This movie is must watch\n",rating);
    }
    else if(rating >= 7)
    {
        printf("Great! You gave a good rating of %d out of 10. This movie is definitely worth watching\n",rating);
    }
    else if(rating >= 5)
    {
        printf("Okay! You gave an average rating of %d out of 10. This movie may or may not be worth watching\n",rating);
    }
    else if(rating >= 3)
    {
        printf("Hmm! You gave a below average rating of %d out of 10. This movie may not be worth watching\n",rating);
    }
    else
    {
        printf("Oh no! You gave a terrible rating of %d out of 10. This movie definitely not worth watching\n",rating);
    }
  
    return 0;
}