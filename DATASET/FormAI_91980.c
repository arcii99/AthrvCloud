//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char* conspiracies[] = {"The government controls the weather through chemtrails.",
                            "The moon landing was faked.",
                            "9/11 was an inside job.",
                            "The Illuminati controls everything.",
                            "The Earth is flat and NASA is lying to us.",
                            "Aliens live among us.",
                            "Vaccines cause autism.",
                            "The world is run by lizard people.",
                            "The Titanic never sank - it was her sister ship.",
                            "All famous people are clones.",
                            "The Bermuda Triangle is a portal to another dimension.",
                            "The CIA created AIDS.",
                            "The pyramids were built by aliens."};

    int index;

    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    while(1) {
        printf("Press enter to generate a new conspiracy theory or type 'exit' to quit:\n");
        char input[10];
        fgets(input, 10, stdin);

        if(input[0] == 'e' || input[0] == 'E') {
            break;
        }

        index = rand() % 13;
        printf("\n%s\n\n", conspiracies[index]);
    }

    printf("Thank you for using the Random Conspiracy Theory Generator. Don't forget to stay woke!");

    return 0;
}