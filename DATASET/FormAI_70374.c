//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    /* Initialize random number generator */
    srand(time(NULL));

    /* Fortune options */
    char *fortunes[] = {
        "You will have a great day today!",
        "Tomorrow will bring an unexpected surprise.",
        "You will soon achieve a major life goal.",
        "Be careful of making impulsive decisions.",
        "A financial windfall is coming your way.",
        "You will meet someone special in the near future.",
        "Things may seem tough now, but they will get better.",
        "Your hard work will pay off in the end.",
        "Take time to appreciate the small things in life.",
        "A new opportunity is on the horizon."
    };

    /* Get random index for fortune */
    int randomIndex = rand() % 10;

    /* Print fortune */
    printf("Your fortune for today is: %s\n", fortunes[randomIndex]);

    return 0;
}