//FormAI DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include<stdio.h>

int main() {
    char string[1000], ch;
    int i, j, length;
    
    printf("Enter a string: ");
    scanf("%[^\n]", string);

    length = strlen(string);

    for(i=0; i<length; i++) {
        ch = string[i];

        if(ch == ' ' || ch == '\n' || ch == '\t') {
            continue;
        }

        if(ch != '(' && ch != ')' && ch != '[' && ch != ']' && ch != '{' && ch != '}') {
            printf("Invalid input: %c", ch);
            break;
        }
        
        for(j=i+1; j<length; j++) {
            if(ch == '(' && string[j] == ')') {
                i = j;
                break;
            } else if(ch == '[' && string[j] == ']') {
                i = j;
                break;
            } else if(ch == '{' && string[j] == '}') {
                i = j;
                break;
            } else if(ch == ')' || ch == ']' || ch == '}') {
                printf("Invalid input: %c", ch);
                break;
            }
        }
    }

    if(i == length) {
        printf("Valid input");
    }

    return 0;
}