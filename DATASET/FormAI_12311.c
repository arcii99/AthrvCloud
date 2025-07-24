//FormAI DATASET v1.0 Category: Funny ; Style: grateful
#include<stdio.h>

int main(){
    printf("Thank you for choosing to run this program!\n");
    printf("This program is designed to create a list of your favorite things.\n");
    printf("Please enter the number of your favorite things: ");

    int numOfFavThings;
    scanf("%d", &numOfFavThings);

    char favThings[numOfFavThings][50];
    for(int i = 0; i < numOfFavThings; i++){
        printf("Please enter your favorite thing #%d: ", i+1);
        scanf("%s", favThings[i]);
    }

    printf("\nThank you for sharing your favorite things!\n");
    printf("Here is your list:\n");

    for(int i = 0; i < numOfFavThings; i++){
        printf("%d. %s\n", i+1, favThings[i]);
    }

    printf("I am so grateful that you took the time to create this list.\n");
    printf("I hope that it brings you as much joy as it does to me.\n");
    printf("Thank you again for running this program!\n");
    return 0;
}