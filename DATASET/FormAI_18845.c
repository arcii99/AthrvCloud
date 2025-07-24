//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the resume string
#define MAX_RESUME_LENGTH 10000

// Define the maximum length of the skill keyword array
#define MAX_KEYWORD_LENGTH 100
#define MAX_NUM_KEYWORDS 1000

// Define the skill keyword struct
typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
} Keyword;

// Define the resume struct
typedef struct {
    char resume[MAX_RESUME_LENGTH];
    Keyword keywords[MAX_NUM_KEYWORDS];
    int num_keywords;
} Resume;

// Define the skill keyword array
Keyword skills[] = {
    {"C"},
    {"C++"},
    {"Java"},
    {"Python"},
    {"SQL"},
    {"JavaScript"},
    {"HTML"},
    {"CSS"}
};

// Define the number of skill keywords
int num_skills = sizeof(skills) / sizeof(skills[0]);

// Define the resume parsing function
Resume parse_resume(char* text) {
    Resume resume;
    strncpy(resume.resume, text, MAX_RESUME_LENGTH);
    resume.num_keywords = 0;
    char* word = strtok(text, " ,.-\n");
    while (word != NULL) {
        for (int i = 0; i < num_skills; i++) {
            if (strcmp(word, skills[i].keyword) == 0) {
                strncpy(resume.keywords[resume.num_keywords].keyword, word, MAX_KEYWORD_LENGTH);
                resume.num_keywords++;
                break;
            }
        }
        word = strtok(NULL, " ,.-\n");
    }
    return resume;
}

int main() {
    // Sample resume text
    char* resume_text = "Software Developer with proficiency in C++, Java, and Python. Proficient in SQL and JavaScript. Experience with HTML and CSS.";
    
    // Parse the resume text
    Resume resume = parse_resume(resume_text);
    
    // Print the parsed resume
    printf("Resume: %s\n\n", resume.resume);
    printf("Keywords:\n");
    for (int i = 0; i < resume.num_keywords; i++) {
        printf("- %s\n", resume.keywords[i].keyword);
    }
    
    return 0;
}