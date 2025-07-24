//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
    char c_cat_language[50];
    int i=0;
    
    printf("Enter a sentence in C Cat Language: ");
    gets(c_cat_language); // gets() function is used to read input from the user
    
    printf("\nC Cat Translator Output\n");
    
    while(c_cat_language[i] != '\0') { // '\0' represents the end of a string
        if(c_cat_language[i] == 'c') {
            printf("meow ");
        }
        else if(c_cat_language[i] == 'C') {
            printf("MEOW ");
        }
        else if(c_cat_language[i] == 't') {
            printf("purr ");
        }
        else if(c_cat_language[i] == 'T') {
            printf("PURR ");
        }
        else if(c_cat_language[i] == 'r') {
            printf("meow");
        }
        else if(c_cat_language[i] == 'R') {
            printf("MEOW");
        }
        else if(c_cat_language[i] == 's') {
            printf("hiss ");
        }
        else if(c_cat_language[i] == 'S') {
            printf("HISS ");
        }
        else {
            printf("%c",c_cat_language[i]);
        }
        
        i++;
    }
    
    return 0;
}