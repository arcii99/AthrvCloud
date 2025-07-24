//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator
    
    char name[20];
    printf("Welcome to the Fortune Teller. Please enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s! I will now attempt to divine your future...\n\n", name);
    
    int choice;
    printf("Please choose a number from the following options:\n");
    printf("1. Career\n2. Love\n3. Wealth\n4. Health\n5. Family\n");
    scanf("%d", &choice);
    printf("\n");
    
    switch(choice) {
        case 1:
            printf("You will find great success in your chosen career path. Hard work and dedication will pay off.\n");
            break;
        case 2:
            printf("New love is on the horizon. Keep an open mind and heart, and be ready to embrace it.\n");
            break;
        case 3:
            printf("You will experience a windfall of financial abundance in the near future. Use it wisely.\n");
            break;
        case 4:
            printf("Your health is a top priority. Make sure to prioritize self-care and listen to your body.\n");
            break;
        case 5:
            printf("Your family will be a great source of strength and support throughout your journey.\n");
            break;
        default:
            printf("Invalid selection. Please try again and choose a number between 1 and 5.\n");
            return 0;
    }
    
    printf("\nThank you for using the Fortune Teller. May your future be bright!\n");
    
    return 0;
}