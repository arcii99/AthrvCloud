//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length of element and attribute names */
#define MAX_NAME_LEN 50

/* Define the maximum length of element and attribute values */
#define MAX_VALUE_LEN 200

/* Define the maximum depth of nested elements */
#define MAX_NESTED_DEPTH 10

/* Define the XML tag type */
typedef enum {
    OPEN_TAG,       // <tag>
    CLOSE_TAG,      // </tag>
    SELF_CLOSING    // <tag/>
} TagType;

/* Define the XML tag structure */
typedef struct {
    TagType type;                   // The type of tag
    char name[MAX_NAME_LEN];        // The name of tag
    int num_attributes;             // The number of attributes
    char attributes[MAX_NAME_LEN][MAX_VALUE_LEN];    // The attributes of tag
} XMLTag;

/* Define the XML parser structure */
typedef struct {
    int depth;                      // The current depth of nested elements
    XMLTag nested_tags[MAX_NESTED_DEPTH];    // The nested tags
} XMLParser;

/* Function that parses the XML file */
void parse_XML(FILE* fp) {
    char line[MAX_VALUE_LEN];
    XMLParser parser = {0};

    while (fgets(line, sizeof(line), fp)) {
        /* Remove any newline characters from the line */
        strtok(line, "\n");

        /* Check if the line is an opening tag */
        if (line[0] == '<' && line[1] != '/') {
            /* Create a new tag */
            XMLTag tag = {OPEN_TAG};

            /* Parse the tag name */
            char* token = strtok(line + 1, " ");
            strcpy(tag.name, token);

            /* Parse the tag attributes */
            while ((token = strtok(NULL, " "))) {
                /* Remove any quotes from the attribute value */
                char* value = strtok(strtok(NULL, "\""), "\"");
                strcpy(tag.attributes[tag.num_attributes++], value);
            }

            /* Add the tag to the parser */
            parser.nested_tags[parser.depth++] = tag;
        }
        /* Check if the line is a closing tag */
        else if (line[0] == '<' && line[1] == '/') {
            /* Remove the '/' and '>' characters from the line */
            char* token = strtok(line + 2, ">");

            /* Get the name of the closing tag */
            char name[MAX_NAME_LEN];
            sscanf(token, "%s", name);

            /* Check if the closing tag matches the current tag */
            if (strcmp(name, parser.nested_tags[parser.depth - 1].name) == 0) {
                /* Remove the current tag from the parser */
                parser.depth--;
            }
            else {
                printf("Error: Mismatched tags - %s and %s\n",
                    parser.nested_tags[parser.depth - 1].name, name);
                exit(1);
            }
        }
        /* The line must be an element value */
        else {
            /* Get the current element */
            XMLTag tag = parser.nested_tags[parser.depth - 1];

            /* Print the element value */
            printf("%s: %s\n", tag.name, line);
        }
    }
}

/* Main function */
int main() {
    /* Open the XML file for parsing */
    FILE* fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    /* Parse the XML file */
    parse_XML(fp);

    /* Close the file */
    fclose(fp);

    return 0;
}