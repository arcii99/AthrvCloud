//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

char *get_random_word();
void print_random_string(int);
void generate_typing_test(int);

char words[MAX_WORDS][MAX_WORD_LEN] = { // A list of paranoia inducing words to type
    "Conspiracy",
    "Alien",
    "Mind-control",
    "Paranoid",
    "Privacy",
    "Surreptitious",
    "Spies",
    "Covert",
    "Surveillance",
    "Encryption",
    "Secret",
    "Illuminati",
    "Propaganda",
    "Censorship",
    "Underground",
    "Black-ops",
    "Cover-up",
    "Seditious",
    "Double-agent",
    "Espionage",
    "Infiltration",
    "Prophecy",
    "Dystopian",
    "Apocalypse",
    "Orwellian",
    "Big-brother",
    "Totalitarianism",
    "Evil",
    "Zombie",
    "Pandemic",
    "Outbreak",
    "Chaos",
    "Anarchy",
    "Mass-destruction",
    "Terrorism",
    "Nuclear",
    "Armageddon",
    "End-times",
    "The-devil",
    "666",
    "Satanic",
    "Occult",
    "Ghost",
    "Poltergeist",
    "Haunting",
    "Demon",
    "Exorcism"
};

int main() {
    srand(time(NULL)); // Seed random number generator
    
    generate_typing_test(60); // Generate a typing test of 60 words
    
    return 0;
}

// Returns a random word from the list of paranoia inducing words
char *get_random_word() {
    int index = rand() % MAX_WORDS;
    return words[index];
}

// Prints a random string of length n using get_random_word()
void print_random_string(int n) {
    for(int i = 0; i < n; i++) {
        char *word = get_random_word();
        printf("%s ", word);
    }
    printf("\n");
}

// Generates a typing test of n words and prompts the user to type each word
void generate_typing_test(int n) {
    printf("Welcome to the Paranoia Typing Test\n\n");
    printf("Type each word as it appears on the screen, then press enter.\n");
    printf("You will have 60 seconds to type as many words as possible.\n\n");
    
    int success_count = 0;
    time_t start_time = time(NULL);
    while(difftime(time(NULL), start_time) <= 60.0) {
        char *word = get_random_word();
        printf("%s", word);
        fflush(stdout); // Ensure the word is printed immediately
        char user_input[MAX_WORD_LEN];
        scanf("%s", user_input);
        if(strcmp(user_input, word) == 0) {
            success_count++;
        }
    }
    
    printf("\nTime's up! You typed %d words correctly.\n", success_count);
    printf("Your typing speed is approximately %d WPM.\n", success_count);
    printf("Were you feeling paranoid while typing? I hope not!\n");
}