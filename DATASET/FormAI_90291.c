//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: secure
#include <stdio.h>
#include <string.h>

void translate(char *cat, char *english) {
    if (strcmp(cat, "meow") == 0) {
        strcpy(english, "Hello");
    } else if (strcmp(cat, "purr") == 0) {
        strcpy(english, "Thank you");
    } else if (strcmp(cat, "hiss") == 0) {
        strcpy(english, "Stop");
    } else {
        strcpy(english, "I don't understand");
    }
}

int main() {
    char cat[20], english[20];
    printf("Enter a cat sound: ");
    scanf("%s", cat);
    translate(cat, english);
    printf("In English: %s\n", english);
    return 0;
}