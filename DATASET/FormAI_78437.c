//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>

char* fortunes[] = {
    "You will find success in your future endeavors.", 
    "A great opportunity will come your way soon.",
    "Your hard work will pay off in the near future.",
    "Love is in the air for you!",
    "You will make a new and valuable friend in the coming weeks.",
    "Take time to enjoy the little things in life.",
    "Do not be afraid to take risks, for they often lead to great rewards.",
    "Good luck is coming your way!"
};

int main() {
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Please choose a number between 1 and 8 to receive your fortune: ");

    int choice;
    scanf("%d", &choice);

    // Check to make sure the user's choice is valid
    if(choice < 1 || choice > 8) {
        printf("\nSorry, that is an invalid choice. Please choose a number between 1 and 8.\n");
        return 1;
    }

    // Get a random fortune from the fortunes array
    char* fortune = fortunes[choice-1];

    printf("\nYour fortune for today is: %s\n", fortune);

    return 0;
}