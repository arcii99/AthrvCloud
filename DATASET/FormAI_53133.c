//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random conspiracy theory
char* generate_conspiracy() {
    // Array of conspiracy theories
    char* theories[] = {
        "The moon landing was faked by the government",
        "Chemtrails are being used to control our minds",
        "The illuminati is controlling world events",
        "Area 51 contains evidence of extraterrestrial life",
        "The government is hiding a cure for cancer",
        "COVID-19 is a man-made virus created in a lab"
    };
    
    // Generate a random index to select a theory from the array
    srand(time(NULL));
    int index = rand() % 6;
    
    return theories[index];
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("----------------------------------------------------\n\n");
    
    // Prompt the user to generate a conspiracy theory
    char input;
    do {
        printf("Press 'g' to generate a random conspiracy theory or 'q' to quit: ");
        scanf("%c", &input);
        
        // Generate a conspiracy theory if the user enters 'g'
        if (input == 'g') {
            char* theory = generate_conspiracy();
            printf("\n%s\n\n", theory);
        }
        
        // Clear the input buffer
        while (getchar() != '\n');
        
    } while (input != 'q');
    
    printf("Thank you for using the Random Conspiracy Theory Generator!\n");
    printf("-----------------------------------------------------------\n");
    
    return 0;
}