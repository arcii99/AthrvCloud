//FormAI DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dictionary[][20] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine"};

int contains(char *word){
    for (int i = 0; i < 12; i++){
        if (strcmp(word, dictionary[i]) == 0)
            return 1;
    }
    return 0;
}

void spellCheck(char *text) {
    char *word = strtok(text, ".,!? ;:\"()\n");
    printf("\nMisspelled words: ");
    while (word != NULL) {
        if (!contains(word)){
            printf("%s, ", word);
        }
        word = strtok(NULL, ".,!? ;:\"()\n");
    }
}

int main() {
    char *text = "I ate an appel and a nectarne for brekfast, then went to the grocry store and bought some banannas."; // line 17
    spellCheck(text);
    return 0;
}