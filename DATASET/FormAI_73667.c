//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

void print_instructions();
void clear_screen();
void generate_words(char words[][MAX_WORD_LENGTH]);
int calculate_typing_speed(float time_taken, int num_chars);

int main() {
    char player_name[MAX_NAME_LENGTH];
    char typed_text[MAX_WORDS * MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int i, num_chars, typed_chars = 0, correct_chars = 0;
    float start_time = 0.0, end_time = 0.0, time_taken;
    int typing_speed;

    clear_screen();
    print_instructions();

    printf("Enter your name: ");
    fgets(player_name, MAX_NAME_LENGTH, stdin);

    clear_screen();
    printf("Welcome, %s", player_name);
    printf("You will be given %d words to type as fast as possible. Press any key to start.", MAX_WORDS);
    getchar();

    generate_words(words);

    for (i = 0; i < MAX_WORDS; i++) {
        printf("Type the word \"%s\": ", words[i]);
        fgets(typed_text, MAX_WORD_LENGTH, stdin);
        num_chars = strlen(words[i]);

        if (typed_text[num_chars - 1] == '\n') {
            typed_text[num_chars - 1] = '\0';
            num_chars = num_chars - 1;
        }       

        if (strcmp(typed_text, words[i]) == 0) {
            correct_chars += num_chars;
            typed_chars += num_chars;
            printf("Correct! ");
        }
        else {
            typed_chars += strlen(typed_text);
            printf("Incorrect. ");
        }

        printf("You typed %d characters out of %d in %0.2f seconds.\n", num_chars, strlen(words[i]), end_time - start_time);
    }

    time_taken = end_time - start_time;
    typing_speed = calculate_typing_speed(time_taken, typed_chars);

    printf("\nYour typing speed is %d characters per minute. Well done!\n", typing_speed);
    
    return 0;
}

void print_instructions() {
    printf("Welcome to the typing speed test!\n\n");
    printf("You will be given a series of words to type as fast as possible.\n");
    printf("Your typing speed will be calculated in characters per minute.\n\n");
    printf("Press any key to begin...\n");

    getchar();
}

void clear_screen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void generate_words(char words[][MAX_WORD_LENGTH]) {
    int i;
    char *word_list[] = {"apple", "banana", "cherry", "orange", "grape", "watermelon", "kiwi", "pear", "peach", "mango"};

    srand(time(NULL));

    for (i = 0; i < MAX_WORDS; i++) {
        strcpy(words[i], word_list[rand() % 10]);
    }

    printf("\nWords generated:\n");

    for (i = 0; i < MAX_WORDS; i++) {
        printf("\"%s\" ", words[i]);
    }

    printf("\n\nPress any key to start typing...");
    getchar();
    clear_screen();
}

int calculate_typing_speed(float time_taken, int num_chars) {
    float minutes = time_taken / 60.0;
    int chars_per_minute = (int) ((float) num_chars / minutes);

    return chars_per_minute;
}