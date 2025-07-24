//FormAI DATASET v1.0 Category: Syntax parsing ; Style: future-proof
#include <stdio.h>
#include <string.h>

int main() {

    char syntax[50];
    fgets(syntax, 50, stdin);

    int length = strlen(syntax);
    int brackets = 0;
    int quotes = 0;
    int comments = 0;

    for(int i = 0; i < length; i++) {
        if(syntax[i] == '{' || syntax[i] == '}') {
            brackets++;
        } else if(syntax[i] == '\"' || syntax[i] == '\'') {
            quotes++;
            i++;
            while(syntax[i] != '\"' && syntax[i] != '\'') {
                i++;
            }
        } else if(syntax[i] == '/' && syntax[i+1] == '/') {
            comments++;
            break;
        } else if(syntax[i] == '/' && syntax[i+1] == '*') {
            comments++;
            i += 2;
            while(syntax[i] != '*' || syntax[i+1] != '/') {
                i++;
            }
            i++;
        }
    }

    if(brackets % 2 != 0) {
        printf("Error: Uneven brackets\n");
        return 0;
    }

    if(quotes % 2 != 0) {
        printf("Error: Uneven quotes\n");
        return 0;
    }

    if(comments % 2 != 0) {
        printf("Error: Uneven comments\n");
        return 0;
    }

    printf("Syntax Correct\n");
    return 0;

}