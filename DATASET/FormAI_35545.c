//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <string.h>

struct Translation {
    const char* c_word;
    const char* cat_translation;
};

struct Translation cat_translations[] = {
    {"meow", "mewo meow"},
    {"scratch", "ruuf staarsh"},
    {"nap", "zeeee snore"},
    {"food", "munch munch"},
    {"water", "slurp slurp"},
    {"play", "purr pounce"},
    {"sleep", "prrrrr zzzzzz"}
};

int main() {
    char user_input[50];
    printf("Welcome to C Cat Translator! \n");
    printf("Please enter a word to be translated into Cat Language: \n");
    scanf("%s", user_input);
    int i;

    for (i = 0; i < sizeof(cat_translations) / sizeof(cat_translations[0]); i++) {
        if (strcmp(cat_translations[i].c_word, user_input) == 0) {
            printf("%s \n", cat_translations[i].cat_translation);
            return 0;
        }
    }

    printf("Sorry, we couldn't find a translation for that word. \n");
    return 0;
}