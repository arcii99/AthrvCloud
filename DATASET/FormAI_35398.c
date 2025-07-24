//FormAI DATASET v1.0 Category: HTML beautifier ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SPACES 4
#define MAX_LINE_LENGTH 1024

void indent(int level);
int parse_tag(char *line);

int main()
{
    char line[MAX_LINE_LENGTH];
    int inside_tag = 0, level = 0;
    
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        int start = 0, end = strlen(line) - 1;
        
        while (start <= end && (line[start] == ' ' || line[start] == '\t')) {
            start++;
        }
        
        while (end >= 0 && (line[end] == ' ' || line[end] == '\t' || line[end] == '\n' || line[end] == '\r')) {
            end--;
        }
        
        if (start > end) {
            continue;
        }
        
        if (inside_tag) {
            if (line[start] == '<') {
                level++;
            }
            
            inside_tag = parse_tag(line + start) > 0;
        } else {
            indent(level);
        }
        
        printf("%.*s\n", (int)(end - start + 1), line + start);
        
        if (!inside_tag && line[end] == '>') {
            level--;
        }
    }
    
    return 0;
}

void indent(int level)
{
    for (int i = 0; i < level * INDENT_SPACES; i++) {
        putchar(' ');
    }
}

int parse_tag(char *line)
{
    int len = strlen(line);
    
    if (len < 3 || line[0] != '<' || line[1] == '/' || line[len - 1] != '>') {
        return 0;
    }
    
    int i = 1;
    
    while (i < len - 1 && line[i] != ' ' && line[i] != '>') {
        if (!isalnum(line[i])) {
            return 0;
        }
        
        i++;
    }
    
    return i;
}