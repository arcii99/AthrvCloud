//FormAI DATASET v1.0 Category: Movie Rating System ; Style: innovative
#include<stdio.h>

int main() {
    int rating = 0;

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please enter a rating between 1 and 10:\n");

    scanf("%d", &rating); // user inputs movie rating

    if (rating > 10 || rating < 1) {
        printf("Invalid input. Please enter a rating between 1 and 10:");
        scanf("%d", &rating);
    }

    switch(rating) {
        case 1:
            printf("This movie is terrible. Do not watch it.\n");
            break;
        case 2:
            printf("This movie is pretty bad. Watch it only if you're really bored.\n");
            break;
        case 3:
            printf("This movie is below average. You might find some entertainment value.\n");
            break;
        case 4:
            printf("This movie is average, with nothing special in it. If you like this genre, give it a shot.\n");
            break;  
        case 5:
            printf("This movie is slightly above average. There might be a few good moments in it.\n");
            break; 
        case 6:
            printf("This movie is good, with some enjoyable moments in it. It's worth a watch!\n");
            break;
        case 7:
            printf("This movie is really good, and worth your time. You won't be disappointed.\n");
            break;
        case 8:
            printf("This movie is amazing, and one of the best in its genre. Definitely watch it!\n");
            break;
        case 9:
            printf("This movie is outstanding. It's a must-watch for anyone who loves movies.\n");
            break;
        case 10:
            printf("This movie is a masterpiece. It's a classic that will be remembered for years to come.\n");
            break;
    }

    return 0; // end of program
}