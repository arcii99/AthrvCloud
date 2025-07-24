//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* fortunes[] = {
    "A dream you dream alone is only a dream. A dream you dream together is reality.",
    "A friend asks only for your time not your money.",
    "A lifetime of happiness lies ahead of you.",
    "All the effort you are making will ultimately pay off.",
    "Curiosity kills boredom. Nothing can kill curiosity.",
    "Do not let friends impose on you, work calmly and silently.",
    "Do not let the past and useless detail choke your existence.",
    "Every adversity carries with it the seed of an equal or greater benefit.",
    "Fortune favors the brave.",
    "Good luck is the result of good planning.",
    "Happiness is an activity.",
    "He who expects no gratitude shall never be disappointed.",
    "If winter come, can spring be far behind?",
    "It takes guts to get out of the ruts.",
    "The human spirit is stronger than anything that can happen to it.",
    "The road to success is always under construction.",
    "There is no time like the present.",
    "Things in your life will improve soon.",
    "You are very talented in many ways.",
    "You can always find happiness at work on Friday.",
    "You have a deep appreciation of the arts and music.",
    "You have an unusual equipment for success, use it properly.",
    "You should be able to make money and hold on to it.",
    "Your future is as bright as your faith."
};

int main() {
    srand(time(NULL)); // seed for random number generation
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Do you want a fortune? (y/n): ");
    char response[10];
    while (fgets(response, 10, stdin)) {
        if (response[0] == 'y') {
            int index = rand() % (sizeof(fortunes)/sizeof(fortunes[0]));
            printf("\nYour fortune is: %s\n\n", fortunes[index]);
            printf("Do you want another fortune? (y/n): ");
        } else if (response[0] == 'n') {
            printf("\nThanks for playing! Goodbye!\n");
            break;
        } else {
            printf("Sorry, I didn't understand that. Please enter y or n: ");
        }
    }
    return 0;
}