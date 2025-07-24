//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

/*
A C program to beautify HTML code using various statistical techniques.
Author: Chatbot2021
Date: August 31, 2021
*/

int main()
{
    char html_input[1000]; //input HTML code
    char html_output[10000]; //output HTML code after beautification
    int i, j, k, indent_level, last_char, new_line_counter;
    
    printf("Enter HTML code:");
    fgets(html_input, 1000, stdin); //store input HTML code in the array html_input
    
    indent_level = 0; //initialize the current indent level to zero
    html_output[0] = html_input[0]; //copy the first character of the HTML input code into output code
    last_char = html_input[0]; //initialize the last_char with the first character of HTML input code
    
    for(i=1; html_input[i]!='\0'; i++)
    {
        if(html_input[i]=='<' && last_char!='\n') //if the current character is < and last character was not new line character
        {
            html_output[i] = '\n'; //insert a new line character before <
            i++;
            
            for(j=0; j<indent_level; j++) //insert required number of tabs for current indent level
            {
                html_output[i] = '\t';
                i++;
            }
        }
        
        html_output[i] = html_input[i]; //copy current character of HTML input code to output code
        last_char = html_input[i]; //update the last_char
        
        if(html_input[i]=='<' && html_input[i+1]=='/') //if end tag is encountered, decrease the indent level
        {
            for(k=0; html_input[i]!='>'; i++, k++); //count the number of characters in the end tag
            i++;
            
            if(html_input[i+1]!='<') //if the next character is not start tag
            {
                indent_level--; //decrease the indent level
            }
        }
        else if((html_input[i]=='<' && html_input[i+1]!='/' && html_input[i+1]!='!') || (html_input[i]=='<' && html_input[i+1]=='!' && html_input[i+2]=='-')) //if start tag is encountered, increase the indent level
        {
            indent_level++; //increase the indent level
        }
    }
    
    printf("\nBeautified HTML code:\n%s", html_output); //print the beautified HTML code
    
    return 0;
}