//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 1000

//Global variables
char xmlString[MAX_STRING_LENGTH];
int currentIndex = 0;

//Function declarations
void parseXML();

int main()
{
    //Accept user input for XML string
    printf("Enter the XML string:\n");
    fgets(xmlString, MAX_STRING_LENGTH, stdin);

    //Parse the XML string
    parseXML();

    return 0;
}

void parseXML()
{
    //Local variables
    char openElement[MAX_STRING_LENGTH];
    char closeElement[MAX_STRING_LENGTH];
    char data[MAX_STRING_LENGTH];

    //Loop until the end of the XML string is reached
    while(xmlString[currentIndex] != '\0')
    {
        //Check if current element is a starting element
        if(xmlString[currentIndex] == '<' && xmlString[currentIndex+1] != '/')
        {
            //Move the current index to the next character after '<'
            currentIndex++;

            //Extract the opening element name
            int i=0;
            while(xmlString[currentIndex] != '>')
            {
                openElement[i] = xmlString[currentIndex];
                currentIndex++;
                i++;
            }

            //Print the opening element name
            printf("Element name: %s\n", openElement);
        }

        //Check if current element is a ending element
        else if(xmlString[currentIndex] == '<' && xmlString[currentIndex+1] == '/')
        {
            //Move the current index to the next character after '/'
            currentIndex+=2;

            //Extract the closing element name
            int i=0;
            while(xmlString[currentIndex] != '>')
            {
                closeElement[i] = xmlString[currentIndex];
                currentIndex++;
                i++;
            }

            //Print the closing element name
            printf("Element closed: %s\n", closeElement);

            //Check if the opening and closing tags match
            if(strcmp(openElement,closeElement) != 0)
            {
                printf("Error! Opening and closing tags do not match\n");
                exit(EXIT_FAILURE);
            }
        }

        //Check if current element is data
        else if(xmlString[currentIndex] != '<')
        {
            //Extract the data
            int i=0;
            while(xmlString[currentIndex] != '<')
            {
                data[i] = xmlString[currentIndex];
                currentIndex++;
                i++;
            }

            //Print the data
            printf("Data: %s\n", data);
        }

        //Move to the next character
        currentIndex++;
    }
}