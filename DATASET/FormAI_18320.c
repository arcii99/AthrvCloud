//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RESUME_SIZE 1024 // Maximum size of the resume

typedef struct  {
    char* name;
    char* email;
    char* phone;
    char* address;
} ContactInfo;

typedef struct {
    char* company;
    char* position;
    int start_year;
    int end_year;
} JobInfo;

typedef struct {
    char* university;
    char* degree;
    int grad_year;
} EducationInfo;

typedef struct {
    ContactInfo contact_info;
    JobInfo* job_info;
    int num_jobs;
    EducationInfo* education_info;
    int num_educations;
} Resume;

Resume parse_resume(char* resume_text);

int main() {
    char resume_text[MAX_RESUME_SIZE];
    // TODO: Get the resume text from the user or a file

    Resume resume = parse_resume(resume_text);

    // TODO: Use the resume data to do something useful (e.g. matching job openings)
    return 0;
}

Resume parse_resume(char* resume_text) {
    Resume resume;
    resume.job_info = NULL;
    resume.num_jobs = 0;
    resume.education_info = NULL;
    resume.num_educations = 0;

    char* section_start;
    char* section_end;

    // Parse contact info
    section_start = strstr(resume_text, "Contact Info:");
    if (section_start != NULL) {
        section_start += strlen("Contact Info:");

        section_end = strstr(section_start, "\n\n");
        char* contact_info_text = strndup(section_start, section_end - section_start);
        char* saveptr;
        char* line = strtok_r(contact_info_text, "\n", &saveptr);
        while (line != NULL) {
            if (strstr(line, "Name:")) {
                resume.contact_info.name = strdup(line + strlen("Name:"));
            }
            else if (strstr(line, "Email:")) {
                resume.contact_info.email = strdup(line + strlen("Email:"));
            }
            else if (strstr(line, "Phone:")) {
                resume.contact_info.phone = strdup(line + strlen("Phone:"));
            }
            else if (strstr(line, "Address:")) {
                resume.contact_info.address = strdup(line + strlen("Address:"));
            }
            line = strtok_r(NULL, "\n", &saveptr);
        }
        free(contact_info_text);
    }

    // Parse job info
    section_start = strstr(resume_text, "Experience:");
    if (section_start != NULL) {
        section_start += strlen("Experience:");

        section_end = strstr(section_start, "\n\n");
        char* job_info_text = strndup(section_start, section_end - section_start);
        char* saveptr;
        char* line = strtok_r(job_info_text, "\n", &saveptr);
        while (line != NULL) {
            resume.num_jobs++;
            resume.job_info = realloc(resume.job_info, resume.num_jobs * sizeof(JobInfo));
            JobInfo* job = &resume.job_info[resume.num_jobs - 1];
            job->start_year = -1;
            job->end_year = -1;

            job->position = strdup(line);
            line = strtok_r(NULL, "\n", &saveptr);
            if (line != NULL) {
                job->company = strdup(line);
                line = strtok_r(NULL, "\n", &saveptr);
            }
            if (line != NULL) {
                if (sscanf(line, "%d-%d", &job->start_year, &job->end_year) == 1) {
                    job->end_year = -1;
                }
                line = strtok_r(NULL, "\n", &saveptr);
            }
        }
        free(job_info_text);
    }

    // Parse education info
    section_start = strstr(resume_text, "Education:");
    if (section_start != NULL) {
        section_start += strlen("Education:");

        section_end = strstr(section_start, "\n\n");
        char* education_info_text = strndup(section_start, section_end - section_start);
        char* saveptr;
        char* line = strtok_r(education_info_text, "\n", &saveptr);
        while (line != NULL) {
            resume.num_educations++;
            resume.education_info = realloc(resume.education_info, resume.num_educations * sizeof(EducationInfo));
            EducationInfo* education = &resume.education_info[resume.num_educations - 1];
            education->grad_year = -1;

            education->university = strdup(line);
            line = strtok_r(NULL, "\n", &saveptr);
            if (line != NULL) {
                education->degree = strdup(line);
                line = strtok_r(NULL, "\n", &saveptr);
            }
            if (line != NULL) {
                sscanf(line, "Graduated %d", &education->grad_year);
                line = strtok_r(NULL, "\n", &saveptr);
            }
        }
        free(education_info_text);
    }

    return resume;
}