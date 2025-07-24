//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: mind-bending
#include<stdio.h>
#include<string.h>

// Function to convert C Cat language to English
void convertCcat(char input[100])
{
    char output[100];
    
    // Initialize variables
    int i=0, j=0;
    int len = strlen(input);
    int count=0;
    int flag=0;
    
    // Loop through the input string
    for(i=0;i<len;i++)
    {
        // Check for keyword "meow"
        if(input[i]=='m' && input[i+1]=='e' && input[i+2]=='o' && input[i+3]=='w')
        {
            // If "meow" found, replace with "printf("
            output[j++]='p';
            output[j++]='r';
            output[j++]='i';
            output[j++]='n';
            output[j++]='t';
            output[j++]='f';
            output[j++]='(';
            i+=3;
            flag=1;
        }
        // Check for '+' operator
        else if(input[i]=='+')
        {
            // If '+' found, replace with ','
            output[j++]=',';
            flag=1;
        }
        // Check for '-' operator
        else if(input[i]=='-')
        {
            // If '-' found, replace with ')'
            output[j++]=')';
            flag=1;
        }
        // Check for '=' operator
        else if(input[i]=='=' && input[i+1]=='=')
        {
            // If '==' found, replace with '=='
            output[j++]='=';
            output[j++]='=';
            i++;
            flag=1;
        }
        // Check for '!' operator
        else if(input[i]=='!')
        {
            // If '!' found, replace with '!='
            output[j++]='!';
            output[j++]='=';
            flag=1;
        }
        // Check for variable name
        else if(input[i]>='a' && input[i]<='z')
        {
            // If variable found, replace with variable name in English
            if(flag==1)
            {
                output[j++]=',';
                count++;
                flag=0;
            }
            if(count>0)
            {
                output[j++]='\'';
                output[j++]=',';
                output[j++]=' ';
            }
            count=0;
            output[j++]=toupper(input[i]);
            i++;
            while(input[i]!='\n')
            {
                output[j++]=input[i];
                i++;
            }
            i--;
        }
        // Check for end of line
        else if(input[i]=='\n')
        {
            // If end of line found, add ');' to end of line
            output[j++]=')';
            output[j++]=')';
            output[j++]=';';
            output[j++]='\n';
            flag=0;
            count=0;
        }
        else
        {
            // If none of the above conditions are met, copy the input character to output
            output[j++]=input[i];
        }
    }
    // Print the output string
    printf("%s", output);
}


int main()
{
    // Variable to store input string
    char input[100];
    
    // Ask user for C Cat code input
    printf("Welcome to the C Cat Translator program!\n");
    printf("Please enter your C Cat code:\n");
    fgets(input, 100, stdin);
    
    // Convert C Cat code to English and print output
    convertCcat(input);
    
    // Exit program
    printf("Translation successfull! Goodbye!\n");
    return 0;
}