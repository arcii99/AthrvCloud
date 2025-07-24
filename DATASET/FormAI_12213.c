//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Set random seed using current time
    
    const char* nouns[] = {"aliens", "government", "Illuminati", "Big Pharma", "NWO"};
    const char* verbs[] = {"control", "manipulate", "brainwash", "dominate", "enslave"};
    const char* adjectives[] = {"secret", "hidden", "shadowy", "sinister", "deceptive"};
    const char* objects[] = {"population", "energy", "currency", "technology", "resources"};
    const char* locations[] = {"Area 51", "Bermuda Triangle", "Hollow Earth", "Moon landing site", "Atlantis"};
    
    printf("Welcome to the random conspiracy theory generator!\n\n");
    
    while(1) {
        printf("Here's a new theory for you: ");
        printf("%s %s the %s %s in %s.\n\n", nouns[rand() % 5], verbs[rand() % 5], adjectives[rand() % 5], objects[rand() % 5], locations[rand() % 5]);
        printf("Would you like to hear another theory? (y/n): ");
        
        char choice = getchar();
        while(getchar() != '\n'); // Clear input buffer
        
        if(choice == 'n') {
            break;
        }
    }
    
    printf("\nThanks for using the random conspiracy theory generator. Stay woke!");
    
    return 0;
}