//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MetaData {
    char name[50];
    char value[100];
} tags[10];

void extractMetadata(char line[]) {
    char *token;
    char *delimiter = ":";
    int index = 0;

    token = strtok(line, delimiter);

    while(token != NULL) {
        if(index == 0) {
            strcpy(tags[index].name, token);
        } else {
            strcpy(tags[index].value, token);
        }
        token = strtok(NULL, delimiter);
        index++;
    }
}

void displayMetaData() {
    printf("\nMetadata Information:\n");
    for(int i=0; i<10 && tags[i].name[0]!='\0'; i++) {
        printf("%s: %s\n", tags[i].name, tags[i].value);
    }
}

int main() {
    FILE *fp;
    char line[100];

    fp = fopen("sample.txt", "r");

    if(fp == NULL) {
        printf("File not found!");
        exit(1);
    }

    while(fgets(line, 100, fp) != NULL) {
        if(strstr(line, "<metadata>") != NULL) {
            fgets(line, 100, fp); // skip <metadata> line
            while(strstr(line, "</metadata>") == NULL) {
                extractMetadata(line);
                fgets(line, 100, fp);
            }
            break;
        }
    }

    displayMetaData();

    return 0;
}