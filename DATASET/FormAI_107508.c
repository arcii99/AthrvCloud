//FormAI DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rating;
    printf("Welcome to the Unique C Movie Rating System!\n"); // Displaying welcome message
    printf("Please rate the movie on a scale of 1 to 10: "); 
    scanf("%d", &rating); // Reading user input
    
    if (rating < 1) { // Handling invalid input less than 1
        printf("Oh no! You entered a rating below 1. That's not possible!!!\n");
        exit(0);
    }
    else if (rating > 10) { // Handling invalid input greater than 10
        printf("What!!! You're rating the movie more than 10?! Are you sure?\n");
        printf("Please re-enter your rating between 1 and 10: ");
        scanf("%d", &rating);
    }

    switch (rating) { // Checking the rating and providing suitable comments
        case 1:
            printf("Seriously! You're giving it a 1?? You must be kidding!\n");
            break;
        case 2:
            printf("I agree, the movie was pretty bad!\n");
            break;
        case 3:
            printf("Yeah, it was not a good movie at all!\n");
            break;
        case 4:
            printf("It was an average movie at best\n");
            break;
        case 5:
            printf("It was an okay movie, not good or bad!\n");
            break;
        case 6:
            printf("It was a good movie but not great!\n");
            break;
        case 7:
            printf("It was a great movie, I would recommend watching it!\n");
            break;
        case 8:
            printf("Amazing! It was a fantastic movie that I loved!\n");
            break;
        case 9:
            printf("OMG! It was an incredible movie, definitely worth watching again!\n");
            break;
        case 10:
            printf("WOW! This movie was a masterpiece, one of the best I have ever seen!\n");
            break;
    }
    printf("Thank you for using the Unique C Movie Rating System! Have a great day!\n");
    return 0;
}