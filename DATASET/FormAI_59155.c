//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>

/* Function to translate C Cat Language to English */
char* translateCat(char* sentence){
    char* translation = "";
    int length = strlen(sentence);
    int i;
    for(i=0;i<length;i++){
        switch(sentence[i]){
            case 'P': translation = strcat(translation,"Please ");
                      break;
            case 'G': translation = strcat(translation,"give ");
                      break;
            case 'M': translation = strcat(translation,"me ");
                      break;
            case 'T': translation = strcat(translation,"a ");
                      break;
            case 'F': translation = strcat(translation,"fish ");
                      break;
            case 'H': translation = strcat(translation,"house ");
                      break;
            case 'E': translation = strcat(translation,"every ");
                      break;
            case 'S': translation = strcat(translation,"single ");
                      break;
            case 'D': translation = strcat(translation,"day. ");
                      break;
            default: break;
        }
    }
    return translation;
}

int main() {
    /* sample C Cat Language sentence */
    char* sentence = "PGMTFPMTFPDT";
    char* translation = translateCat(sentence);
    printf("%s",translation);
    return 0;
}