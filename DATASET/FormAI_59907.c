//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void parseXML(char xml[]) {
    char temp[MAX_SIZE], tag[MAX_SIZE], value[MAX_SIZE];
    int i = 0, j = 0, k = 0, isTag = 0;

    printf("Parsing xml...\n");
    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            isTag = 1;
            j = i + 1;
        }
        else if (isTag) {
            if (xml[i] == '>') {
                isTag = 0;
                tag[k] = '\0';
                k = 0;
                if (strcmp(tag, "/xml") == 0) {
                    printf("End of xml");
                    return;
                }
                printf("<%s>", tag);
            }
            else if (xml[i] == '=') {
                isTag = 2;
                value[k] = '\0';
                k = 0;
            }
            else if (isTag == 1) {
                tag[k++] = xml[i];
            }
            else if (isTag == 2) {
                value[k++] = xml[i];
            }
        }
        else {
            temp[j++] = xml[i];
        }
        i++;
    }
    temp[j] = '\0';
    printf("%s\n", temp);
}

int main() {
    char xml[MAX_SIZE] = "<xml>\n"
                         "<name>John</name>\n"
                         "<age=27></age>\n"
                         "</xml>";
    parseXML(xml);
    return 0;
}