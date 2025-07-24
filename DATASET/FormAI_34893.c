//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char* theories[10] = {
        "Aliens are controlling our government",
        "The moon landing was faked",
        "Birds are actually surveillance drones",
        "The earth is flat",
        "Chemtrails are controlling our minds",
        "The illuminati are secretly ruling the world",
        "There is a secret organization that controls the weather",
        "The government is hiding the existence of time travel",
        "Elvis Presley is still alive",
        "The Bermuda Triangle is a portal to another dimension"
    };
    char* people[10] = {
        "The Rothschilds",
        "The Bilderbergs",
        "The Freemasons",
        "The New World Order",
        "The Jesuits",
        "The Reptilians",
        "The Deep State",
        "The Illuminati",
        "The Trilateral Commission",
        "The Elders of Zion"
    };
    char* evidence[10] = {
        "I read it on the internet",
        "There are too many coincidences",
        "I had a dream about it",
        "It just feels right",
        "There are secret symbols everywhere",
        "My neighbor told me",
        "There are too many unanswered questions",
        "It's the only logical explanation",
        "I saw it on a conspiracy website",
        "It's obvious if you just connect the dots"
    };
    char* actions[10] = {
        "We must spread awareness!",
        "We need to start a revolution!",
        "We must overthrow the government!",
        "We need to create our own secret society!",
        "We must recruit more people to our cause!",
        "We need to hack into government databases to find the truth!",
        "We must organize protests and rallies!",
        "We need to create a documentary exposing the truth!",
        "We must infiltrate the highest levels of government!",
        "We need to create a network of informants!"
    };
    printf("Welcome to the Random Conspiracy Theory Generator! Press enter to generate a new theory...\n");
    getchar();
    while(1) {
        printf("\n%s\n", theories[rand() % 10]);
        printf("Blaming who? %s\n", people[rand() % 10]);
        printf("What is the evidence? %s\n", evidence[rand() % 10]);
        printf("What should we do about it? %s\n", actions[rand() % 10]);
        printf("\nPress enter to generate another theory or type 'q' to quit...\n");
        char c = getchar();
        if(c == 'q') {
            break;
        }
    }
    printf("\nThanks for using the Random Conspiracy Theory Generator!\n");
    return 0;
}