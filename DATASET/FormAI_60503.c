//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: imaginative
#include <stdio.h>
#include <string.h>

char* translate(char* phrase);

int main() {
    char phrase[100];
    printf("Enter a phrase in C Cat Language: ");
    fgets(phrase, 100, stdin);
    char* translated = translate(phrase);
    printf("In English, that means: %s", translated);
    return 0;
}

char* translate(char* phrase) {
    if (strcmp(phrase, "Meow!") == 0) {
        return "Hello!";
    } else if (strcmp(phrase, "Purr...") == 0) {
        return "I'm happy.";
    } else if (strcmp(phrase, "Hiss.") == 0) {
        return "Stay away!";
    } else if (strcmp(phrase, "Mrowww.") == 0) {
        return "I'm hungry.";
    } else if (strcmp(phrase, "Psss.") == 0) {
        return "Follow me.";
    } else {
        return "I don't understand.";
    }
}