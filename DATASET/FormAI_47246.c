//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\n\nWelcome to the C Typing Speed Test!\n\n");

    char strings[10][100] = {"The quick brown fox jumps over the lazy dog.\n", 
                             "Jackdaws love my big sphinx of quartz.\n", 
                             "How vexingly quick daft zebras jump!\n",
                             "Sphinx of black quartz, judge my vow.\n",
                             "The five boxing wizards jump quickly.\n",
                             "Pack my box with five dozen liquor jugs.\n",
                             "A quick brown fox jumps over a lazy dog.\n",
                             "Jaded zombies acted quaintly but kept driving their oxen forward.\n",
                             "The public was amazed to view the quickness and dexterity of the juggler.\n",
                             "Quick brown fox jumps over a lazy dog.\n"};

    int length[10], count = 0, time_limit, time_taken;

    printf("We have 10 different strings for you to type.\n");
    printf("You will get 25 seconds to type each string.\n");
    printf("Are you ready? Press any key to start.\n");
    getchar();

    srand((unsigned) time(NULL));
    for (int i = 0; i < 10; i++) {
        printf("String [%d]: %s", i + 1, strings[i]);
        length[i] = strlen(strings[i]);
        time_limit = 25;
        time_t start_time = time(NULL), current_time = time(NULL);

        while (difftime(current_time, start_time) < time_limit) {
            char input;
            scanf("%c", &input);
            if (input == '\n') {
                break;
            }
            if (input != strings[i][count]) {
                printf("\nYou have typed a wrong character. Please try again.\n");
                break;
            }
            count++;
        }
        time_taken = difftime(current_time, start_time);
        printf("\nTime taken: %d seconds\n", time_taken);
        printf("Your typing speed for string %d is: %.2f characters per minute.\n", i + 1, (length[i] * 60.0) / (time_taken));
    }

    printf("\n\nCongratulations! You have completed the typing speed test.\n");
    printf("Thank you for participating.\n\n");

    return 0;
}