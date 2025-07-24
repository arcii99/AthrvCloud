//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
/*
 * Ada's HTML Beautifier
 * This program takes an HTML file as input and outputs a more readable version of it.
 * It does this by adding line breaks and indentation to every tag and attribute.
 * Written by Ada Lovelace.
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 100

/*
 * This function calculates the new indentation level based on the current level and the tag depth.
 * For each opening tag, the depth is incremented by 1 and the indentation level is increased.
 * For each closing tag, the depth is decremented by 1 and the indentation level is decreased.
 */
int calculate_indent_level(int depth, int current_level) {
    int new_level = current_level;
    if (depth > 0) {
        new_level++;
    } else if (depth < 0) {
        new_level--;
    }
    new_level = (new_level < 0) ? 0 : new_level;
    new_level = (new_level > MAX_INDENT_LEVEL) ? MAX_INDENT_LEVEL : new_level;
    return new_level;
}

/*
 * This function takes a line of HTML code and returns the depth of the opening tag (if any).
 * If the line does not contain an opening tag, then -1 is returned instead.
 */
int get_tag_depth(char *line) {
    int depth = 0;
    char *start = strchr(line, '<');
    if (start != NULL) {
        depth = 1;
        while (*++start != '\0') {
            if (*start == '<') {
                depth++;
            } else if (*start == '>') {
                depth--;
            }
            if (depth == 0) {
                break;
            }
        }
    } else {
        depth = -1;
    }
    return depth;
}

/*
 * This function takes a line of HTML code and adds indentation to it based on the current
 * indentation level.
 */
void add_indentation(char *line, int level) {
    int i;
    for (i = 0; i < level; i++) {
        printf("    ");
    }
}

/*
 * Main function - reads lines of HTML code from a file and outputs the beautified version.
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [input file]\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file '%s'\n", argv[1]);
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    int depth = 0;
    int indent_level = 0;
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        depth += get_tag_depth(line);
        add_indentation(line, indent_level);
        printf("%s", line);
        indent_level = calculate_indent_level(get_tag_depth(line), indent_level);
    }
    fclose(input_file);
    return 0;
}