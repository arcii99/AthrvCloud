//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // set up random seed
    srand(time(0));

    // declare fortune array
    char *fortunes[5] = {"You will have a prosperous day.",
                         "Keep your mind open to new ideas.",
                         "Your hard work will pay off soon.",
                         "Good luck will come your way.",
                         "A pleasant surprise is in store for you."};

    // get random index for fortune array
    int index = rand() % 5;

    // print fortune
    printf("Your fortune today is: %s\n", fortunes[index]);

    return 0;
}