//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse the XML file
void parseXML(char* xmlString) {
    char* openingTag, *closingTag, *openingTagName, *closingTagName;
    char* token;
    const char* DELIMITER = "<>";
    int i = 0;
    
    token = strtok(xmlString, DELIMITER);
    
    while (token != NULL) {
        openingTag = strstr(token, "<");
        closingTag = strstr(token, ">");
        
        // If the token contains an opening tag
        if (openingTag != NULL) {
            openingTagName = strtok(openingTag, " ");
            printf("Opening tag: %s\n", openingTagName + 1); // +1 to skip the '<' character
            
            // Print the attributes of the opening tag
            while (openingTagName != NULL) {
                char* attribute = strtok(NULL, " ");
                if (attribute != NULL) {
                    printf("Attribute: %s\n", attribute);
                }
                openingTagName = strtok(NULL, " ");
            }
        }
        
        // If the token contains a closing tag
        if (closingTag != NULL) {
            closingTagName = strtok(closingTag, " ");
            printf("Closing tag: %s\n", closingTagName + 2); // +2 to skip the '</' characters
        }
        
        // If the token contains data
        if (closingTag == NULL && openingTag == NULL) {
            printf("Data: %s\n", token);
        }
        
        token = strtok(NULL, DELIMITER);
        i++;
    }
}
    
int main() {
    char xmlString[] = "<example attribute1='value1' attribute2='value2'><title>Hello, World!</title><description>This is an example XML file.</description></example>";
    parseXML(xmlString);
    return 0;
}