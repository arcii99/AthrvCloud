//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    char* fortunes[] = {"You will receive good news soon.",
                        "You will meet someone special today.",
                        "A great opportunity will present itself soon.",
                        "You will receive unexpected financial gains.",
                        "You will find love in an unexpected place."};

    int index = rand() % 5;

    printf("Automated Fortune Teller:\n\n");
    printf("Your fortune for today is: %s\n", fortunes[index]);

    return 0;
}