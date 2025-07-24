//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random;
    srand(time(NULL));
    random = rand() % 10;

    printf("Welcome to the Automated Fortune Teller!\n\n");

    switch(random) {
        case 0:
            printf("You will receive good news today!\n");
            break;
        case 1:
            printf("Be careful with your decisions today!\n");
            break;
        case 2:
            printf("Your hard work will pay off soon!\n");
            break;
        case 3:
            printf("You will meet someone special in the near future.\n");
            break;
        case 4:
            printf("Travel is in your future!\n");
            break;
        case 5:
            printf("Someone from your past will reappear soon.\n");
            break;
        case 6:
            printf("The next time you take a risk, it will pay off.\n");
            break;
        case 7:
            printf("Lucky numbers for today: 4, 7, 13.\n");
            break;
        case 8:
            printf("You will experience unexpected change today.\n");
            break;
        case 9:
            printf("Meditation or relaxation will bring you peace today.\n");
            break;
        default:
            printf("Error: invalid random number.\n");
            break;
    }

    return 0;
}