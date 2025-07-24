//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include<stdio.h>
#include<string.h>

void indent(int level) {
    int i;
    for (i=0; i<level; i++) {
        printf("  "); // Two spaces
    }
}

void print_element(char* tag_name, int level) {
    indent(level);
    printf("<%s>\n", tag_name);
}

void print_text(char* text, int level) {
    indent(level);
    printf("%s\n", text);
}

void print_close_element(char* tag_name, int level) {
    indent(level);
    printf("</%s>\n", tag_name);
}

int main() {
    char input[] = "<html><head><title>Title</title></head><body><h1>Heading</h1><p>Paragraph</p></body></html>";
    int input_length = strlen(input);

    int level = 0;
    int i = 0;
    while (i < input_length) {
        if (input[i] == '<') {
            i++; // Move past <
            if (input[i] != '/') { // Opening tag
                int tag_start = i;
                while (input[i] != '>') {
                    i++;
                }
                int tag_end = i;
                char tag_name[tag_end - tag_start + 1];
                memcpy(tag_name, input + tag_start, tag_end - tag_start);
                tag_name[tag_end - tag_start] = '\0';
                print_element(tag_name, level);
                level++;
            }
            else { // Closing tag
                int tag_start = i + 1;
                while (input[i] != '>') {
                    i++;
                }
                int tag_end = i;
                char tag_name[tag_end - tag_start + 1];
                memcpy(tag_name, input + tag_start, tag_end - tag_start);
                tag_name[tag_end - tag_start] = '\0';
                level--;
                print_close_element(tag_name, level);
            }
        }
        else { // Text node
            int text_start = i;
            while (input[i] != '<') {
                i++;
            }
            int text_end = i;
            char text[text_end - text_start + 1];
            memcpy(text, input + text_start, text_end - text_start);
            text[text_end - text_start] = '\0';
            print_text(text, level);
        }
        i++; // Move past > or <
    }
    return 0;
}