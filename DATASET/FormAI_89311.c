//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 64
#define MAX_FIELDS 10

int parse_csv_line(char *line, char (*fields)[MAX_FIELD_LEN], int max_fields) {
    int len = strlen(line);
    char *p = line;
    int i, j;

    // reset fields
    for (i=0; i<max_fields; i++) {
        fields[i][0] = '\0';
    }

    i = 0;
    while (i < max_fields && p < line+len) {
        // skip whitespace
        while (*p == ' ' || *p == '\t') {
            p++;
        }

        // parse field
        j = 0;
        while (j < MAX_FIELD_LEN-1 && p < line+len && *p != ',' && *p != '\n') {
            fields[i][j] = *p;
            p++;
            j++;
        }
        fields[i][j] = '\0';

        // check for end of line
        if (*p == '\n') {
            i++;
            break;
        }

        // check for end of line
        if (*p != ',') {
            break;
        }

        // move to next field
        i++;
        p++;
    }

    return i;
}

int main() {
    char line[MAX_LINE_LEN];
    char fields[MAX_FIELDS][MAX_FIELD_LEN];
    int i, n_fields;

    while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
        n_fields = parse_csv_line(line, fields, MAX_FIELDS);
        for (i=0; i<n_fields; i++) {
            printf("%s\n", fields[i]);
        }
    }

    return 0;
}