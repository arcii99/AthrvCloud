//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to parse resume and extract relevant information */
void parse_resume(char *resume_text) {
    char *name = NULL;
    char *email = NULL;
    char *phone = NULL;
    char *education = NULL;
    char *experience = NULL;

    /* Extract name from resume */
    char *name_start = strstr(resume_text, "Name:");
    if(name_start != NULL) {
        name_start += strlen("Name:");
        char *name_end = strchr(name_start, '\n');
        if(name_end != NULL) {
            name = strndup(name_start, name_end - name_start);
        }
    }

    /* Extract email from resume */
    char *email_start = strstr(resume_text, "Email:");
    if(email_start != NULL) {
        email_start += strlen("Email:");
        char *email_end = strchr(email_start, '\n');
        if(email_end != NULL) {
            email = strndup(email_start, email_end - email_start);
        }
    }

    /* Extract phone number from resume */
    char *phone_start = strstr(resume_text, "Phone:");
    if(phone_start != NULL) {
        phone_start += strlen("Phone:");
        char *phone_end = strchr(phone_start, '\n');
        if(phone_end != NULL) {
            phone = strndup(phone_start, phone_end - phone_start);
        }
    }

    /* Extract education details from resume */
    char *education_start = strstr(resume_text, "Education:");
    if(education_start != NULL) {
        education_start += strlen("Education:");
        char *education_end = strstr(education_start, "Experience:");
        if(education_end != NULL) {
            education = strndup(education_start, education_end - education_start);
        }
        else {
            education = strdup(education_start);
        }
    }

    /* Extract experience details from resume */
    char *experience_start = strstr(resume_text, "Experience:");
    if(experience_start != NULL) {
        experience_start += strlen("Experience:");
        experience = strdup(experience_start);
    }

    /* Print the extracted information */
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Education: %s\n", education);
    printf("Experience: %s\n", experience);

    /* Free the memory */
    free(name);
    free(email);
    free(phone);
    free(education);
    free(experience);
}

int main() {
    /* Example resume text */
    char *resume = "Name: John Doe\nEmail: john.doe@example.com\nPhone: (555) 555-1234\nEducation: Bachelor of Science in Computer Science, XYZ University, 2010-2014\nExperience: Software Engineer, ABC Inc., 2014-present\nSkills: C, Python, Java";

    /* Parse the resume */
    parse_resume(resume);

    return 0;
}