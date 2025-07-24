//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Welcome to the C Alien Language Translator!\n");
    char alienString[50];
    printf("Please enter the alien language string: ");
    scanf("%s", alienString);

    char cTranslatedString[50];
    int i, j;
    for (i = 0; i < strlen(alienString); i++){
        int count = 1;
        while (alienString[i] == alienString[i+1]){
            count++;
            i++;
        }
        int ascii = alienString[i];
        if (count % 2 == 0){
            ascii = ascii - count;
        }
        else {
            ascii = ascii + count;
        }
        cTranslatedString[j] = ascii;
        j++;
    }

    printf("The translated C string is: %s", cTranslatedString);
    return 0;
}