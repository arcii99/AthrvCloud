//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

/* Define an array with different fortunes */
static const char *fortunes[] = {
    "You will find success in all your endeavors.",
    "A pleasant surprise is on the way to you.",
    "The best way to predict the future is to create it.",
    "Good news is coming your way.",
    "Everything will work out in the end.",
    "Don't be afraid to take a chance on something new.",
    "You will overcome all challenges and come out stronger in the end.",
    "Great things are ahead for you!",
    "Your hard work will pay off soon.",
    "You will soon find the answer you've been searching for.",
    "Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle.",
    "You will find happiness and fulfillment in the next phase of your life."
};

/* Main function */
int main(void)
{
    int i, index;
    
    /* Display welcome message */
    printf("Welcome to the Automated Fortune Teller!\n");
    
    /* Generate a random index within the range of the fortunes array */
    index = rand() % (sizeof(fortunes) / sizeof(char*));
    
    /* Display the selected fortune */
    printf("\nYour fortune for today is: \n\n%s\n", fortunes[index]);

    return 0;
}