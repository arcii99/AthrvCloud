//FormAI DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Log Analyzer Program!\n");
    printf("We are going to analyze your log file to find out how many times a specific keyword is mentioned.\n");

    char filename[100];
    printf("Please enter the name of the log file you want to analyze: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Failed to open the file: %s\n", filename);
        printf("Please make sure that the file exists and that you have permission to read it\n");
        exit(1);
    }

    char keyword[100];
    printf("Please enter the keyword you want to search for: ");
    scanf("%s", keyword);

    int count = 0;
    char line[500];
    while(fgets(line, 500, fp)) {
        if(strstr(line, keyword) != NULL) {
            count++;
        }
    } 

    printf("The keyword '%s' was mentioned %d times in the log file.\n", keyword, count);
    
    printf("We hope you found this program useful!\n");
    printf("Goodbye!\n");

    fclose(fp);
    return 0;
}