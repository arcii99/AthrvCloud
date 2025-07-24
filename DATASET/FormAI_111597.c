//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char c_cat_language[1000];
    int length, i, j;
    
    printf("Enter the C Cat language code to translate into English: ");
    fgets(c_cat_language, sizeof(c_cat_language), stdin);
    
    length = strlen(c_cat_language);
    
    for(i=0; i<length; i++) {
        if(c_cat_language[i] == 'm' && c_cat_language[i+1] == 'e' && c_cat_language[i+2] == 'o') {
            printf("Hello");
            i += 2;
        }
        else if(c_cat_language[i] == 'p' && c_cat_language[i+1] == 'u' && c_cat_language[i+2] == 'r') {
            printf("World");
            i += 2;
        }
        else if(c_cat_language[i] == 'm' && c_cat_language[i+1] == 'i' && c_cat_language[i+2] == 'a' && c_cat_language[i+3] == 'o') {
            printf("Goodbye");
            i += 3;
        }
        else if(c_cat_language[i] == 'n' && c_cat_language[i+1] == 'y' && c_cat_language[i+2] == 'a') {
            printf("Yes");
            i += 2;
        }
        else if(c_cat_language[i] == 'n' && c_cat_language[i+1] == 'o') {
            printf("No");
            i++;
        }
        else {
            printf("%c", c_cat_language[i]);
        }
    }
    
    return 0;
}