//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numOfFortunes = 10; //number of fortunes to be displayed
    char* fortunes[numOfFortunes]; //declare an array of pointers for the fortunes
    int randomIndex; //random index to select a fortune

    //initialize the array of pointers with fortunes
    fortunes[0] = "You will meet someone special today.";
    fortunes[1] = "Your hard work will pay off soon.";
    fortunes[2] = "A big change is coming in your life.";
    fortunes[3] = "Keep an open mind and good things will come.";
    fortunes[4] = "Beware of people who try to deceive you.";
    fortunes[5] = "Your creative talents will soon be recognized.";
    fortunes[6] = "Great things are in store for you.";
    fortunes[7] = "Today will be a lucky day for you.";
    fortunes[8] = "Be patient and your dreams will come true.";
    fortunes[9] = "You will find inner peace and happiness.";

    //seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n\n");

    //display the fortunes
    for(int i=0; i<numOfFortunes; i++)
    {
        //generate a random index
        randomIndex = rand() % numOfFortunes;
        printf("%d. %s\n", i+1, fortunes[randomIndex]);
    }

    printf("\nThank you for using the Fortune Teller!\n");

    return 0;
}