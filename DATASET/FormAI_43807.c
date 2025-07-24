//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {

    // Sample XML to be parsed
    char xml[] = "<person>"
                 "<name>John Doe</name>"
                 "<age>25</age>"
                 "<email>john.doe@gmail.com</email>"
                 "</person>";

    // Define variables used for parsing the XML
    char tag[20], content[50];
    int i, j;
    int in_tag = 0, in_content = 0;

    // Loop through each character in the XML
    for (i = 0; i < strlen(xml); i++) {

        // Check if we are inside a tag
        if (xml[i] == '<') {
            in_tag = 1;
            j = 0; // reset content index
        }

        // Check if we are inside content
        if (in_tag == 0) {
            content[j] = xml[i];
            j++;
        }

        // Check if we are closing a tag
        if (xml[i] == '>') {
            in_tag = 0;
            content[j] = '\0'; // add null terminator to content
            printf("Tag: %s, Content: %s\n", tag, content);
            memset(tag, 0, sizeof(tag));       // reset tag array
            memset(content, 0, sizeof(content)); // reset content array
            j = 0; // reset content index
        }

        // Copy characters to tag array
        if (in_tag == 1 && xml[i] != '<' && xml[i] != '>') {
            tag[j] = xml[i];
            j++;
        }
    }

    return 0;
}