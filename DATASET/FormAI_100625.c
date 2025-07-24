//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    FILE *fp;
    char filename[100], pattern[100], buf[1024];
    regex_t regex;
    int reti, line_num = 0;
    
    // Prompt user for filename and keyword
    printf("Enter filename: ");
    scanf("%s", filename);
    
    printf("Enter keyword: ");
    scanf("%s", pattern);
    
    // Open file for reading
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);   
    }
    
    // Compile regular expression
    reti = regcomp(&regex, pattern, 0);
    if(reti) {
        printf("Error compiling regular expression\n");
        exit(1);
    }
    
    // Search file line by line
    while(fgets(buf, 1024, fp) != NULL) {
        line_num++;
        reti = regexec(&regex, buf, 0, NULL, 0);
        if(!reti) {
            printf("Line %d: %s", line_num, buf);
        }
    }
    
    // Cleanup
    fclose(fp);
    regfree(&regex);
    
    return 0;
}