//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char* fortunes[] = {
        "You will meet someone special today.",
        "You'll be blessed with good news in the near future.",
        "Your hard work will pay off soon.",
        "A unique opportunity will present itself to you.",
        "You will make a new friend today.",
        "Your future looks bright and full of promise.",
        "Your creative ideas will be recognized and rewarded.",
        "Your courage and confidence will lead to success.",
        "You'll be given a chance to shine and show your skills.",
        "Your persistence and determination will lead to victory."
    };

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Think of a question and I will provide an answer.\n");
    printf("Press Enter to get your fortune!\n");
    getchar();

    srand(time(NULL));
    int random_index = rand() % 10;

    printf("Your fortune is: %s\n", fortunes[random_index]);

    return 0;
}