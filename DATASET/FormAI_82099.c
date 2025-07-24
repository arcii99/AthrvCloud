//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>

int main() {
    char str[1000];
    int i, j, k, len, tabs = 0;

    printf("Enter HTML code: ");
    scanf("%[^\n]s", str);

    len = strlen(str);

    for(i = 0; i < len; i++) {
        //If the current character is '<', print newline and required number of tabs before it
        if(str[i] == '<') {
            printf("\n");
            for(k = 0; k < tabs; k++) {
                printf("\t");
            }
            printf("%c", str[i]);
            //If the next character is '/', decrease the number of tabs to indent the closing tag correctly
            if(str[i+1] == '/') {
                tabs--;
            }
            //Otherwise, increase the number of tabs to indent the nested tags correctly
            else {
                tabs++;
            }
        }
        //If the current character is '>', print it and required number of newlines and tabs after it
        else if(str[i] == '>') {
            printf("%c", str[i]);
            if(str[i-1] == '/') {
                tabs--;
            }
            printf("\n");
            for(j = 0; j < tabs; j++) {
                printf("\t");
            }
        }
        //If the current character is not '<' or '>', simply print it
        else {
            printf("%c", str[i]);
        }
    }

    return 0;
}