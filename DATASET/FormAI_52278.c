//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char* fortunes[] = {
        "You will have a great day tomorrow.",
        "Love will enter your life soon.",
        "Your hard work will pay off soon.",
        "You will receive a pleasant surprise soon.",
        "Good things come to those who wait.",
        "Be patient and your dreams will come true.",
        "Take a chance and it will pay off.",
        "The journey is more important than the destination.",
        "Your determination will lead to success.",
        "Believe in yourself and anything is possible."
    };
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);

    srand(time(NULL));
    int random_index = rand() % num_fortunes;
    char* fortune = fortunes[random_index];

    printf("Welcome to the Automated Fortune Teller\n\n");
    printf("Your fortune for today is:\n\n%s\n", fortune);

    return 0;
}