//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    const char* fortunes[] = {"You will become a millionaire in the next five years.",
                              "You will meet your soulmate in the next six months.",
                              "A new business opportunity will come your way soon.",
                              "You will go on a life-changing trip in the near future.",
                              "A creative project that you have been working on will be successful.",
                              "You will make a big breakthrough in your career soon.",
                              "A long-lost friend will contact you soon.",
                              "An unexpected financial windfall is coming your way."};

    int random_index = rand() % (sizeof(fortunes) / sizeof(*fortunes));

    printf("Your fortune for today is: %s\n", fortunes[random_index]);

    return 0;
}