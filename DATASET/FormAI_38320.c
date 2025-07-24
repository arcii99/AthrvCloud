//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to trim whitespace characters from both ends of a string
char* trim(char* str){
    char* end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0) return str;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
    return str;
}

// Function to beautify HTML code
char* beautifyHtml(char* htmlCode){
    char* beautifiedCode = malloc(strlen(htmlCode) + 1);
    int indentLevel = 0;
    int previousIndentLevel = 0;
    char* token = strtok(htmlCode, "\n");
    while(token != NULL){
        char* trimmedToken = trim(token);
        previousIndentLevel = indentLevel;
        if(strncmp(trimmedToken, "</", 2) == 0) indentLevel--;
        for(int i = 0; i < indentLevel; i++) strcat(beautifiedCode, "    ");
        strcat(beautifiedCode, trimmedToken);
        strcat(beautifiedCode, "\n");
        if(strncmp(trimmedToken, "<", 1) == 0 && strncmp(trimmedToken + 1, "/", 1) != 0 && strncmp(trimmedToken + strlen(trimmedToken) - 2, "/>", 2) != 0) indentLevel++;
        token = strtok(NULL, "\n");
    }
    free(htmlCode);
    return beautifiedCode;
}

int main(){
    char* htmlCode = "<html>\n<head>\n<title>My Website</title>\n</head>\n<body>\n<h1>Welcome to my website!</h1>\n<p>Please enjoy your stay.</p>\n</body>\n</html>";
    char* beautifiedCode = beautifyHtml(htmlCode);
    printf("%s", beautifiedCode);
    free(beautifiedCode);
    return 0;
}