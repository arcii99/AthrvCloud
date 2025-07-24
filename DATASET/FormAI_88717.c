//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: statistical
/* 

XML Parser Example:
In this program, we will parse an XML file and retrieve the values of specified elements.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum length of element names and values
#define MAX_ELEMENT_LENGTH 1000

// Define the maximum number of elements we will process
#define MAX_ELEMENT_COUNT 1000

// Define the maximum length of the input file path
#define MAX_FILE_PATH_LENGTH 1000

// Define the structure to store element name and value information
typedef struct {
    char name[MAX_ELEMENT_LENGTH];
    char value[MAX_ELEMENT_LENGTH];
} Element;

// Parse the XML file and return the specified elements
Element* parseXML(char* filePath, char* elementNames[], int elementCount) {
    
    // Create a new file pointer to read the input file
    FILE* filePointer;
    filePointer = fopen(filePath, "r");

    // If file pointer is null, return null
    if (filePointer == NULL) {
        return NULL;
    }

    // Create a buffer to store each line of the input file
    char lineBuffer[MAX_ELEMENT_LENGTH];

    // Allocate memory for the array to store the specified elements
    Element* elements = (Element*) malloc(sizeof(Element) * elementCount);

    // Initialize a counter to track the number of elements processed
    int elementIndex = 0;

    // Loop through each line of the input file
    while (fgets(lineBuffer, MAX_ELEMENT_LENGTH, filePointer)) {
        
        // Loop through each specified element name
        for (int i = 0; i < elementCount; i++) {

            // Find the element name in the current line
            char* nameStart = strstr(lineBuffer, elementNames[i]);

            // If the name is found, retrieve the value of the element
            if (nameStart != NULL) {
                
                // Find the start and end position of the element value
                char* valueStart = strstr(nameStart, ">") + 1;
                char* valueEnd = strstr(valueStart, "</");

                // Copy the element name and value into the elements array
                strncpy(elements[elementIndex].name, elementNames[i], MAX_ELEMENT_LENGTH - 1);
                strncpy(elements[elementIndex].value, valueStart, valueEnd - valueStart);

                // Increment the element counter and exit the loop
                elementIndex++;
                break;
            }
        }

        // If all specified elements have been found, exit the loop
        if (elementIndex == elementCount) {
            break;
        }
    }

    // Close the input file
    fclose(filePointer);

    // Return the array of elements
    return elements;
}

// Entry point of the application
int main() {

    // Define the file path and specified element names
    char filePath[MAX_FILE_PATH_LENGTH] = "sample.xml";
    char* elementNames[] = { "name", "age", "gender" };
    int elementCount = sizeof(elementNames) / sizeof(char*);

    // Parse the XML file and retrieve the specified elements
    Element* elements = parseXML(filePath, elementNames, elementCount);

    // Loop through each element and print the name and value
    for (int i = 0; i < elementCount; i++) {
        printf("%s: %s\n", elements[i].name, elements[i].value);
    }

    // Free the memory allocated for the array of elements
    free(elements);

    return 0;
}