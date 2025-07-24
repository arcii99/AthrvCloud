//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: all-encompassing
#include<stdio.h>
#include<ctype.h>
#include<string.h>

char* c_cat_to_eng(char*);

char* c_cat_to_eng(char* c_cat) {
    static const char* const c_cat_words[] = {
        "meow",     "hiss",     "purr",     "scratch",
        "tail",     "whiskers", "claws",    "kitten",
        "litter",   "yawn",     "nap",      "hunt",
        "bat",      "clean",    "curious",  "furry",
        "milk",     "playful",  "sleep",    "pouch",
        "sharp",    "lazy",     "feline",   "flee",
        "bite",     "rat",      "jump",     "knead",
        "lick",     "mouse",    "nap",      "nose",
        "paw",      "rat",      "rest",     "scratch",
        "stare",    "tail",     "tongue",   "whiskers"
    };

    static const char* const eng_words[] = {
        "I am hungry.",             "I am angry.",
        "I am happy.",              "I need attention.",
        "How are you?",             "I love you!",
        "I want to go outside.",    "I want to go inside.",
        "I am bored.",              "I am scared.",
        "Let me in!",               "Let me out!",
        "You smell bad.",           "You smell good.",
        "I want to play.",          "What is that?",
        "I'm thirsty.",             "Let's snuggle.",
        "It's nap time.",           "I'm bringing you a gift.",
        "Don't touch me there.",    "I want to play later.",
        "Where are you?",           "I want to run!",
        "Ouch!",                    "Leave me alone.",
        "What is that?",            "Hold me!",
        "I don't like that.",       "Where am I?",
        "I am tired.",              "I am clever.",
        "I am uncomfortable.",      "I need to stretch.",
        "I am watching you.",       "I like that.",
        "I am hungry.",             "I am angry.",
        "I want to rest.",          "I need attention."
    };

    static char eng[100];
    int i;

    eng[0] = '\0';

    char* token = strtok(c_cat, " ");
    while (token != NULL) {
        for (i = 0; i < 40; i++) {
            if (strcmp(token, c_cat_words[i]) == 0) {
                strcat(eng, eng_words[i]);
                strcat(eng, " ");
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return eng;
}

int main() {
    char c_cat_sentence[200], eng_sentence[500];
    printf("Enter a sentence in C-Cat language: ");
    fgets(c_cat_sentence, 200, stdin);
    c_cat_sentence[strcspn(c_cat_sentence, "\n")] = 0; // Removing newline character

    // Convert C-Cat language sentence to English
    strcpy(eng_sentence, c_cat_to_eng(c_cat_sentence));

    printf("English Translation: %s\n", eng_sentence);
    return 0;
}