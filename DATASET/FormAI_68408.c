//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    char repeat = 'y';
    
    srand(time(NULL));
    
    // Array of possible fortunes
    char *fortunes[] = {
        "You will soon receive unexpected news.",
        "Good luck is just around the corner.",
        "Your artistic talents will soon be recognized.",
        "Your future looks bright!",
        "An exciting trip is in your future.",
        "A new opportunity will soon present itself.",
        "Your hard work will pay off soon.",
        "Expect great things to happen to you soon.",
        "Love is in the air.",
        "Don't give up hope, good things are coming.",
        "You will soon find what you have been looking for.",
        "The situation may seem difficult now, but stay positive.",
        "Your friends and family will support you through tough times.",
        "Your determination will lead you to success.",
        "You are on the right path, keep moving forward.",
        "Be patient, good things come to those who wait."
    };
    
    printf("Welcome to the Automated Fortune Teller!\n\n");
    
    do {
        printf("Press enter to receive your fortune.\n");
        getchar();
        
        i = rand() % 16; // Generate random number between 0-15
        
        printf("\n%s\n\n", fortunes[i]);
        
        printf("Would you like to ask another question? (y/n)\n");
        scanf(" %c", &repeat);
    } while (repeat == 'y' || repeat == 'Y');
    
    printf("\nThanks for using the Automated Fortune Teller!\n");
    
    return 0;
}