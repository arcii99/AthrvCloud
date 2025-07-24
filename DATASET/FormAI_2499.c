//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ans;
    char name[20];
    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s! I will predict your fortune.\n", name);

    srand(time(NULL));
    ans = rand() % 10;

    switch(ans) {
        case 0:
            printf("\n%s, You will find success in whatever you do.", name);
            break;
        case 1:
            printf("\n%s, Your dedication will bring you great success.", name);
            break;
        case 2:
            printf("\n%s, A great opportunity is coming your way. Be ready for it.", name);
            break;
        case 3:
            printf("\n%s, Keep pushing yourself and you will achieve your goals.", name);
            break;
        case 4:
            printf("\n%s, A big surprise is in store for you!", name);
            break;
        case 5:
            printf("\n%s, Your hard work and perseverance will pay off soon.", name);
            break;
        case 6:
            printf("\n%s, Your creativity will be your biggest strength.", name);
            break;
        case 7:
            printf("\n%s, You will soon find inner peace and harmony.", name);
            break;
        case 8:
            printf("\n%s, You will meet someone special soon.", name);
            break;
        case 9:
            printf("\n%s, Your life will be filled with joy and happiness.", name);
            break;
        default:
            printf("\n%s, Error. Please try again later.", name);
    }

    return 0;
}