//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up random seed
    srand(time(NULL));
    
    // Define fortune messages
    char *fortunes[] = {"You will find happiness in unexpected places.",
                        "Good news will come to you soon.",
                        "Your hard work will pay off in the end.",
                        "A new opportunity will present itself to you.",
                        "You will meet someone special in the near future.",
                        "An unexpected journey awaits you.",
                        "Your creativity will be rewarded.",
                        "You are good enough, no need to doubt yourself.",
                        "A new friendship will blossom soon.",
                        "An old friend will come back into your life."};
    
    // Generate random index
    int random_index = rand() % 10;
    
    // Print fortune message
    printf("Your fortune for today is: %s\n", fortunes[random_index]);
    
    return 0;
}