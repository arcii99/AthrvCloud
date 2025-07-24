//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: modular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_BUFFER_SIZE 1024

//Struct represents XML tag
typedef struct XMLtag {
    char* tagName;
    struct Attributes* attributeList;
    struct XMLtag* childList;
    char* text;
} XMLtag;

//Struct represents XML attribute
typedef struct Attribute {
    char* name;
    char* value;
    struct Attribute* next;
} Attribute;

//Function to parse XML string and return the root tag
XMLtag* parseXML(char* xmlString);

//Function to create new XML tag
XMLtag* createXMLtag(char* tagName, Attribute* attributeList, char* text, XMLtag* childList);

//Function to create new XML attribute
Attribute* createAttribute(char* attributeName, char* attributeValue);

//Function to print XML tag
void printXMLtag(XMLtag* tag);

//Function to print XML attribute
void printAttribute(Attribute* attr);

//Driver code
int main() {

    //Sample XML String
    char xmlString[MAX_BUFFER_SIZE] = "<person name=\"John\"><age>28</age><occupation>Software Engineer</occupation></person>";

    //Parse the xml string
    XMLtag* rootTag = parseXML(xmlString);

    //Print the root tag
    printXMLtag(rootTag);

    return 0;
}

//Function to parse the XML string recursively and return root tag
XMLtag* parseXML(char* xmlString) {
    int length = strlen(xmlString);
    int i = 0;

    //Skip until the first opening tag
    while (xmlString[i] != '<' && i < length) {
        i++;
    }

    //Find the tag name
    char* tagName = (char*)malloc(MAX_BUFFER_SIZE);
    int j = i + 1;
    while (xmlString[j] != ' ' && xmlString[j] != '>' && j < length) {
        tagName[j - i - 1] = xmlString[j];
        j++;
    }
    tagName[j - i - 1] = '\0';

    //Find the attributes
    Attribute* attributeList = NULL;
    while (xmlString[j] != '>' && j < length) {
        char* attributeName = (char*)malloc(MAX_BUFFER_SIZE);
        char* attributeValue = (char*)malloc(MAX_BUFFER_SIZE);

        while (xmlString[j] != '=' && xmlString[j] != '>' && j < length) {
            j++;
        }

        if (xmlString[j] == '>') {
            break;
        }

        j++;

        //Extract the attribute name
        int k = 0;
        while (xmlString[j] != '=' && j < length) {
            attributeName[k++] = xmlString[j++];
        }
        attributeName[k] = '\0';

        j++;

        //Extract the attribute value
        k = 0;
        while (xmlString[j] != '\"' && j < length) {
            j++;
        }

        j++;
        while (xmlString[j] != '\"' && j < length) {
            attributeValue[k++] = xmlString[j++];
        }
        attributeValue[k] = '\0';

        Attribute* newAttribute = createAttribute(attributeName, attributeValue);
        if (attributeList == NULL) {
            attributeList = newAttribute;
        }
        else {
            Attribute* temp = attributeList;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newAttribute;
        }
        j++;
    }

    j++;

    //Find the text
    char* text = (char*)malloc(MAX_BUFFER_SIZE);
    int k = 0;
    while (xmlString[j] != '<' && j < length) {
        text[k++] = xmlString[j++];
    }
    text[k] = '\0';

    //Find the child tags
    XMLtag* childList = NULL;
    int nestedTagCounter = 0;
    int start = j;
    int end = -1;

    while (j < length) {
        if (xmlString[j] == '<') {
            if (xmlString[j + 1] == '/') {
                //End tag
                if (nestedTagCounter == 0) {
                    end = j - 1;
                    break;
                }
                else {
                    nestedTagCounter--;
                    j++;
                }
            }
            else {
                //Start tag
                if (nestedTagCounter == 0) {
                    end = j - 1;

                    char* childXMLstring = (char*)malloc(MAX_BUFFER_SIZE);
                    strncpy(childXMLstring, &xmlString[start], end - start + 1);
                    childXMLstring[end - start + 1] = '\0';
                    XMLtag* childTag = parseXML(childXMLstring);

                    if (childList == NULL) {
                        childList = childTag;
                    }
                    else {
                        XMLtag* temp = childList;
                        while (temp->childList != NULL) {
                            temp = temp->childList;
                        }
                        temp->childList = childTag;
                    }
                    start = j;
                    nestedTagCounter++;
                }
                else {
                    nestedTagCounter++;
                }
                j++;
            }
        }
        else {
            j++;
        }
    }

    //Create the tag
    char* tagText = NULL;
    if (end != -1) {
        tagText = (char*)malloc(MAX_BUFFER_SIZE);
        strncpy(tagText, &xmlString[start], end - start + 1);
        tagText[end - start + 1] = '\0';
    }
    else {
        tagText = (char*)malloc(strlen(text) + 1);
        strcpy(tagText, text);
    }

    XMLtag* tag = createXMLtag(tagName, attributeList, tagText, childList);
    return tag;
}

//Function to create new XML tag
XMLtag* createXMLtag(char* tagName, Attribute* attributeList, char* text, XMLtag* childList) {
    XMLtag* tag = (XMLtag*)malloc(sizeof(XMLtag));
    tag->tagName = (char*)malloc(strlen(tagName) + 1);
    strcpy(tag->tagName, tagName);
    tag->attributeList = attributeList;
    tag->childList = childList;
    tag->text = (char*)malloc(strlen(text) + 1);
    strcpy(tag->text, text);
    return tag;
}

//Function to create new XML attribute
Attribute* createAttribute(char* attributeName, char* attributeValue) {
    Attribute* attribute = (Attribute*)malloc(sizeof(Attribute));
    attribute->name = (char*)malloc(strlen(attributeName) + 1);
    strcpy(attribute->name, attributeName);
    attribute->value = (char*)malloc(strlen(attributeValue) + 1);
    strcpy(attribute->value, attributeValue);
    attribute->next = NULL;
    return attribute;
}

//Function to print XML tag
void printXMLtag(XMLtag* tag) {
    printf("<%s ", tag->tagName);
    Attribute* tempAttr = tag->attributeList;
    while (tempAttr != NULL) {
        printAttribute(tempAttr);
        tempAttr = tempAttr->next;
    }
    printf(">");

    if (tag->childList == NULL) {
        printf("%s", tag->text);
    }
    else {
        printf("\n");
        XMLtag* tempTag = tag->childList;
        while (tempTag != NULL) {
            printXMLtag(tempTag);
            tempTag = tempTag->childList;
        }
        printf("\n");
    }

    printf("</%s>\n", tag->tagName);
}

//Function to print XML attribute
void printAttribute(Attribute* attr) {
    printf("%s=\"%s\" ", attr->name, attr->value);
}