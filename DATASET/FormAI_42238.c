//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
    char questions[10][101] = {
        "What is your favorite color?", 
        "What is your zodiac sign?", 
        "What is your favorite food?", 
        "What type of music do you like?", 
        "What is your biggest fear?", 
        "What is your dream job?", 
        "What is your favorite hobby?", 
        "What is your favorite movie?", 
        "What is your favorite animal?", 
        "What is your favorite place to travel?"
        };
    char fortunes[10][201] = {
        "You will find love in the most unexpected place.", 
        "Your hard work will pay off in the near future.", 
        "A long lost friend will soon reappear in your life.", 
        "An unexpected gift is coming your way.", 
        "You will travel to a place you have always dreamed of.", 
        "Your creativity will be at an all-time high.", 
        "Your health will improve in the coming months.", 
        "You will receive recognition for your hard work.", 
        "A new opportunity is coming your way.", 
        "You will find inner peace."
        };
        
    int input = 0;
    printf("Welcome to the Automated Fortune Teller! Please ask your question (1-10): ");
    scanf("%d", &input);
    
    if(input < 1 || input > 10) {
        printf("Invalid input. Please enter a number between 1 and 10.\n");
        return 0;
    }
    
    printf("You asked: %s\n", questions[input-1]);
    printf("Thinking...\n");
    int random = rand() % 10;
    printf("Your fortune is: %s\n", fortunes[random]);
    
    return 0;
}