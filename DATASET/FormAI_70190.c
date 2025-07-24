//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_TAG_SIZE 50

// Structure to hold tag attributes
typedef struct tag_attribute {
    char name[MAX_TAG_SIZE];
    char value[MAX_LINE_SIZE - MAX_TAG_SIZE - 4]; // -4 for the quotes and equal sign
} tag_attribute;

// Structure to hold the parsed XML content
typedef struct xml_content {
    char tag_name[MAX_TAG_SIZE];
    tag_attribute attributes[10]; // Assuming each tag can have up to 10 attributes
    int num_attributes;
    char content[MAX_LINE_SIZE];
} xml_content;

// Structure to hold the thread parameters
typedef struct thread_params {
    char* file_path;
    xml_content* content;
} thread_params;

// Function to parse a line and extract the tag name, attributes and content
void parse_line(char* line, xml_content* content) {
    char* token = strtok(line, "<>");
    int pos = 0;

    while (token != NULL) {
        // Ignore whitespace and comment lines
        if (strcmp(token, "\n") == 0 || strcmp(token, "\r") == 0 || strstr(token, "<!--") != NULL || strstr(token, "-->") != NULL) {
            token = strtok(NULL, "<>");
            continue;
        }

        // Extract tag name
        if (token[0] == '<' && token[1] != '/') {
            strcpy(content->tag_name, &token[1]);
            pos = strlen(token) - 1;
            if (token[pos] == '>') {
                token = strtok(NULL, "<>");
                continue;
            }
        }

        // Extract attributes
        if (token[0] != '<') {
            char* delimiter = strstr(token, "=");
            if (delimiter != NULL) {
                char attr_name[MAX_TAG_SIZE];
                strcpy(attr_name, token);
                attr_name[strlen(attr_name) - 1] = '\0'; // Remove the trailing space
                strcpy(content->attributes[content->num_attributes].name, attr_name);
                strcpy(content->attributes[content->num_attributes].value, delimiter + 2);
                content->num_attributes++;
                pos = strlen(token) - 1;
                if (token[pos] == '>') {
                    token = strtok(NULL, "<>");
                    continue;
                }
            }
        }

        // Extract content
        if (token[0] != '<' && strlen(token) > 0) {
            if (content->content[0] == '\0') {
                strcpy(content->content, token);
            } else {
                strcat(content->content, " ");
                strcat(content->content, token);
            }
            pos = strlen(token) - 1;
            if (token[pos] == '>') {
                token = strtok(NULL, "<>");
                continue;
            }
        }

        // End tag
        if (token[0] == '<' && token[1] == '/') {
            break;
        }

        token = strtok(NULL, "<>");
    }
}

// Thread function to parse the given file and extract the XML content
void* parse_file(void* params) {
    thread_params* p = (thread_params*)params;

    FILE* fp = fopen(p->file_path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        xml_content content;
        memset(&content, 0, sizeof(xml_content));

        parse_line(line, &content);

        if (content.tag_name[0] != '\0') {
            memcpy(p->content, &content, sizeof(xml_content));
            break;
        }
    }

    fclose(fp);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    thread_params params[5];

    char* file_paths[5] = {"file1.xml", "file2.xml", "file3.xml", "file4.xml", "file5.xml"};
    xml_content contents[5];

    for (int i = 0; i < 5; i++) {
        memset(&contents[i], 0, sizeof(xml_content));
        params[i].file_path = file_paths[i];
        params[i].content = &contents[i];
        pthread_create(&threads[i], NULL, parse_file, &params[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
        printf("Tag name: %s\n", contents[i].tag_name);
        printf("Number of attributes: %d\n", contents[i].num_attributes);
        for (int j = 0; j < contents[i].num_attributes; j++) {
            printf("Attribute %d: %s=%s\n", j+1, contents[i].attributes[j].name, contents[i].attributes[j].value);
        }
        printf("Content: %s\n", contents[i].content);
        printf("\n");
    }

    return 0;
}