//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    char element_name[50];
    char element_data[200];
} xml_element_t;

void *parse_xml(void *filename);

int main(int argc, char **argv) {

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, parse_xml, "example1.xml");
    pthread_create(&thread2, NULL, parse_xml, "example2.xml");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;

}

void *parse_xml(void *filename) {

    FILE *xml_file;
    xml_file = fopen(filename, "r");

    if(xml_file == NULL) {
        printf("Error opening file %s.\n", filename);
        pthread_exit(NULL);
    }

    char line[256];
    memset(line, 0, sizeof(line));

    xml_element_t element;
    memset(&element, 0, sizeof(xml_element_t));

    while(fgets(line, sizeof(line), xml_file)) {
        char *tag_open = strchr(line, '<');
        if(tag_open == NULL) continue;

        char *tag_close = strchr(tag_open, '>');
        if(tag_close == NULL) continue;
        *tag_close++ = '\0';

        char *space = strchr(tag_open, ' ');
        if(space != NULL && space < tag_close) {
            // Start tag with attributes
            int len = space - tag_open - 1;
            strncpy(element.element_name, tag_open + 1, len);
            element.element_name[len] = '\0';

            char *attr = space + 1;
            char *attr_close = strchr(attr, '>');
            if(attr_close != NULL) {
                *attr_close = '\0';
                strcpy(element.element_data, attr);
            }
        } else {
            // Start or end tag without attributes
            if(tag_open[1] == '/') {
                printf("%s: %s\n", filename, element.element_data);
                memset(&element, 0, sizeof(xml_element_t));
            } else {
                strcpy(element.element_name, tag_open+1);
            }
        }
    }

    fclose(xml_file);
    pthread_exit(NULL);
}