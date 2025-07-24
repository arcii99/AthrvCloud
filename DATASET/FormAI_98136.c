//FormAI DATASET v1.0 Category: Text processing ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 1000

int main() {
    char *filename = "sample.txt";
    char *new_filename = "output.txt";
    char *search_string = "Hello";
    char *replace_string = "Hi";
    char line[MAX_LINE_SIZE];

    FILE *fp = fopen(filename, "r");
    FILE *new_fp = fopen(new_filename, "w");

    if(fp == NULL || new_fp == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    while(fgets(line, MAX_LINE_SIZE, fp)) {
        char *search_ptr, *replace_ptr, *temp_ptr = line;
        int search_len = strlen(search_string), replace_len = strlen(replace_string);

        while((search_ptr = strstr(temp_ptr, search_string))) {
            int len = search_ptr - temp_ptr;
            fwrite(temp_ptr, 1, len, new_fp);
            fwrite(replace_string, 1, replace_len, new_fp);
            temp_ptr = search_ptr + search_len;
        }

        fwrite(temp_ptr, 1, strlen(temp_ptr), new_fp);
    }

    fclose(fp);
    fclose(new_fp);

    printf("Successfully wrote file to %s\n", new_filename);

    return 0;
}