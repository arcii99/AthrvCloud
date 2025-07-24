//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <string.h>

// define constants
#define MAX_RESUME_LENGTH 5000
#define MAX_NAME_LENGTH 50
#define MAX_SKILLS_LENGTH 200
#define MAX_EXPERIENCE_LENGTH 1000

// define data structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
} Resume;

// function prototypes
int parseResume(char* resumeStr, Resume* resume);
int countWords(char* str);
int countLines(char* str);

int main() {
    // initialize variables
    char resumeStr[MAX_RESUME_LENGTH];
    Resume resume;

    // sample resume string
    char* sampleResume = "Name: John Doe\nSkills: C Programming, Java, Python\nExperience: Software Engineer at XYZ Company (2 years)\nEducation: Bachelor's Degree in Computer Science\nCertification: Certified C Programmer\n";

    // copy sample resume to the resume string
    strcpy(resumeStr, sampleResume);

    // parse the resume string
    int parsed = parseResume(resumeStr, &resume);

    // print the parsed resume
    if (parsed) {
        printf("Name: %s\nSkills: %s\nExperience: %s\n", resume.name, resume.skills, resume.experience);
    } else {
        printf("Unable to parse the resume.\n");
    }

    return 0;
}

// parse the resume string and populate the resume variable
int parseResume(char* resumeStr, Resume* resume) {
    // initialize variables
    int nameIdx = -1, skillsIdx = -1, expIdx = -1, eduIdx = -1, certIdx = -1;

    // find the indices of the fields in the resume string
    char* namePtr = strstr(resumeStr, "Name:");
    char* skillsPtr = strstr(resumeStr, "Skills:");
    char* expPtr = strstr(resumeStr, "Experience:");
    char* eduPtr = strstr(resumeStr, "Education:");
    char* certPtr = strstr(resumeStr, "Certification:");

    // check if all fields are present
    if (namePtr == NULL || skillsPtr == NULL || expPtr == NULL) {
        return 0;
    }

    // get the indices of the fields
    nameIdx = namePtr - resumeStr;
    skillsIdx = skillsPtr - resumeStr;
    expIdx = expPtr - resumeStr;

    // if education and certification fields are present, get their indices
    if (eduPtr != NULL) {
        eduIdx = eduPtr - resumeStr;
    }

    if (certPtr != NULL) {
        certIdx = certPtr - resumeStr;
    }

    // get the values of the fields
    int nameLength = skillsIdx - nameIdx - 5;
    int skillsLength = expIdx - skillsIdx - 8;
    int expLength = (eduIdx == -1 && certIdx == -1) ? strlen(resumeStr) - expIdx - 12 : ((eduIdx != -1 && certIdx == -1) ? eduIdx - expIdx - 12 : certIdx - expIdx - 16);
    char name[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    char exp[MAX_EXPERIENCE_LENGTH];
    strncpy(name, resumeStr + nameIdx + 5, nameLength);
    name[nameLength] = '\0';
    strncpy(skills, resumeStr + skillsIdx + 8, skillsLength);
    skills[skillsLength] = '\0';
    strncpy(exp, resumeStr + expIdx + 12, expLength);
    exp[expLength] = '\0';

    // populate the resume struct
    strcpy(resume->name, name);
    strcpy(resume->skills, skills);
    strcpy(resume->experience, exp);

    return 1;
}

// count the number of words in a string
int countWords(char* str) {
    // initialize variables
    int count = 0, i = 0;

    // loop through the string
    while (str[i] != '\0') {
        // if a whitespace character is encountered, increment the count
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            count++;
        }
        i++;
    }

    // add one to the count for the last word
    count++;

    return count;
}

// count the number of lines in a string
int countLines(char* str) {
    // initialize variables
    int count = 1, i = 0;

    // loop through the string
    while (str[i] != '\0') {
        // if a newline character is encountered, increment the count
        if (str[i] == '\n') {
            count++;
        }
        i++;
    }

    return count;
}