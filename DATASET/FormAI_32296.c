//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int length, i, j, vowels = 0;
    printf("Enter a sentence in C Cat Language: ");
    fgets(input, 100, stdin);
    length = strlen(input);

    for(i = 0; i < length; i++) {
        if(input[i] == 'm' && input[i+1] == 'e') {
            printf("The cat says 'You': ");
            i++;
        }
        else if(input[i] == 'h' && input[i+1] == 'i') {
            printf("The cat says 'Hello': ");
            i++;
        }
        else if((input[i] == 'f' && input[i+1] == 'e' && input[i+2] == 'd') || (input[i] == 'h' && input[i+1] == 'u' && input[i+2] == 'n' && input[i+3] == 'g' && input[i+4] == 'r' && input[i+5] == 'y')) {
            printf("The cat says 'I'm hungry': ");
            i+=2;
        }
        else if(input[i] == 'g' && input[i+1] == 'o' && input[i+2] == 'o' && input[i+3] == 'd') {
            printf("The cat says 'Great': ");
            i+=3;
        }
        else if(input[i] == 'b' && input[i+1] == 'a' && input[i+2] == 'd') {
            printf("The cat says 'Terrible': ");
            i+=2;
        }
        else {
            printf("%c", input[i]);
        }
    }
    return 0;
}