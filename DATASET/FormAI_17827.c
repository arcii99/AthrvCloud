//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = rand() % 100;
    printf("Current Temperature: %d°C\n", temperature);

    if (temperature <= 0) {
        printf("Wow! It's freezing outside! You better stay indoors.\n");
    } else if (temperature > 0 && temperature <= 15) {
        printf("Brrr... It's pretty chilly out there. Don't forget to wear a jacket!\n");
    } else if (temperature > 15 && temperature <= 25) {
        printf("Ahh, the perfect temperature! Enjoy the day!\n");
    } else if (temperature > 25 && temperature <= 35) {
        printf("Whew! It's getting hot, isn't it? Make sure to stay hydrated.\n");
    } else {
        printf("It's scorching hot outside! Avoid stepping out unless it's absolutely necessary!\n");
    }

    printf("Would you like to check the temperature again? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Ok, let me check again...\n");
        main();
    } else {
        printf("Alright, have a good day!\n");
    }

    return 0;
}