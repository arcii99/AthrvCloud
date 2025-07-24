//FormAI DATASET v1.0 Category: HTML beautifier ; Style: genious
#include <stdio.h> 

int main() 
{ 
    //Taking user input
    char htmlCode[] = "<html>\n<body>\n<h1>Welcome to Genius CodeFormers</h1>\n</body>\n</html>";

    //Initializing required variables
    int i, j, k=0, depth=0, count=0, length=0;

    length = strlen(htmlCode);

    //Loop for traversing code and indenting
    for(i=0; i<length; i++)
    {
        if(htmlCode[i] == '<')
        {
            count++;

            //Printing tag with indenting
            printf("\n");

            for(j=0; j<depth; j++)
                printf("\t");

            printf("%c", htmlCode[i]);

            k++; 

            //Checking for self closing tags
            if(htmlCode[i+1] == '/')
            {
                k--;
                depth--;
            }
            else if(htmlCode[i+1] == '!')
            {
                k--;
            }
            else
            {
                depth++;
            }
        }
        else if(htmlCode[i] == '>')
        {
            printf("%c\n", htmlCode[i]);

            if(htmlCode[i-1] != '/')
            {
                k++;

                for(j=0; j<depth; j++)
                    printf("\t");
            }
        }
        else
        {
            printf("%c", htmlCode[i]);
        } 
    } 

    return 0; 
}