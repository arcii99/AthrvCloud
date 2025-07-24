//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    char* fortunes[] = {
        "You will meet an old friend today.",
        "A new opportunity will present itself to you soon.",
        "Good things come to those who wait. Patience is key.",
        "Your hard work will pay off in the near future.",
        "It's time to take a leap of faith.",
        "Be on the lookout for a sign.",
        "The answer you seek is right in front of you.",
        "You will overcome your challenges with ease.",
        "Great things await you in your near future.",
        "Don't be afraid to take risks and try new things.",
        "You will find success in unexpected places.",
        "Trust your instincts and follow your intuition."
    };
    srand(time(NULL));
    int i = rand() % 12;
    printf("Your fortune for today is:\n\n%s\n\n", fortunes[i]);
    return 0;
}