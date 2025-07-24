//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our XML Parser function
void parseXML(char* content) {
    char* startTag = NULL;
    char* endTag = NULL;
    char* tagContent = NULL;
    
    // Find start and end tags
    startTag = strstr(content, "<");
    while (startTag != NULL) {
        endTag = strstr(startTag, ">");
        
        if (endTag == NULL) {
            printf("Error: Invalid XML format");
            return;
        }
        
        // Extract tag content
        tagContent = (char*)malloc(sizeof(char) * (endTag - startTag - 1));
        memcpy(tagContent, startTag + 1, endTag - startTag - 1);
        tagContent[endTag - startTag - 1] = '\0';
        
        // Print tag content
        printf("%s\n", tagContent);
        
        // Free memory
        free(tagContent);
        
        // Find next start tag
        startTag = strstr(endTag, "<");
    }
}

int main() {
    char* xmlContent = "<root><person><name>John</name><age>30</age></person></root>";
    
    parseXML(xmlContent);
    
    return 0;
}