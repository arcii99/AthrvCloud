//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RESUMES 1000
#define MAX_WORDS 4000
#define MAX_WORD_LEN 50

// Resume struct
typedef struct {
    char name[MAX_WORD_LEN];
    char university[MAX_WORD_LEN];
    char skills[MAX_WORD_LEN];
} Resume;

// Function to split a string into words
int split_words(char *str, char words[][MAX_WORD_LEN]) {
    int count = 0;
    char *token = strtok(str, " ");

    while(token != NULL) {
        strncpy(words[count], token, MAX_WORD_LEN);
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to check if a word is in a list of words
bool word_in_list(char *word, char words[][MAX_WORD_LEN], int word_count) {
    for(int i = 0; i < word_count; i++) {
        if(strncmp(word, words[i], MAX_WORD_LEN) == 0) {
            return true;
        }
    }

    return false;
}

// Function to parse a resume and check for matching keywords
void parse_resume(char *resume_text, char keywords[][MAX_WORD_LEN], int keyword_count) {
    char words[MAX_WORDS][MAX_WORD_LEN];
    int word_count = split_words(resume_text, words);

    bool match = false;
    for(int i = 0; i < word_count; i++) {
        if(word_in_list(words[i], keywords, keyword_count)) {
            match = true;
            break;
        }
    }

    if(match) {
        printf("Match found!\n");
    }
}

int main() {
    char keywords[][MAX_WORD_LEN] = {"Java", "Python", "JavaScript", "C++", "HTML", "CSS"};

    // Initialize resumes
    Resume resumes[MAX_RESUMES];
    for(int i = 0; i < MAX_RESUMES; i++) {
        memset(resumes[i].name, 0, MAX_WORD_LEN);
        memset(resumes[i].university, 0, MAX_WORD_LEN);
        memset(resumes[i].skills, 0, MAX_WORD_LEN);
    }

    // Read in resumes from file
    FILE *fp = fopen("resumes.txt", "r");
    if(fp == NULL) {
        printf("Error opening resumes file.\n");
        return 1;
    }

    int num_resumes = 0;
    char buffer[1024];
    while(fgets(buffer, 1024, fp)) {
        char *token = strtok(buffer, ",");
        strncpy(resumes[num_resumes].name, token, MAX_WORD_LEN);

        token = strtok(NULL, ",");
        strncpy(resumes[num_resumes].university, token, MAX_WORD_LEN);

        token = strtok(NULL, ",");
        strncpy(resumes[num_resumes].skills, token, MAX_WORD_LEN);

        num_resumes++;
    }

    fclose(fp);

    // Parse each resume and check for matches
    for(int i = 0; i < num_resumes; i++) {
        printf("\nParsing resume for %s...\n", resumes[i].name);
        parse_resume(resumes[i].skills, keywords, 6);
    }

    return 0;
}