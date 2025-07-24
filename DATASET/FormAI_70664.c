//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000 // maximum number of words that can be indexed
#define MAX_WORD_LEN 50 // maximum length of each word that can be indexed
#define MAX_FILES 100 // maximum number of files that can be indexed
#define MAX_FILE_NAME_LEN 100 // maximum length of file name

// list of words that need to be ignored when indexing
char* ignored_words[] = {"a", "an", "the", "and", "but", "or", "in", "on", "at", "to", "by", NULL};

// structure to hold information about a file
struct file_info {
    char name[MAX_FILE_NAME_LEN];
    int word_count;
    int* word_locs[MAX_WORDS];
};

// structure to hold information about a word
struct word_info {
    char name[MAX_WORD_LEN];
    int file_count;
    int* file_nums[MAX_FILES];
    int* word_locs[MAX_FILES][MAX_WORDS];
};

// function prototype for word comparison function used in qsort
int word_compare(const void* a, const void* b);

int main() {
    // variable declarations
    int i, j, k;
    char word[MAX_WORD_LEN];
    char file_name[MAX_FILE_NAME_LEN];
    FILE* fp;
    int file_count = 0;
    int word_count = 0;
    struct file_info files[MAX_FILES];
    struct word_info words[MAX_WORDS];

    // ask user for input file
    printf("Enter the name of the input file: ");
    scanf("%s", file_name);

    // open input file
    fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    // read input file word by word and create index
    while(fscanf(fp, "%s", word) == 1) {
        // convert word to lower case
        for(i=0; i<strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // check if word should be ignored
        for(i=0; ignored_words[i]!=NULL; i++) {
            if(strcmp(word, ignored_words[i]) == 0) {
                break;
            }
        }
        if(ignored_words[i] != NULL) {
            continue; // word should be ignored
        }

        // look for word in words array
        for(i=0; i<word_count; i++) {
            if(strcmp(word, words[i].name) == 0) {
                break;
            }
        }

        // if word not found, add it to words array
        if(i == word_count) {
            strcpy(words[i].name, word);
            words[i].file_count = 0;
            word_count++;
        }

        // look for file in files array
        for(j=0; j<file_count; j++) {
            if(strcmp(files[j].name, file_name) == 0) {
                break;
            }
        }

        // if file not found, add it to files array
        if(j == file_count) {
            strcpy(files[j].name, file_name);
            files[j].word_count = 0;
            file_count++;
        }

        // add word location in file
        files[j].word_locs[files[j].word_count] = &i;
        files[j].word_count++;

        // add file to word info
        words[i].file_nums[words[i].file_count] = &j;
        words[i].word_locs[j][words[i].file_count] = &files[j].word_locs[files[j].word_count-1];
        words[i].file_count++;
    }

    // print index
    printf("Index:\n");
    for(i=0; i<word_count; i++) {
        printf("%s:\n", words[i].name);
        qsort(words[i].file_nums, words[i].file_count, sizeof(int*), word_compare);
        for(j=0; j<words[i].file_count; j++) {
            printf("\t%s: ", files[*(words[i].file_nums[j])].name);
            qsort(words[i].word_locs[*(words[i].file_nums[j])], files[*(words[i].file_nums[j])].word_count, sizeof(int*), word_compare);
            for(k=0; k<files[*(words[i].file_nums[j])].word_count; k++) {
                printf("%d ", *(words[i].word_locs[*(words[i].file_nums[j])][k]));
            }
            printf("\n");
        }
    }

    return 0;
}

// word comparison function used in qsort
int word_compare(const void* a, const void* b) {
    return **((int**)a) - **((int**)b);
}