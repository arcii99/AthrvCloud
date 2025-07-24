//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Automated Fortune Teller!\n\n");

    // Seed random number generator with current time
    srand(time(NULL));
    
    // Fortune list
    char *fortunes[] = {
        "You will find success on your next venture.",
        "An old friend will contact you soon.",
        "You will meet someone special in the next month.",
        "Your hard work will pay off soon.",
        "Take a moment to appreciate the people in your life.",
        "Your creativity will lead you to new opportunities.",
        "You will receive good news regarding your finances.",
        "The path you are currently on will lead to great success.",
        "You will be presented with an exciting opportunity soon.",
        "A loved one will surprise you with a thoughtful gesture.",
        "Your health will improve in the coming days.",
        "You will find clarity and focus in your daily life.",
        "Someone close to you will offer a helping hand when you need it most.",
        "Your kindness and generosity will be rewarded.",
        "You will achieve your long-term goals with patience and persistence.",
        "An unexpected adventure awaits you in the near future.",
        "Your positive attitude will attract good things into your life.",
        "You will make a new friend in the coming weeks.",
        "Your actions will inspire others to follow in your footsteps.",
        "A new chapter in your life is about to begin."
    };
    
    // Generate random index to select fortune
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    int index = rand() % num_fortunes;
    
    // Display fortune
    printf("Your fortune for today is:\n%s\n", fortunes[index]);
    
    return 0;
}