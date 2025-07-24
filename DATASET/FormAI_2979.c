//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <string.h>

char translationTable[30][2] = {{'a', 'b'}, {'b', 'c'}, {'c', 'd'}, {'d', 'e'}, {'e', 'f'}, {'f', 'g'}, {'g', 'h'}, {'h', 'i'}, {'i', 'j'}, {'j', 'k'}, {'k', 'l'}, {'l', 'm'}, {'m', 'n'}, {'n', 'o'}, {'o', 'p'}, {'p', 'q'}, {'q', 'r'}, {'r', 's'}, {'s', 't'}, {'t', 'u'}, {'u', 'v'}, {'v', 'w'}, {'w', 'x'}, {'x', 'y'}, {'y', 'z'}, {'z', 'a'}, {' ', ' '}, {'\n', '\n'}, {'\t', '\t'}};

void translate(char* input) {
    int length = strlen(input);
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < 30; j++) {
            if(input[i] == translationTable[j][0]) {
                printf("%c", translationTable[j][1]);
                break;
            }
        }
    }
}

int main() {
    printf("Enter the text to translate\n");
  
    while(1) {
        char input[100];
        fgets(input, 100, stdin);
        printf("\nTranslated text: ");
        translate(input);
        printf("\n");
    }

    return 0;
}