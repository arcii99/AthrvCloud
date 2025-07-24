//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Function to translate a string from Alien Language to English
void translate(char alien_str[]) {
    // Define the Alien Language dictionary - replace these with your own translations
    char alien_dict[][20] = {"nfn", "hello", "mld", "goodbye", "xctm", "thank you", "trt", "please"};
    int dict_size = sizeof(alien_dict) / sizeof(alien_dict[0]);
    // Split the Alien Language string into words
    char *word = strtok(alien_str, " ");
    while (word != NULL) {
        // Check if the current word is in the Alien Language dictionary
        int found = 0;
        for (int i = 0; i < dict_size; i++) {
            if (strcmp(word, alien_dict[i]) == 0) {
                printf("%s ", alien_dict[i+1]);
                found = 1;
                break;
            }
        }
        // If the current word is not in the dictionary, print it as-is
        if (!found) {
            printf("%s ", word);
        }
        // Move to the next word in the Alien Language string
        word = strtok(NULL, " ");
    }
}

// Main function to test the Alien Language Translator
int main() {
    char alien_str[] = "nfn, my name is xctm. trt translate this sentence into Alien Language.";
    printf("Alien Language: %s\n", alien_str);
    printf("English Translation: ");
    translate(alien_str);
    printf("\n");
    return 0;
}