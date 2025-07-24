//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include<stdio.h>
#include<string.h>

int main(){
    int rating;
    char movie_title[50];
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter the name of the movie you wish to rate: ");
    scanf("%[^\n]s", movie_title);
    printf("\n");

    printf("Please rate the movie on a scale of 1 to 10: ");
    scanf("%d", &rating);
    printf("\n");

    switch (rating)
    {
    case 1:
        printf("Yuck, that movie was worse than a baloney sandwich left in the sun for hours.\n");
        break;
    
    case 2:
        printf("That movie was about as enjoyable as a root canal. Yikes!\n");
        break;

    case 3:
        printf("Eh, that movie was like a stale bag of chips. Not great, but not terrible.\n");
        break;

    case 4:
        printf("That movie was like plain oatmeal - bland and unexciting.\n");
        break;

    case 5:
        printf("Meh, that movie was like a soggy slice of pizza. Not great, but not terrible either.\n");
        break;

    case 6:
        printf("Well, well, that movie was like a nice cheeseburger - satisfying but not exactly gourmet.\n");
        break;

    case 7:
        printf("Now we're talking! That movie was like a great plate of bacon and eggs. I'd watch it again.\n");
        break;

    case 8:
        printf("Wow, that movie was like a perfectly cooked steak - juicy, flavorful, and satisfying.\n");
        break;

    case 9:
        printf("Holy cow, that movie was like a gourmet meal at a five-star restaurant. Simply amazing.\n");
        break;

    case 10:
        printf("Stop the presses! That movie was like a diamond-encrusted unicorn flown in on a rainbow. Pure perfection.\n");
        break;

    default:
        printf("Invalid rating. Please rate the movie on a scale of 1 to 10.\n");
        break;
    }

    printf("Thanks for using the Unique C Movie Rating System! Hope to see you again soon.\n");
    return 0;
}