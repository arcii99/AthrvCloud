//FormAI DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100 // maximum number of lines in file
#define MAX_LINE_LENGTH 100 // maximum length of each line

struct file {
    char lines[MAX_LINES][MAX_LINE_LENGTH]; // array of lines in the file
    int num_lines; // number of lines in the file
};

// function to read file and return its contents as a struct
struct file read_file(char* filename) {
    struct file f;
    f.num_lines = 0;

    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        exit(1);
    }

    char buffer[MAX_LINE_LENGTH];
    while(fgets(buffer, MAX_LINE_LENGTH, fp)) {
        if(f.num_lines == MAX_LINES) {
            printf("Error: File has too many lines (max %d)\n", MAX_LINES);
            exit(1);
        }
        strcpy(f.lines[f.num_lines], buffer);
        f.num_lines++;
    }

    fclose(fp);

    return f;
}

// function to write struct contents to file
void write_file(char* filename, struct file f) {
    FILE* fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        exit(1);
    }

    for(int i=0; i<f.num_lines; i++) {
        fputs(f.lines[i], fp);
    }

    fclose(fp);
}

// function to synchronize two files
void sync_files(char* filename1, char* filename2) {
    struct file f1 = read_file(filename1);
    struct file f2 = read_file(filename2);

    // check if files are already identical
    if(f1.num_lines == f2.num_lines) {
        int i;
        for(i=0; i<f1.num_lines; i++) {
            if(strcmp(f1.lines[i], f2.lines[i]) != 0) {
                break;
            }
        }
        if(i == f1.num_lines) {
            printf("Files are already identical\n");
            return;
        }
    }

    // synchronize files
    if(f1.num_lines > f2.num_lines) {
        for(int i=f2.num_lines; i<f1.num_lines; i++) {
            strcpy(f2.lines[i], f1.lines[i]);
        }
        f2.num_lines = f1.num_lines;
        write_file(filename2, f2);
        printf("Synchronized files\n");
    } else {
        for(int i=f1.num_lines; i<f2.num_lines; i++) {
            strcpy(f1.lines[i], f2.lines[i]);
        }
        f1.num_lines = f2.num_lines;
        write_file(filename1, f1);
        printf("Synchronized files\n");
    }
}

int main() {
    char filename1[] = "file1.txt";
    char filename2[] = "file2.txt";

    sync_files(filename1, filename2);

    return 0;
}