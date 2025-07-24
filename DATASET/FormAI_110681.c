//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structs for storing parsed resume data
typedef struct contact_info {
    char *name;
    char *email;
    char *phone;
} ContactInfo;

typedef struct education {
    char *degree;
    char *school;
    char *major;
    char *gpa;
} Education;

typedef struct experience {
    char *title;
    char *company;
    char *location;
    char *start_date;
    char *end_date;
    char *description;
} Experience;

int main() {
    char resume[] = "Alice Smith\nalice.smith@email.com\n(555) 555-5555\n\
                     Education: Bachelor of Science in Computer Science, XYZ University, 3.8 GPA\n\
                     Experience: Software Engineer, ABC Corp, San Francisco, CA, August 2016 - present\n\
                     - Developed and maintained web applications using React and Redux\n\
                     - Collaborated with cross-functional teams to design and implement new features\n\
                     Experience: Android Developer, DEF Co, New York, NY, June 2014 - August 2016\n\
                     - Designed and developed mobile applications using Java and Android SDK\n\
                     - Worked with product managers and designers to deliver high-quality app experiences";

    // Parse resume into individual sections
    char *name = strtok(resume, "\n");
    char *email = strtok(NULL, "\n");
    char *phone = strtok(NULL, "\n");

    // Parse education section
    char *education_str = strstr(resume, "Education:");
    char *education_end = strstr(resume, "Experience:");
    int education_len = education_end - education_str;
    char *education = malloc(sizeof(char) * (education_len + 1));
    strncpy(education, education_str, education_len);
    education[education_len] = '\0';

    char *degree_start = strstr(education, ":") + 2; // skip over ": "
    char *degree_end = strstr(education, ",");
    int degree_len = degree_end - degree_start;
    char *degree = malloc(sizeof(char) * (degree_len + 1));
    strncpy(degree, degree_start, degree_len);
    degree[degree_len] = '\0';

    char *school_start = strstr(degree_end, ", ") + 2; // skip over ", "
    char *school_end = strstr(degree_end + 2, ",");
    int school_len = school_end - school_start;
    char *school = malloc(sizeof(char) * (school_len + 1));
    strncpy(school, school_start, school_len);
    school[school_len] = '\0';

    char *gpa_start = strstr(school_end, "GPA:") + 5; // skip over "GPA: "
    char *gpa_end = strstr(school_end, "\n");
    int gpa_len = gpa_end - gpa_start;
    char *gpa = malloc(sizeof(char) * (gpa_len + 1));
    strncpy(gpa, gpa_start, gpa_len);
    gpa[gpa_len] = '\0';

    Education *edu = malloc(sizeof(Education));
    edu->degree = degree;
    edu->school = school;
    edu->gpa = gpa;

    // Parse experience section
    char *experience_str = strstr(resume, "Experience:");
    int experience_len = strlen(resume) - (experience_str - resume);
    char *experience = malloc(sizeof(char) * (experience_len + 1));
    strncpy(experience, experience_str, experience_len);
    experience[experience_len] = '\0';

    char *exp_start = experience;
    char *exp_title, *exp_company, *exp_loc, *exp_start_date, *exp_end_date, *exp_desc;
    while ((exp_title = strstr(exp_start, "\n- ")) != NULL) {
        exp_title += 3; // skip over "- "
        exp_company = strstr(exp_title, ", ") + 2; // skip over ", "
        exp_loc = strstr(exp_company, ", ") + 2; // skip over ", "
        exp_start_date = strstr(exp_loc, ", ") + 2; // skip over ", "
        exp_end_date = strstr(exp_start_date, " - ") + 3; // skip over " - "
        exp_desc = strstr(exp_end_date, "\n");
        int exp_title_len = exp_company - exp_title - 2;
        int exp_company_len = exp_loc - exp_company - 2;
        int exp_loc_len = exp_start_date - exp_loc - 2;
        int exp_start_date_len = exp_end_date - exp_start_date - 3;
        int exp_end_date_len = exp_desc - exp_end_date;
        char *title = malloc(sizeof(char) * (exp_title_len + 1));
        char *company = malloc(sizeof(char) * (exp_company_len + 1));
        char *loc = malloc(sizeof(char) * (exp_loc_len + 1));
        char *start_date = malloc(sizeof(char) * (exp_start_date_len + 1));
        char *end_date = malloc(sizeof(char) * (exp_end_date_len + 1));
        char *desc = malloc(sizeof(char) * (strlen(exp_desc) + 1));
        strncpy(title, exp_title, exp_title_len);
        title[exp_title_len] = '\0';
        strncpy(company, exp_company, exp_company_len);
        company[exp_company_len] = '\0';
        strncpy(loc, exp_loc, exp_loc_len);
        loc[exp_loc_len] = '\0';
        strncpy(start_date, exp_start_date, exp_start_date_len);
        start_date[exp_start_date_len] = '\0';
        strncpy(end_date, exp_end_date, exp_end_date_len);
        end_date[exp_end_date_len] = '\0';
        strcpy(desc, exp_desc + 1);
        Experience *exp = malloc(sizeof(Experience));
        exp->title = title;
        exp->company = company;
        exp->location = loc;
        exp->start_date = start_date;
        exp->end_date = end_date;
        exp->description = desc;
        printf("Title: %s\n", exp->title);
        printf("Company: %s\n", exp->company);
        printf("Location: %s\n", exp->location);
        printf("Start date: %s\n", exp->start_date);
        printf("End date: %s\n", exp->end_date);
        printf("Description: %s\n", exp->description);
        exp_start = exp_desc + 1;
    }

    // Store parsed data into ContactInfo, Education, and Experience structs
    ContactInfo *contact = malloc(sizeof(ContactInfo));
    contact->name = name;
    contact->email = email;
    contact->phone = phone;

    printf("Name: %s\n", contact->name);
    printf("Email: %s\n", contact->email);
    printf("Phone: %s\n", contact->phone);

    free(contact);
    free(edu);
    free(experience);
    return 0;
}