//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>

// Define our translation function
void translate(char* phrase){
    char* c_cats[][2] = {
        {"cat", "nya"},
        {"meow", "nyaa"},
        {"food", "noms"},
        {"sleep", "purrs"},
        {"play", "swats"},
        {"love", "purrfect"},
        {"water", "licks"},
        {"box", "cave"},
        {"treats", "catnip"},
        {"vet", "hide"},
        {"outside", "freedom"},
        {"scratch", "sharpen"},
        {"mouse", "toy"},
        {"human", "staff"},
        {"furry", "snuggly"},
        {"claws", "weapons"},
        {"cuddle", "nuzzle"},
        {"bird", "prey"},
        {"tail", "plaything"},
        {"bath", "betrayal"},
        {"yarn", "fun string"},
        {"fish", "yummy swimmy"},
        {"window", "viewing station"},
        {"jump", "leap of faith"},
        {"purr", "motor"},
        {"hiss", "warning"},
        {"chase", "hunt"},
        {"nap", "catnap"},
        {"pounce", "ambush"}
    };

    // Get the number of phrases in our dictionary
    int num_phrases = sizeof(c_cats) / sizeof(c_cats[0]);

    // Replace any matching phrases in the input
    char* matching_word;
    for (int i=0; i<num_phrases; i++) {
        matching_word = strstr(phrase, c_cats[i][0]);
        if (matching_word != NULL) {
            // Print the translated phrase minus the matching word
            printf("%.*s", matching_word-phrase, phrase);
            printf("%s", c_cats[i][1]);

            // Recurse on the rest of the string
            translate(matching_word+strlen(c_cats[i][0]));
            return;
        }
    }

    // If there are no matches left, print the remainder of the input
    printf("%s", phrase);
}

int main() {
    // Define some phrases to translate
    char phrase1[] = "I love my cat so much!";
    char phrase2[] = "Scratch that post, not the couch!";
    char phrase3[] = "I gave my cat some treats for being good.";
    char phrase4[] = "When my human is gone, I like to play with their shoes.";

    // Translate the phrases
    translate(phrase1);
    printf("\n");
    translate(phrase2);
    printf("\n");
    translate(phrase3);
    printf("\n");
    translate(phrase4);
    printf("\n");

    return 0;
}