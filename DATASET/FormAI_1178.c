//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declaring the global variables
char XMLData[200];
char CurrentTag[50], CurrentValue[50], Attribute[50], AttributeValue[50];
int IndexXML, IndexTag, IndexAttribute;

//Function to get the value of a specific attribute for a given tag
char* GetAttributeValue(char* TagName, char* AttrName)
{
    //Setting the default value to NULL
    char* AttrValue = NULL;

    //Checking if the given TagName and AttrName are valid
    if((TagName != NULL) && (AttrName != NULL))
    {
        //Iterating through the XMLData to get the value of the attribute
        for(int i=0; i<strlen(XMLData); i++)
        {
            //Checking if the current character is '<', which denotes the start of a new tag
            if(XMLData[i] == '<')
            {
                //Incrementing the index of the XMLData to skip the '<' character
                i++;
                
                //Checking if the tag name matches the given TagName
                if(strncmp(XMLData+i, TagName, strlen(TagName)) == 0)
                {
                    //Setting the index of the tag name
                    IndexTag = i+strlen(TagName);

                    //Iterating through the tag to find the given attribute name
                    while(XMLData[IndexTag] != '>')
                    {                
                        //Checking if the current character is the start of a new attribute
                        if(XMLData[IndexTag] == ' ')
                        {
                            IndexAttribute = IndexTag+1;

                            //Iterating through the attribute to get the attribute name and value
                            while(XMLData[IndexAttribute] != '=')
                            {
                                Attribute[IndexAttribute-IndexTag-1] = XMLData[IndexAttribute];
                                IndexAttribute++;
                            }
                            Attribute[IndexAttribute-IndexTag-1] = '\0';

                            //Checking if the attribute name matches the given AttrName
                            if(strcmp(Attribute, AttrName) == 0)
                            {
                                //Incrementing the index to get the attribute value
                                IndexAttribute++;

                                //Checking if the attribute value is within double quotes
                                if(XMLData[IndexAttribute] == '"')
                                {
                                    IndexAttribute++;

                                    //Iterating through the attribute value to get the string within double quotes
                                    while(XMLData[IndexAttribute] != '"')
                                    {
                                        AttributeValue[IndexAttribute-IndexTag-strlen(Attribute)-3] = XMLData[IndexAttribute];
                                        IndexAttribute++;
                                    }
                                    AttributeValue[IndexAttribute-IndexTag-strlen(Attribute)-3] = '\0';

                                    //Setting the attribute value to the AttrValue variable
                                    AttrValue = AttributeValue;
                                }
                                //Exiting the loop as the attribute value has been found
                                break;
                            }
                        }
                        IndexTag++;
                    }
                    //Exiting the loop as the tag has been found
                    break;
                }
            }
        }
    }

    //Returning the attribute value
    return AttrValue;
}

int main()
{
    //Initializing the XMLData variable
    strcpy(XMLData, "<person id=\"1\">\n<name>John Doe</name>\n<age>25</age>\n</person>");

    //Parsing the XMLData to get the name and age of the person
    char* Name = GetAttributeValue("person", "name");
    char* Age = GetAttributeValue("person", "age");
    
    //Printing the name and age of the person
    printf("Name: %s\nAge: %s\n", Name, Age);

    return 0;
}