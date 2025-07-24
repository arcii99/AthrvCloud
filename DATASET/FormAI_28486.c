//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: expert-level
#include <stdio.h> // for printf, FILE, fopen, fclose
#include <stdlib.h> // for malloc, realloc, free
#include <string.h> // for strcmp, strcpy, strtok

#define BUFF_SIZE 1024 // buffer size for file reading
#define MAX_ATTR 10 // maximum number of attributes supported for a tag

// function to parse XML file
void parseXML(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        return;
    }

    char buffer[BUFF_SIZE];
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int tag_index = 0; // index for storing tags
    int attr_index = 0; // index for storing attributes
    int value_index = 0; // index for storing attribute values
    int i;

    // structure for storing tag information
    typedef struct {
        char* name;
        int num_attr;
        char** attr_names;
        char** attr_values;
    } tagInfo;

    tagInfo* tagArr = (tagInfo*) malloc(sizeof(tagInfo)); // dynamic array for storing tag information

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '<') { // if line contains an XML tag
            if (line[1] == '/') { // if it's a closing tag
                tag_index--; // decrement tag index
                if (attr_index > 0) { // if there were attributes in this tag
                    tagArr[tag_index].num_attr = attr_index; // store total number of attributes
                    tagArr[tag_index].attr_names = (char**) malloc(attr_index * sizeof(char*)); // allocate memory for attribute names
                    tagArr[tag_index].attr_values = (char**) malloc(attr_index * sizeof(char*)); // allocate memory for attribute values
                    for (i = 0; i < attr_index; i++) { // copy attribute names and values to tag structure
                        tagArr[tag_index].attr_names[i] = (char*) malloc(strlen(buffer) * sizeof(char));
                        tagArr[tag_index].attr_values[i] = (char*) malloc(strlen(buffer) * sizeof(char));
                        strcpy(tagArr[tag_index].attr_names[i], strtok(buffer, "=\""));
                        strcpy(tagArr[tag_index].attr_values[i], strtok(NULL, "=\""));
                    }
                }
                attr_index = 0; // reset attribute index
            }
            else { // if it's an opening tag
                tagArr = (tagInfo*) realloc(tagArr, (tag_index + 1) * sizeof(tagInfo)); // allocate memory for new tag
                tagArr[tag_index].name = (char*) malloc((strlen(buffer) - 2) * sizeof(char)); // allocate memory for tag name
                strcpy(tagArr[tag_index].name, strtok(line + 1, ">")); // copy tag name to tag structure
                tag_index++; // increment tag index
            }
        }
        else if (line[0] == '\t' || line[0] == ' ') { // if line contains an attribute
            strcpy(buffer, strtok(line + 1, ">")); // copy attribute to buffer
            if (strcmp(buffer, "") != 0) { // if attribute is not empty
                attr_index++; // increment attribute index
            }
        }
        else { // if line contains tag value
            tagArr[tag_index-1].num_attr = attr_index; // store total number of attributes
            tagArr[tag_index-1].attr_names = (char**) malloc(attr_index * sizeof(char*)); // allocate memory for attribute names
            tagArr[tag_index-1].attr_values = (char**) malloc(attr_index * sizeof(char*)); // allocate memory for attribute values
            for (i = 0; i < attr_index; i++) { // copy attribute names and values to tag structure
                tagArr[tag_index-1].attr_names[i] = (char*) malloc(strlen(buffer) * sizeof(char));
                tagArr[tag_index-1].attr_values[i] = (char*) malloc(strlen(buffer) * sizeof(char));
                strcpy(tagArr[tag_index-1].attr_names[i], strtok(buffer, "=\""));
                strcpy(tagArr[tag_index-1].attr_values[i], strtok(NULL, "=\""));
            }
            tagArr[tag_index-1].num_attr = attr_index; // store total number of attributes
            tagArr[tag_index-1].attr_names = (char**) realloc(tagArr[tag_index-1].attr_names, (attr_index + 1) * sizeof(char*));
            tagArr[tag_index-1].attr_values = (char**) realloc(tagArr[tag_index-1].attr_values, (attr_index + 1) * sizeof(char*));
            tagArr[tag_index-1].attr_names[attr_index] = (char*) malloc(sizeof(char));
            tagArr[tag_index-1].attr_values[attr_index] = (char*) malloc(sizeof(char));
            strcpy(tagArr[tag_index-1].attr_names[attr_index], "");
            strcpy(tagArr[tag_index-1].attr_values[attr_index], strtok(line, "\n"));
            value_index = 0; // reset value index
            attr_index = 0; // reset attribute index
        }
    }

    fclose(fp); // close file

    // print results
    for (i = 0; i < tag_index; i++) {
        printf("Tag %d:\n", i+1);
        printf("Name: %s\n", tagArr[i].name);
        printf("Number of attributes: %d\n", tagArr[i].num_attr);
        for (int j = 0; j < tagArr[i].num_attr; j++) {
            printf("Attribute %d: %s = %s\n", j+1, tagArr[i].attr_names[j], tagArr[i].attr_values[j]);
        }
    }

    // free memory
    for (i = 0; i < tag_index; i++) {
        free(tagArr[i].name);
        for (int j = 0; j < tagArr[i].num_attr; j++) {
            free(tagArr[i].attr_names[j]);
            free(tagArr[i].attr_values[j]);
        }
        free(tagArr[i].attr_names);
        free(tagArr[i].attr_values);
    }
    free(tagArr);

    if (line) {
        free(line);
    }
}

int main() {
    parseXML("sample.xml");
    return 0;
}