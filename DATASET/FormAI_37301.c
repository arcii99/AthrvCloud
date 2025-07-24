//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int main() {
    char c_cat_language[] = "MIAO MIAO MEOW PURR PURR";
    char human_language[] = "";
    char c_cat_word[10] = "";
    int i, j = 0;

    for (i = 0; i < strlen(c_cat_language); i++) {
        if (c_cat_language[i] != ' ') {
            c_cat_word[j] = c_cat_language[i];
            j++;
        }
        else {
            c_cat_word[j] = '\0';
            j = 0;

            if (strcmp(c_cat_word, "MIAO") == 0) {
                strcat(human_language, "Hi");
            }
            else if (strcmp(c_cat_word, "MEOW") == 0) {
                strcat(human_language, "How are you");
            }
            else if (strcmp(c_cat_word, "PURR") == 0) {
                strcat(human_language, "I am happy");
            }

            strcat(human_language, " ");
        }
    }

    printf("%s", human_language);

    return 0;
}