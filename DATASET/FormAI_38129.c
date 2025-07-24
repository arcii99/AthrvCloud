//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int fortune = rand() % 5;

    if (fortune == 0) {
        printf("You will receive some exciting news today.\n");
    }
    else if (fortune == 1) {
        printf("You will have a great day today.\n");
    }
    else if (fortune == 2) {
        printf("You will meet someone special today.\n");
    }
    else if (fortune == 3) {
        printf("You will overcome a challenge in your life.\n");
    }
    else {
        printf("You will have a surprise opportunity in your near future.\n");
    }

    return 0;
}