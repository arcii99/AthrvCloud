//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_conspiracy(char *string) {
    printf("%s\n", string);
}

int main() {
    srand(time(NULL));

    int random_num = rand() % 5;

    switch(random_num) {
        case 0:
            print_conspiracy("The earth is flat! The government has been lying to us for years about the shape of our planet.");
            break;
        case 1:
            print_conspiracy("Chemtrails are real! The government is spraying chemicals in the air to control our thoughts and behavior.");
            break;
        case 2:
            print_conspiracy("The moon landing was faked! NASA staged the entire event to fool the public into thinking we made it to the moon.");
            break;
        case 3:
            print_conspiracy("Aliens exist and are among us! The government has kept their existence a secret for decades.");
            break;
        case 4:
            print_conspiracy("The Illuminati control everything! They are secretly pulling the strings behind the scenes.");
            break;
        default:
            print_conspiracy("Sorry, no conspiracy theory today. Try again later.");
            break;
    }

    return 0;
}