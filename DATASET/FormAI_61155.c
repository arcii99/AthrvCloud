//FormAI DATASET v1.0 Category: Funny ; Style: lively
#include<stdio.h>
#include<string.h>
int main(){

    //Greetings and introduction
    printf("Hello there, buddy! I hope you're ready for a fun ride into the world of C programming.\n");
    printf("Today, we're going to write a program that reads in your name and tells you how many letters are in it! Exciting, right?\n\n");

    //Prompting user for name
    printf("What's your name, pal?\n");

    //Defining string variable to hold user input
    char name[20];

    //Using scanf to read in user input and store in name variable
    scanf("%s", name);

    //Using strlen to get the length of the name and storing in variable length
    int length = strlen(name);

    //Printing out the result to the user
    printf("Well, well, well. %s, huh? That's %d letters long!\n\n", name, length);

    //Farewell message
    printf("Thanks for playing along, friend. Have a great day and keep on coding!\n");

    return 0;
}