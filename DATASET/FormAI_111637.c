//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: standalone
/* 
  This program demonstrates the building of a simple XML parser in C
  The program takes an XML file as input and outputs the contents of the elements contained in it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Structure to hold XML element data */
struct xml_element {
    char *tagname;
    char *contents;
};

/* Function to parse XML tag and its contents and store it in the xml_element struct */
void parse_tag(char *tag, struct xml_element *element) {
    char *tmp = NULL;
    size_t tag_len = 0, contents_len = 0;

    tmp = strchr(tag, '>'); /* Find end of tag */
    tag_len = tmp - tag;
    element->tagname = calloc(tag_len + 1, sizeof(char));
    strncpy(element->tagname, tag + 1, tag_len - 1);

    tmp++; /* Move past tag end */

    contents_len = strlen(tmp) - tag_len - 3; /* Calculate contents length */
    element->contents = calloc(contents_len + 1, sizeof(char));
    strncpy(element->contents, tmp + tag_len + 1, contents_len);
}

int main(int argc, char **argv) {
    FILE *file = NULL;

    char buffer[BUFFER_SIZE] = { 0 };
    char *tmp = NULL;

    struct xml_element current_element = { NULL, NULL };

    if (argc != 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        return -1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file %s\n", argv[1]);
        return -1;
    }

    while (!feof(file)) {
        fgets(buffer, BUFFER_SIZE, file); /* Read a line from the file */

        tmp = strchr(buffer, '<'); /* Find start of tag */
        if (tmp) { /* If tag found */
            parse_tag(tmp, &current_element);
            printf("Tag: %s, Contents: %s\n", current_element.tagname, current_element.contents);

            /* Clean up element memory */
            free(current_element.tagname);
            free(current_element.contents);
            current_element.tagname = NULL;
            current_element.contents = NULL;
        }
    }

    fclose(file);

    return 0;
}