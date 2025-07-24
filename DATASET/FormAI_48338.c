//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int rand_num = rand() % 5;

    if(rand_num == 0) {
        printf("You will have a very successful day!\n");
    }

    else if(rand_num == 1) {
        printf("You may encounter some obstacles, but you will overcome them!\n");
    }

    else if(rand_num == 2) {
        printf("Your hard work will pay off soon!\n");
    }

    else if(rand_num == 3) {
        printf("You may experience some unexpected changes, but they will lead to growth!\n");
    }

    else if(rand_num == 4) {
        printf("You are destined for greatness!\n");
    }

    return 0;
}