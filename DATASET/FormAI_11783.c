//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_LENGTH 100
#define MAX_ATTRIBS 10
#define MAX_ATTRIB_NAME_LENGTH 50
#define MAX_ATTRIB_VALUE_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_TAG_LENGTH];
    char attribNames[MAX_ATTRIBS][MAX_ATTRIB_NAME_LENGTH];
    char attribValues[MAX_ATTRIBS][MAX_ATTRIB_VALUE_LENGTH];
    char value[MAX_VALUE_LENGTH];
} XmlElement;

int parseXml(char* xmlString, XmlElement* rootElement);
void printXmlElement(XmlElement element);

int main() {
    char* xmlString = "<root><person name=\"John\"><age>25</age></person><person name=\"Jane\"><age>30</age></person></root>";
    XmlElement rootElement;
    parseXml(xmlString, &rootElement);
    printXmlElement(rootElement);
    return 0;
}

int parseXml(char* xmlString, XmlElement* rootElement) {
    int i = 0, j = 0, k = 0;
    int numAttribs = 0, attribNameLength = 0, attribValueLength = 0;
    char tagName[MAX_TAG_LENGTH];
    char attribName[MAX_ATTRIB_NAME_LENGTH];
    char attribValue[MAX_ATTRIB_VALUE_LENGTH];
    char currentValue[MAX_VALUE_LENGTH];
    XmlElement elementStack[100];
    int elementStackTop = -1;
    
    while(xmlString[i] != '\0') {
        // Skip whitespace
        while(isspace(xmlString[i])) {
            i++;
        }
        
        // Check for opening tag
        if(xmlString[i] == '<' && xmlString[i+1] != '/') {
            j = 0;
            i++;
            while(xmlString[i] != '>' && !isspace(xmlString[i])) {
                tagName[j++] = xmlString[i++];
            }
            tagName[j] = '\0';
            if(elementStackTop >= 0) {
                XmlElement currentElement = elementStack[elementStackTop];
                strcpy(rootElement->value, "");
                if(strcmp(currentElement.name, "") == 0) {
                    strcpy(rootElement->name, tagName);
                } else {
                    numAttribs = 0;
                    while(xmlString[i] != '>') {
                        while(isspace(xmlString[i])) {
                            i++;
                        }
                        if(xmlString[i] != '/') {
                            j = 0;
                            while(xmlString[i] != '=' && !isspace(xmlString[i])) {
                                attribName[j++] = xmlString[i++];
                            }
                            attribName[j] = '\0';
                            while(isspace(xmlString[i])) {
                                i++;
                            }
                            if(xmlString[i] == '=') {
                                i++;
                                while(isspace(xmlString[i])) {
                                    i++;
                                }
                                if(xmlString[i] == '\"') {
                                    i++;
                                    j = 0;
                                    while(xmlString[i] != '\"' && j < MAX_ATTRIB_VALUE_LENGTH-1) {
                                        attribValue[j++] = xmlString[i++];
                                    }
                                    attribValue[j] = '\0';
                                    i++;
                                    strcpy(rootElement->attribNames[numAttribs], attribName);
                                    strcpy(rootElement->attribValues[numAttribs], attribValue);
                                    numAttribs++;
                                }
                            }
                        } else {
                            break; 
                        }
                    }
                    while(xmlString[i] != '>') {
                        i++;
                    }
                    i++;
                }
                elementStack[elementStackTop] = *rootElement;
                elementStackTop++;
            } else {
                strcpy(rootElement->name, tagName);
                numAttribs = 0;
                while(xmlString[i] != '>') {
                    while(isspace(xmlString[i])) {
                        i++;
                    }
                    if(xmlString[i] != '/') {
                        j = 0;
                        while(xmlString[i] != '=' && !isspace(xmlString[i])) {
                            attribName[j++] = xmlString[i++];
                        }
                        attribName[j] = '\0';
                        while(isspace(xmlString[i])) {
                            i++;
                        }
                        if(xmlString[i] == '=') {
                            i++;
                            while(isspace(xmlString[i])) {
                                i++;
                            }
                            if(xmlString[i] == '\"') {
                                i++;
                                j = 0;
                                while(xmlString[i] != '\"' && j < MAX_ATTRIB_VALUE_LENGTH-1) {
                                    attribValue[j++] = xmlString[i++];
                                }
                                attribValue[j] = '\0';
                                i++;
                                strcpy(rootElement->attribNames[numAttribs], attribName);
                                strcpy(rootElement->attribValues[numAttribs], attribValue);
                                numAttribs++;
                            }
                        }
                    } else {
                        break;
                    }
                }
                while(xmlString[i] != '>') {
                    i++;
                }
                i++;
                elementStackTop++;
            }
        } else if(xmlString[i] == '<' && xmlString[i+1] == '/') { // Closing tag
            i += 2;
            j = 0;
            while(xmlString[i] != '>') {
                tagName[j++] = xmlString[i++];
            }
            tagName[j] = '\0';
            if(elementStackTop >= 0) {
                XmlElement currentElement = elementStack[elementStackTop];
                if(strcmp(currentElement.name, tagName) == 0) {
                    elementStackTop--;
                    *rootElement = currentElement;
                } else {
                    printf("Error: closing tag '%s' does not match opening tag '%s'\n", tagName, currentElement.name);
                    return 1;
                }
            } else {
                printf("Error: too many closing tags, no matching opening tag for '%s'\n", tagName);
                return 1;
            }
            i++;
        } else { // Element value
            j = 0;
            while(xmlString[i] != '<' && xmlString[i] != '\0') {
                currentValue[j++] = xmlString[i++];
            }
            currentValue[j] = '\0';
            if(elementStackTop >= 0) {
                XmlElement currentElement = elementStack[elementStackTop];
                strcpy(currentElement.value, currentValue);
                elementStack[elementStackTop] = currentElement;
            } else {
                strcpy(rootElement->value, currentValue);
            }
        }
    }
    
    return 0;
}

void printXmlElement(XmlElement element) {
    printf("<%s", element.name);
    int i;
    for(i = 0; i < MAX_ATTRIBS; i++) {
        if(strcmp(element.attribNames[i], "") != 0) {
            printf(" %s=\"%s\"", element.attribNames[i], element.attribValues[i]);
        }
    }
    if(strlen(element.value) == 0 && strlen(element.name) > 0) {
        printf(">\n");
    } else if(strlen(element.value) > 0 && strlen(element.name) > 0) {
        printf(">%s</%s>\n", element.value, element.name);
    } else {
        printf("\n");
    }
}