//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* header;
    char* value;
} field;

typedef struct {
    field* fields;
    int count;
} resume;

void print_field(field f) {
    printf("%s: %s\n", f.header, f.value);
}

void print_resume(resume r) {
    for (int i = 0; i < r.count; i++) {
        print_field(r.fields[i]);
    }
}

void free_resume(resume r) {
    for (int i = 0; i < r.count; i++) {
        free(r.fields[i].header);
        free(r.fields[i].value);
    }
    free(r.fields);
}

char* get_next_field(char* string, char delim) {
    char* result = NULL;
    int count = 0;

    while (*(string + count) != delim) {
        if (*(string + count) == '\0') {
            break;
        }
        count++;
    }

    if (count > 0) {
        result = (char*) malloc((count + 1) * sizeof(char));
        strncpy(result, string, count);
        *(result + count) = '\0';
    }

    return result;
}

field parse_field(char* string) {
    char delim = ':';
    char* header = get_next_field(string, delim);
    char* value = get_next_field(string + strlen(header) + 1, '\n');
    field f = {header, value};
    return f;
}

resume parse_resume(char* input) {
    resume r;
    r.fields = NULL;
    r.count = 0;

    char* line = strtok(input, "\n");

    while (line != NULL) {
        field f = parse_field(line);
        r.fields = (field*) realloc(r.fields, (r.count + 1) * sizeof(field));
        *(r.fields + r.count) = f;
        r.count++;
        line = strtok(NULL, "\n");
    }

    return r;
}

int main() {
    char input[] = "Name: John Doe\n"
                   "Email: john.doe@example.com\n"
                   "Education: Bachelor's in Computer Science\n"
                   "Skills: C++, Java, Python\n";
    resume r = parse_resume(input);
    print_resume(r);
    free_resume(r);
    return 0;
}