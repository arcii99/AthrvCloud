//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: visionary
#include <stdio.h>
#include <string.h>

//Function to translate input string from C Cat language to English
void catTranslator(char ccat[]) {
    int index = 0;
    char translation[1000] = "";

    while (ccat[index] != '\0') {
        //Check for specific C Cat keywords and translate accordingly
        if (ccat[index] == 'i' && ccat[index+1] == 'f') {
            strcat(translation, "If");
            index += 2;
        } else if (ccat[index] == 'e' && ccat[index+1] == 'l' && ccat[index+2] == 's' && ccat[index+3] == 'e') {
            strcat(translation, "Else");
            index += 4;
        } else if (ccat[index] == 'w' && ccat[index+1] == 'h' && ccat[index+2] == 'i' && ccat[index+3] == 'l' && ccat[index+4] == 'e') {
            strcat(translation, "While");
            index += 5;
        } else if (ccat[index] == 'f' && ccat[index+1] == 'o' && ccat[index+2] == 'r') {
            strcat(translation, "For");
            index += 3;
        } else if (ccat[index] == 'r' && ccat[index+1] == 'e' && ccat[index+2] == 't' && ccat[index+3] == 'u' && ccat[index+4] == 'r' && ccat[index+5] == 'n') {
            strcat(translation, "Return");
            index += 6;
        } else {
            //If not a keyword, just add the character to the translation
            strncat(translation, &ccat[index], 1);
            index++;
        }
    }
    //Print the final translation
    printf("%s", translation);
}

int main() {
    char ccat[1000];

    //Get input string from user
    printf("Enter C Cat code to be translated: ");
    fgets(ccat, 1000, stdin);

    //Call the translation function
    printf("Translated code: ");
    catTranslator(ccat);
    return 0;
}