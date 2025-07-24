//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: random
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parseXML(char *xml) {
    char buffer[BUFFER_SIZE];
    int i = 0, j = 0;
    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            i++;
            while (xml[i] != '>') {
                buffer[j] = xml[i];
                i++;
                j++;
            }
            buffer[j] = '\0';
            printf("%s\n", buffer);
            j = 0;
        }
        i++;
    }
}

int main() {
    char xml[BUFFER_SIZE] = "<root><name>John</name><age>25</age><gender>Male</gender></root>";
    parseXML(xml);
    return 0;
}