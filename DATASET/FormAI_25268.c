//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char* translate(char str[]) {
    char* result = (char* )malloc(strlen(str)*3+1);

    int i=0,j=0;
    while(str[i]) {
        if(isalpha(str[i])) {
            if(str[i]>='a' && str[i]<='z') {
                result[j++] = 'c';
                result[j++] = toupper(str[i++]);
                result[j++] = 'c';
            }
            else {
                result[j++] = str[i++];
            }
        }
        else {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char str[100];
    printf("Enter a sentence to translate in C Cat Language:\n");
    fgets(str, 100, stdin);
    
    char* translated_str = translate(str);
    printf("Translated sentence: %s", translated_str);

    free(translated_str);
    return 0;
}