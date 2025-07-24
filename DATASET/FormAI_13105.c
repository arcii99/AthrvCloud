//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to parse the XML
void parseXML(char* xml) {

    printf("\nThe parsed XML is:\n");

    char *buffer = malloc(strlen(xml) + 1);
    char *key = malloc(strlen(xml) + 1);
    char *value = malloc(strlen(xml) + 1);

    buffer = xml;

    while (*buffer != '\0') {
        if (*buffer == '<') {
            buffer++;
            if (*buffer == '/') {
                buffer++;
            }
            while (*buffer != '>') {
                *key++ = *buffer++;
            }
            *key = '\0';
            printf("<%s>", key);
            key = strchr(buffer, '\"') + 1;
            buffer += strlen(key) + 1;
            value = strchr(key, '\"');
            *value = '\0';
            printf("%s\n", key);
        } else {
            buffer++;
        }
    }

    free(buffer);
    free(key);
    free(value);
}

//Main method
int main() {
    char xml[] = "<employees>"
                 "<employee id=\"1\" name=\"Sherlock Holmes\"/>"
                 "<employee id=\"2\" name=\"Dr. Watson\"/>"
                 "</employees>";
    parseXML(xml);

    return 0;
}