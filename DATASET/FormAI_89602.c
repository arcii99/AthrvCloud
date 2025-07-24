//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to check if a character is an HTML tag
int isTag(char c) 
{
    if(c == '<' || c == '>') 
    {
        return 1;
    }
    return 0;
}

// Beautification function
void beautifyHTML(char* input) 
{
    int indentLevel = 0;
    int i = 0;
    int length = strlen(input);

    // loop through the input string
    while(i < length) 
    {
        if(input[i] == '<') 
        {
            //check for closing tag
            if(input[i+1] == '/') 
            {
                indentLevel--;
            }

            //print current indentation level
            for(int j = 0; j < indentLevel; j++) 
            {
                printf("\t");
            }
            //print tag
            printf("%c", input[i]);

            //check for opening tag
            if(input[i+1] != '/') 
            {
                indentLevel++;
            }
        } 
        else if(input[i] == '>') 
        {
            printf("%c\n", input[i]);
        } 
        else 
        {
            // check if character is part of a tag
            if(isTag(input[i-1]) && !isTag(input[i+1])) 
            {
                //print space after opening tag
                printf("%c ", input[i]);
            }
            else if(!isTag(input[i-1]) && isTag(input[i+1])) 
            {
                //print space before closing tag
                printf("%c ", input[i]);
            }
            else 
            {
                //print character
                printf("%c", input[i]);   
            }
        }
        i++;
    }
}

int main() 
{
    char input[] = "<html>\n\t<head>\n\t\t<title>My Website</title>\n\t</head>\n\t<body>\n\t\t<h1>Welcome to my website!</h1>\n\t\t<p>Some text goes here...</p>\n\t</body>\n</html>";
    beautifyHTML(input); //call beautification function

    return 0;
}