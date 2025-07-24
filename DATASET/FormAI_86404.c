//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>

// Function to translate C cat language to English
void translate(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == '=') {
            printf("I am assigning a value.\n");
        } else if (string[i] == 'm') {
            printf("Meow\n");
        } else if (string[i] == 'p') {
            printf("Purr\n");
        } else {
            printf("%c", string[i]);
        }
        i++;
    }
}

int main() {
    char cat_string[] = "purr = meow + meow";
    printf("C cat string: %s\n", cat_string);
    printf("English translation: ");
    translate(cat_string);
    return 0;
}