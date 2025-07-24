//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPERIENCES 10
#define MAX_EXPERIENCE_LENGTH 100

typedef struct {
    char* title;
    char* company;
    char* startDate;
    char* endDate;
} JobExperience;

char* extractField(char* str, char* startTag, char* endTag) {
    char* start = strstr(str, startTag);
    if (start == NULL) { return NULL; }
    start += strlen(startTag);
    char* end = strstr(start, endTag);
    if (end == NULL) { return NULL; }
    char* field = (char*) malloc((end - start + 1) * sizeof(char));
    strncpy(field, start, end - start);
    field[end - start] = '\0';
    return field;
}

JobExperience* parseResume(char* resume) {
    JobExperience* jobExperiences;
    jobExperiences = (JobExperience*) malloc(MAX_EXPERIENCES * sizeof(JobExperience));
    int experienceCount = 0;
    char* startTag = "<experience>";
    char* endTag = "</experience>";

    char* start = strstr(resume, startTag);
    while (start != NULL && experienceCount < MAX_EXPERIENCES) {
        start += strlen(startTag);
        char* end = strstr(start, endTag);

        char* experienceStr = (char*) malloc((end - start + 1) * sizeof(char));
        strncpy(experienceStr, start, end - start);
        experienceStr[end - start] = '\0';

        jobExperiences[experienceCount].title = extractField(experienceStr, "<title>", "</title>");
        jobExperiences[experienceCount].company = extractField(experienceStr, "<company>", "</company>");
        jobExperiences[experienceCount].startDate = extractField(experienceStr, "<startDate>", "</startDate>");
        jobExperiences[experienceCount].endDate = extractField(experienceStr, "<endDate>", "</endDate>");

        experienceCount += 1;
        start = strstr(end, startTag);
    }

    jobExperiences = realloc(jobExperiences, experienceCount * sizeof(JobExperience));
    return jobExperiences;
}

void printJobExperience(JobExperience jobExperience) {
    printf("Title: %s\n", jobExperience.title);
    printf("Company: %s\n", jobExperience.company);
    printf("Start Date: %s\n", jobExperience.endDate);
    printf("End Date: %s\n", jobExperience.startDate);
}

int main() {
    char* resume = "<resume><experience><title>Software Developer</title><company>ABC Inc.</company><startDate>June 2018</startDate><endDate>Present</endDate></experience><experience><title>Assistant Manager</title><company>XYZ Inc.</company><startDate>January 2014</startDate><endDate>May 2018</endDate></experience></resume>";
    JobExperience* jobExperiences = parseResume(resume);

    printf("Parsed job experiences:\n");
    for (int i = 0; i < sizeof(jobExperiences)/sizeof(JobExperience); i++) {
        printJobExperience(jobExperiences[i]);
    }

    for (int i = 0; i < sizeof(jobExperiences)/sizeof(JobExperience); i++) {
        free(jobExperiences[i].title);
        free(jobExperiences[i].company);
        free(jobExperiences[i].startDate);
        free(jobExperiences[i].endDate);
    }
    free(jobExperiences);

    return 0;
}