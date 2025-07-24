//FormAI DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char html[1000];   
    
    //Input HTML code
    printf("Enter HTML code:\n");
    scanf("%[^\n]s", html);
    
    //Add newline after each '<' or '>'
    for(int i=0; html[i]!='\0'; i++) {
        if(html[i] == '<' || html[i] == '>') {
            printf("%c\n", html[i]);
        } else {
            printf("%c", html[i]);
        }
    }
    
    return 0;
}