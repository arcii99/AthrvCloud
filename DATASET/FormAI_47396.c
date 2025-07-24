//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char* theories[] = {
        "The moon landing was faked",
        "Area 51 holds evidence of extraterrestrial life",
        "The government is controlling our thoughts with chemtrails",
        "Elvis Presley is still alive",
        "The Illuminati controls the world"
    };

    srand(time(0));
    int random = rand() % 5;

    printf("Welcome to the Random Conspiracy Theory Generator! Here's your theory for today:\n\n");
    printf("%s\n", theories[random]);

    return 0;
}