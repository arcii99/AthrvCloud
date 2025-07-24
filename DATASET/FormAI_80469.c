//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the string
#define MAX_LENGTH 100

// Define the struct to store the XML data
typedef struct {
    char name[MAX_LENGTH];
    char value[MAX_LENGTH];
} XMLData;

// Define the function to parse the XML data
void parseXML(char* xml, XMLData* data, int* count) {
    int index = 0;
    int length = strlen(xml);
    int valueStart = 0;
    int valueEnd = 0;
    int dataStart = 0;
    int dataEnd = 0;
    char temp[MAX_LENGTH];

    while (index < length) {
        if (xml[index] == '<') {
            // Start of a new data tag, initialize variables
            valueStart = 0;
            valueEnd = 0;
            dataStart = index + 1;

            // Find the end of the data tag
            while (xml[index] != '>') {
                index++;
            }

            // Calculate the length of the tag name
            int nameLength = index - dataStart;
            strncpy(temp, &xml[dataStart], nameLength);
            temp[nameLength] = '\0';

            // Store the tag name in the data struct
            strcpy(data[*count].name, temp);

            // Check if it is an opening or closing tag
            if (xml[dataStart] != '/') {
                // Find the start and end of the tag value
                valueStart = index + 1;
                while (valueStart < length && xml[valueStart] == ' ') {
                    valueStart++;
                }
                valueEnd = valueStart;
                while (valueEnd < length && xml[valueEnd] != '<') {
                    valueEnd++;
                }

                // Calculate the length of the tag value
                int valueLength = valueEnd - valueStart;
                strncpy(temp, &xml[valueStart], valueLength);
                temp[valueLength] = '\0';

                // Store the tag value in the data struct
                strcpy(data[*count].value, temp);
                (*count)++;
            }
        }

        index++;
    }
}

int main() {
    // Define the XML data string
    char* xml = "<person><name>John Smith</name><age>30</age></person>";

    // Define a struct array to store the XML data
    XMLData data[MAX_LENGTH];

    // Parse the XML data
    int count = 0;
    parseXML(xml, data, &count);

    // Print the parsed data
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", data[i].name, data[i].value);
    }

    return 0;
}