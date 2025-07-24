//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Cryptic
/* Cryptic C Cat Language Translator */

#include <stdio.h>

int main() {
    int kitty = 1;
    int meow = 0;
    char purr[100];
    
    printf("Enter a sentence in the C Cat language: ");
    fgets(purr, 100, stdin);
    
    while (purr[meow] != '\0') {
        if (purr[meow] == 'c') {
            if (purr[meow+1] == 'a' && purr[meow+2] == 't') {
                printf("Meow");
                meow += 2;
            } else {
                printf("C");
            }
        } else if (purr[meow] == 'f') {
            if(purr[meow+1] == 'i' && purr[meow+2] == 's' && purr[meow+3] == 'h') {
                printf("Yum");
                meow += 3;
            } else {
                printf("F");
            }
        } else if (purr[meow] == 'b') {
            if(purr[meow+1] == 'i' && purr[meow+2] == 'r' && purr[meow+3] == 'd') {
                printf("Tweet");
                meow += 3;
            } else {
                printf("B");
            }
        } else if (purr[meow] == 'd') {
            if(purr[meow+1] == 'o' && purr[meow+2] == 'g') {
                printf("Woof");
                meow += 2;
            } else {
                printf("D");
            }
        } else {
            printf("%c", purr[meow]);
        }
        meow++;
    }
    
    printf("\nTranslation complete. Thank you for speaking C Cat language!\n\n");
    return 0;
}