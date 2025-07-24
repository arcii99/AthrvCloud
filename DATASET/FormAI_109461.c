//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define some funny variables
char *skills[] = {"procrastination", "snacking", "Netflix binging", "cat napping"};
char *education[] = {"YouTube University", "Google Search Academy", "Wikipedia Institute of Technology"};
char *languages[] = {"English", "Gibberish", "Emoji", "Dog Speak"};

// define function to parse resume
void parseResume(char *resume) {
    
    // split resume into sections
    char *personal = strtok(resume, "\n");
    char *skills_section = strtok(NULL, "\n");
    char *education_section = strtok(NULL, "\n");
    char *languages_section = strtok(NULL, "\n");
    
    // print out hilarious skills
    printf("Here are my top skills:\n");
    char *skill = strtok(skills_section, ",");
    while(skill != NULL) {
        int index = rand() % (sizeof(skills) / sizeof(skills[0]));
        printf("- %s (I learned this at %s)\n", skill, education[index]);
        skill = strtok(NULL, ",");
    }
    
    // print out ridiculous education history
    printf("\nI am well-educated, having attended the following institutions:\n");
    char *institution = strtok(education_section, ",");
    while(institution != NULL) {
        int index = rand() % (sizeof(education) / sizeof(education[0]));
        printf("- %s (%s graduate)\n", institution, education[index]);
        institution = strtok(NULL, ",");
    }
    
    // print out amazing language abilities
    printf("\nI am fluent in the following languages:\n");
    char *language = strtok(languages_section, ",");
    while(language != NULL) {
        int index = rand() % (sizeof(languages) / sizeof(languages[0]));
        printf("- %s (%s speaker)\n", language, languages[index]);
        language = strtok(NULL, ",");
    }
}

int main() {
    // example resume
    char resume[] = "Jenny Smith\nSkills: procrastination, snacking, Netflix binging, cat napping\nEducation: YouTube University, Wikipedia Institute of Technology, Google Search Academy\nLanguages: English, Gibberish, Emoji, Dog Speak";
    
    // parse resume
    parseResume(resume);
    
    return 0;
}