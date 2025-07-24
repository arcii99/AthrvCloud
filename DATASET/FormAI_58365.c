//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEST_TIME 60 // time limit for the test in seconds

void get_random_text(char *text);
void print_time_remaining(int seconds_left);

int main()
{
    char user_text[1000];
    char random_text[1000];
    int user_text_length, random_text_length, correct_chars = 0;
    time_t start_time, current_time, elapsed_time;
    
    // get the random text to use for the test
    get_random_text(random_text);
    random_text_length = strlen(random_text);
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("You have %d seconds to type as much of the following text as you can:\n\n%s\n\n", TEST_TIME, random_text);
    printf("Press enter when you are ready to start the test.");
    getchar(); // wait for user to press enter
    
    // get the start time of the test
    start_time = time(NULL);
    
    // loop until time limit is reached
    while ((current_time = time(NULL)) - start_time < TEST_TIME) {
        
        // print remaining time every 5 seconds
        if ((int)difftime(current_time, start_time) % 5 == 0) {
            print_time_remaining((int)(TEST_TIME - (current_time - start_time)));
        }
        
        // prompt user for input
        printf(">> ");
        fgets(user_text, 1000, stdin);
        user_text_length = strlen(user_text);
        
        // check if user input matches random text
        for (int i = 0; i < random_text_length && i < user_text_length; i++) {
            if (user_text[i] == random_text[i]) {
                correct_chars++;
            }
        }
    }
    
    // get elapsed time and calculate typing speed
    elapsed_time = time(NULL) - start_time;
    double typing_speed = (double)correct_chars / elapsed_time * 60;
    
    printf("\nTime's up!\n");
    printf("You typed %d characters correctly in %d seconds.\n", correct_chars, elapsed_time);
    printf("Your typing speed is %.2f characters per minute.", typing_speed);
    
    return 0;
}

// generate random text for the user to type
void get_random_text(char *text)
{
    srand(time(NULL));
    const char *words[] = {
        "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog",
        "kind", "hearts", "are", "more", "than", "coronets", "and", "simple", "faith", "than", "norman", "blood",
        "it", "is", "a", "truth", "universally", "acknowledged", "that", "a", "single", "man", "in", "possession", "of", "a", "good", "fortune", "must", "be", "in", "want", "of", "a", "wife",
        "to", "be", "or", "not", "to", "be", "that", "is", "the", "question", "whether", "tis", "nobler", "in", "the", "mind", "to", "suffer", "the", "slings", "and", "arrows", "of", "outrageous", "fortune", "or", "to", "take", "arms", "against", "a", "sea", "of", "troubles",
        "all", "the", "worlds", "a", "stage", "and", "all", "the", "men", "and", "women", "merely", "players", "they", "have", "their", "exits", "and", "their", "entrances", "and", "one", "man", "in", "his", "time", "plays", "many", "parts",
        "but", "soft", "what", "light", "through", "yonder", "window", "breaks", "it", "is", "the", "east", "and", "juliet", "is", "the", "sun",
        "in", "fair", "verona", "where", "we", "lay", "our", "scene", "from", "ancient", "grudge", "break", "to", "new", "mutiny", "where", "civil", "blood", "makes", "civil", "hands", "unclean",
        "once", "upon", "a", "midnight", "dreary", "while", "i", "pondered", "weak", "and", "weary", "over", "many", "a", "quaint", "and", "curious", "volume", "of", "forgotten", "lore"
    };
    
    int num_words = sizeof(words) / sizeof(words[0]);
    for (int i = 0; i < 30; i++) {
        int rand_index = rand() % num_words;
        strcat(text, words[rand_index]);
        strcat(text, " ");
    }
}

// print the time remaining in the test
void print_time_remaining(int seconds_left)
{
    printf("\n%d seconds remaining.\n", seconds_left);
}