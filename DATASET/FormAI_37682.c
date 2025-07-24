//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

int main()
{
    char cat_language[1000], c;
    int i, j;
    
    printf("Enter the sentence in C Cat Language: ");
    
    // reading C Cat Language input from user
    i = 0;
    while ((c = getchar()) != '\n') {
        cat_language[i] = c;
        i++;
    }
    cat_language[i] = '\0';
    
    // converting C Cat Language to English Language
    i = 0;
    while (cat_language[i] != '\0') {
        switch (cat_language[i]) {
            case 'm':
                if (cat_language[i+1] == 'e') {
                    printf("I ");
                    i++;
                } else if (cat_language[i+1] == 'y'){
                    printf("You ");
                    i++;
                } else if (cat_language[i+1] == 'a'){
                    printf("They ");
                    i++;
                }
                break;
            case 'h':
                if (cat_language[i+1] == 'i') {
                    printf("like ");
                    i++;
                } else if (cat_language[i+1] == 'e' && cat_language[i+2] == 'r') {
                    printf("milk ");
                    i += 2;
                }
                break;
            case 'p':
                if (cat_language[i+1] == 'u' && cat_language[i+2] == 'r') {
                    printf("food ");
                    i += 2;
                } else if (cat_language[i+1] == 'a' && cat_language[i+2] == 't') {
                    printf("sleep ");
                    i += 2;
                }
                break;
            case 'c':
                if (cat_language[i+1] == 'h' && cat_language[i+2] == 'a') {
                    printf("run ");
                    i += 2;
                } else if (cat_language[i+1] == 'e' && cat_language[i+2] == 'c') {
                    printf("fish ");
                    i += 2;
                }
                break;
        }
        i++;
    }
    
    printf("\n");
    return 0;
}