//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

int main() {
    char c_cat_language[] = "mew mew purr purr meow meow nyan nyan";
    char english[] = "";

    printf("C Cat Language Translator\nInput C Cat Language: %s\n", c_cat_language);

    for (int i = 0; i < strlen(c_cat_language); i++) {
        if (c_cat_language[i] == 'm') {
            strcat(english, "e");
        } else if (c_cat_language[i] == 'e') {
            strcat(english, "o");
        } else if (c_cat_language[i] == 'w') {
            strcat(english, "w");
        } else if (c_cat_language[i] == 'p') {
            strcat(english, "u");
        } else if (c_cat_language[i] == 'u') {
            strcat(english, "a");
        } else if (c_cat_language[i] == 'r') {
            strcat(english, "n");
        } else if (c_cat_language[i] == 'n') {
            strcat(english, "y");
        } else if (c_cat_language[i] == 'y') {
            strcat(english, "m");
        } else if (c_cat_language[i] == 'a') {
            strcat(english, "i");
        } else if (c_cat_language[i] == 'o') {
            strcat(english, "t");
        } else {
            strcat(english, " ");
        }
    }

    printf("Output English Translation: %s", english);

    return 0;
}