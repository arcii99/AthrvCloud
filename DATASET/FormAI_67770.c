//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: high level of detail
#include <stdio.h>

int main() {
    char cCat[100], cTranslate[100];
    int i, j, k = 0;
    
    // Getting user input for cCat language string
    printf("Enter the cCat language string to be translated: ");
    fgets(cCat, 100, stdin);
    
    // Converting cCat language to English
    for (i = 0; cCat[i] != '\0'; i++) {
        if (cCat[i] == '_') {
            cTranslate[k++] = ' ';
        } else if (cCat[i] >= 65 && cCat[i] <= 90) {
            cTranslate[k++] = cCat[i] + 32;
        } else {
            cTranslate[k++] = cCat[i];
        }
    }
    
    // Displaying English translation of cCat language
    printf("English translation of the given cCat language string:\n%s\n", cTranslate);
    
    return 0;
}