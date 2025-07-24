//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* fortunes[] = {"You will have a prosperous future.", 
                    "Your hard work will soon pay off.",
                    "You will find love in unexpected places.",
                    "New opportunities will arise in your career.",
                    "A great adventure is on the horizon.",
                    "Your creativity will lead to success.",
                    "You will meet someone who will change your life.",
                    "Your health will improve.",
                    "Good things will come to you in the near future.",
                    "Your determination will lead you to success."};

int main() {
    srand(time(NULL));  // Set the random seed
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("----------------------------------------\n\n");
    
    while(1) {
        printf("Please think of a question and press enter to get your answer. (Type 'quit' to exit)\n");
        char input[100];
        fgets(input, 100, stdin);  // Get user input
        
        if(strcmp(input, "quit\n") == 0) {  // Exit if user types 'quit'
            printf("\nThank you for using the Automated Fortune Teller!\n");
            break;
        }
        
        int index = rand() % 10;  // Choose a random fortune
        printf("\n%s\n\n", fortunes[index]);  // Output the fortune
    }
    
    return 0;
}