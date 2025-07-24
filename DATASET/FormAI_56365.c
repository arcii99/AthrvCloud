//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include<stdio.h>

/*function that beautifies the HTML code*/
void beautify(char* str) {

    int i, j, k;
    int tagFlag = 0;
    int indentFlag = 0;
    int indentLevel = 0;
    
    /*loop through each character in the string*/
    for(i=0; str[i] != '\0'; i++) {
        
        /*check for start of a tag*/
        if(str[i] == '<') {
            printf("\n");
            indentFlag = 1;
            tagFlag = 1;
        }
        
        /*print the character*/
        printf("%c", str[i]);

        /*check for end of a tag*/
        if(str[i] == '>') {
            printf("\n");
            tagFlag = 0;
        }
        
        /*check if indent flag is on*/
        if(indentFlag == 1) {
            indentLevel++;
            for(k=0; k<indentLevel; k++) {
                printf("\t");
            }
            indentFlag = 0;
        }
        
        /*check for end tag*/
        if(str[i] == '/' && tagFlag == 1) {
            indentLevel--;
            printf("\n");
            for(k=0; k<indentLevel; k++) {
                printf("\t");
            }
        }
    }
}

/*main function to test*/
int main() {
    char html_str[] = "<html><head><title>Test Page</title></head><body><h1>Welcome</h1><p>This is a sample page.</p></body></html>";
    beautify(html_str);
    return 0;
}