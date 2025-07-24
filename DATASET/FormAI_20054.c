//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to count the number of times a word appears in a string
int count_word_occurences(char str[], char word[]) {
    int count = 0;
    char* found;
    found = strstr(str, word);
    while (found != NULL) {
        count++;
        found = strstr(found+1, word);
    }
    return count;
}

// function to evaluate a resume based on desired skills
int parse_resume(char resume[], char skills[]) {
    int score = 0;
    char *token;
    token = strtok(skills, ",");
    while(token != NULL) {
        int count = count_word_occurences(resume, token);
        if (count > 0) {
            score++;
        }
        token = strtok(NULL, ",");
    }
    return score;
}

int main() {
    char resume[] = "John Doe is a software engineer with experience in Java, C++, and Python programming.";
    char skills[] = "Java,C++,Python,Agile Methodology";
    int score = parse_resume(resume, skills);
    printf("Resume Score: %d", score);
    return 0;
}