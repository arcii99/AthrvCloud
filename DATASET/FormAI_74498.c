//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between 1 - 9
int generateNumber() {
    srand(time(NULL));
    return rand() % 9 + 1;
}

// function to get a random fortune based on number generated
char* getFortune(int num) {
    switch(num) {
        case 1:
            return "The future looks bright!";
        case 2:
            return "Be wary of strangers today.";
        case 3:
            return "A new opportunity will arise.";
        case 4:
            return "Your hard work will pay off soon.";
        case 5:
            return "A loved one may need your help.";
        case 6:
            return "Keep an open mind to new ideas.";
        case 7:
            return "You will receive a surprise gift.";
        case 8:
            return "Travel is in your future.";
        case 9:
            return "Be kind to yourself today.";
        default:
            return "Error: Fortune could not be generated.";
    }
}

int main() {
    // welcome message and instructions
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Think of a question and press Enter to get your fortune.\n");
    printf("Type 'quit' to exit.\n");

    // loop to repeatedly ask for input until user types 'quit'
    while(1) {
        // get user input
        char input[100];
        fgets(input, sizeof(input), stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // if user types 'quit', exit program
        if(strcmp(input, "quit") == 0) {
            printf("Thanks for using the Automated Fortune Teller!\n");
            break;
        }

        // generate random number and get corresponding fortune
        int num = generateNumber();
        char* fortune = getFortune(num);

        // print fortune to console
        printf("Your fortune is: %s\n", fortune);
    }

    return 0;
}