//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Create an array to store fortunes
    char *fortunes[] = {"Today is a good day to learn something new.", 
                        "You will meet someone important today.",
                        "A pleasant surprise is in store for you.",
                        "You will receive a promotion at work.",
                        "Don't be afraid to take risks.",
                        "Your hard work will pay off in the end.",
                        "A loved one is thinking of you.",
                        "Look for the good in every situation.",
                        "You will soon find an opportunity for success.",
                        "Your future is bright."};
    
    // Get the length of the array
    int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    
    // Generate a random number
    srand(time(NULL));
    int randNum = rand() % numFortunes;
    
    // Display the fortune
    printf("Your fortune for today is:\n");
    printf("%s\n", fortunes[randNum]);
    
    return 0;
}