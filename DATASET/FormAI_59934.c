//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller in Linux Torvalds style!\n");
    srand(time(NULL));
    char *fortunes[] = {"The path to success is through hard work and determination.",
                        "The great pleasure in life is doing what people say you cannot do.",
                        "Expect the worst but hope for the best.",
                        "Wisdom is knowing what to do next, skill is knowing how to do it, and virtue is doing it.",
                        "A peaceful mind generates power.",
                        "The best way to predict your future is to create it.",                     
                        "Tomorrow belongs to those who can hear it coming.",
                        "Be brave enough to live life creatively.",
                        "The weakness in a man is the strength for a woman.", 
                        "Opportunity is always knocking. Are you listening?", 
                        "Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle.", 
                        "If you can dream it, you can achieve it.", 
                        "Success is not final, failure is not fatal: it is the courage to continue that counts.", 
                        "Strive for progress, not perfection.", 
                        "Take risks: if you win, you will be happy; if you lose, you will be wise."};
    int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    int randIndex = rand() % numFortunes;
    printf("\nYour fortune for today is: '%s'\n", fortunes[randIndex]);
    printf("Thanks for using the Automated Fortune Teller in Linux Torvalds style! Goodbye!\n");
    return 0;
}