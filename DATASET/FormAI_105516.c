//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

void translate(char sentence[]) {
    char translation[1000] = "";
    int length = strlen(sentence);

    for(int i = 0; i < length; i++) {
        if(sentence[i] == 'c' || sentence[i] == 'C') {
            strcat(translation, "meow");
        } else if(sentence[i] == 'a' || sentence[i] == 'A') {
            strcat(translation, "purr");
        } else if(sentence[i] == 't' || sentence[i] == 'T') {
            strcat(translation, "hiss");
        } else if(sentence[i] == 'g' || sentence[i] == 'G') {
            strcat(translation, "scratch");
        } else if(sentence[i] == 'b' || sentence[i] == 'B') {
            strcat(translation, "lick");
        } else {
            strcat(translation, " ");
        }
    }

    printf("%s\n", translation);
}

int main() {
    char sentence[1000];

    printf("Enter a sentence in C Cat Language: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    printf("Translation: ");
    translate(sentence);

    return 0;
}