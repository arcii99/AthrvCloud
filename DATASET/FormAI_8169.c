//FormAI DATASET v1.0 Category: Log analysis ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp;
    char filename[100], fileline[500], searchstring[100];
    int linenumber = 1, count = 0;
    
    printf("Please enter the path of the log file to search: ");
    fgets(filename, 100, stdin);

    filename[strcspn(filename, "\n")] = 0; // Remove '\n' from the end of the filename
    
    printf("Please enter the string to search in log file: ");
    fgets(searchstring, 100, stdin);

    searchstring[strcspn(searchstring, "\n")] = 0; // Remove '\n' from the end of the search string

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening log file %s\n", filename);
        exit(1);
    }

    printf("Search result for \"%s\" in file \"%s\"\n\n", searchstring, filename);

    while (fgets(fileline, 500, fp)) {
        if (strstr(fileline, searchstring)) {
            printf("Line %d: %s", linenumber, fileline);
            count++;
        }
        linenumber++;
    }

    printf("\nTotal occurrences of \"%s\" in the file \"%s\" are %d\n", searchstring, filename, count);

    fclose(fp);

    return 0;
}