//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Shape-shifting variables
int animal = 0;  // 0: cat, 1: dog, 2: bird
int fur_color = 0; // 0: black, 1: white, 2: orange
int tail_len = 0; // 0: short, 1: medium, 2: long
int wing_size = 0; // 0: small, 1: medium, 2: large

// Translation function
char* translate(char* sentence) {
    // Convert to lowercase
    for (int i = 0; i < strlen(sentence); i++) {
        sentence[i] = tolower(sentence[i]);
    }

    // Split sentence into words
    char* word;
    char* rest = sentence;
    char* translated_sentence = malloc(sizeof(char) * 500);
    translated_sentence[0] = '\0';

    while ((word = strtok_r(rest, " ", &rest))) {
        // Animal Shape-Shifting
        if (strstr(word, "cat")) {
            animal = 0;
        } else if (strstr(word, "dog")) {
            animal = 1;
        } else if (strstr(word, "bird")) {
            animal = 2;
        }

        // Fur Color Shape-Shifting
        if (strstr(word, "black")) {
            fur_color = 0;
        } else if (strstr(word, "white")) {
            fur_color = 1;
        } else if (strstr(word, "orange")) {
            fur_color = 2;
        }

        // Tail Length Shape-Shifting
        if (strstr(word, "short")) {
            tail_len = 0;
        } else if (strstr(word, "medium")) {
            tail_len = 1;
        } else if (strstr(word, "long")) {
            tail_len = 2;
        }

        // Wing Size Shape-Shifting
        if (strstr(word, "small")) {
            wing_size = 0;
        } else if (strstr(word, "medium")) {
            wing_size = 1;
        } else if (strstr(word, "large")) {
            wing_size = 2;
        }

        // Translation
        switch (animal) {
            case 0: // Cat
                switch (fur_color) {
                    case 0: // Black
                        strcat(translated_sentence, "Meow meow, ");
                        break;
                    case 1: // White
                        strcat(translated_sentence, "Purr purr, ");
                        break;
                    case 2: // Orange
                        strcat(translated_sentence, "Hiss hiss, ");
                        break;
                }
                switch (tail_len) {
                    case 0: // Short
                        strcat(translated_sentence, "short tail, ");
                        break;
                    case 1: // Medium
                        strcat(translated_sentence, "medium tail, ");
                        break;
                    case 2: // Long
                        strcat(translated_sentence, "long tail, ");
                        break;
                }
                strcat(translated_sentence, "I am a cat.");
                break;
            case 1: // Dog
                strcat(translated_sentence, "Bark bark,");
                break;
            case 2: // Bird
                switch (wing_size) {
                    case 0: // Small
                        strcat(translated_sentence, "Chirp chirp, small wings, ");
                        break;
                    case 1: // Medium
                        strcat(translated_sentence, "Tweet tweet, medium wings, ");
                        break;
                    case 2: // Large
                        strcat(translated_sentence, "Squawk squawk, large wings, ");
                        break;
                }
                strcat(translated_sentence, "I am a bird.");
                break;
            default:
                strcat(translated_sentence, word);
                strcat(translated_sentence, " ");
                break;
        }
    }

    return translated_sentence;
}

int main() {

    char* sentence = "I saw a black cat with a long tail.";
    printf("%s\n", translate(sentence));

    sentence = "The white dog ran fast.";
    printf("%s\n", translate(sentence));

    sentence = "There was an orange bird with small wings.";
    printf("%s\n", translate(sentence));

    return 0;
}