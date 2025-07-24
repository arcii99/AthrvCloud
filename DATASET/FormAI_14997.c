//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <string.h>

struct Word {
    char alien[20];
    char human[20];
};

typedef struct Word Word;

Word dictionary[] = {
    { "kroax", "hello" },
    { "plensh", "goodbye" },
    { "tulark", "thank you" },
    { "vorg", "yes" },
    { "nok", "no" }
};

void translate(char* alien) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(alien, dictionary[i].alien) == 0) {
            printf("Human: %s\n", dictionary[i].human);
            return;
        }
    }
    printf("Word not found in dictionary\n");
}

int main() {
    printf("Enter an alien word:\n");
    char alien[20];
    scanf("%s", alien);

    translate(alien);
    
    return 0;
}