//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/*
 * Structures for storing the resume data
 */

typedef struct personal_info {
    char name[50];
    char email[50];
    char phone_num[15];
} personal_info;

typedef struct education {
    char degree[50];
    char institute_name[100];
    char start_date[10];
    char end_date[10];
} education;

typedef struct work_exp {
    char company_name[100];
    char start_date[10];
    char end_date[10];
    char job_title[50];
} work_exp;

typedef struct skills {
    char skill_name[50];
    int years_of_experience;
} skills;

/*
 * Function for parsing the given resume
 */

void parse_resume(char* resume_data) {
    personal_info pi;
    education edu;
    work_exp we;
    skills sk;

    char *token = strtok(resume_data, "\n");
    while (token != NULL) {
        if (strcmp(token, "<<PERSONAL INFORMATION>>") == 0) {
            printf("\n------------------PERSONAL INFORMATION - FOUND-----------------------\n");
            token = strtok(NULL, "\n");

            strcpy(pi.name, token);
            printf("Name: %s\n", pi.name);

            token = strtok(NULL, "\n");
            strcpy(pi.email, token);
            printf("Email: %s\n", pi.email);

            token = strtok(NULL, "\n");
            strcpy(pi.phone_num, token);
            printf("Phone Number: %s\n", pi.phone_num);
        }

        else if (strcmp(token, "<<EDUCATION>>") == 0) {
            printf("\n------------------EDUCATION - FOUND-----------------------\n");
            token = strtok(NULL, "\n");

            strcpy(edu.degree, token);
            printf("Degree: %s\n", edu.degree);

            token = strtok(NULL, "\n");
            strcpy(edu.institute_name, token);
            printf("Institute Name: %s\n", edu.institute_name);

            token = strtok(NULL, "\n");
            strcpy(edu.start_date, token);
            printf("Start Date: %s\n", edu.start_date);

            token = strtok(NULL, "\n");
            strcpy(edu.end_date, token);
            printf("End Date: %s\n", edu.end_date);
        }
        else if (strcmp(token, "<<WORK EXPERIENCE>>") == 0) {
            printf("\n------------------WORK EXPERIENCE - FOUND-----------------------\n");
            token = strtok(NULL, "\n");

            strcpy(we.company_name, token);
            printf("Company Name: %s\n", we.company_name);

            token = strtok(NULL, "\n");
            strcpy(we.start_date, token);
            printf("Start Date: %s\n", we.start_date);

            token = strtok(NULL, "\n");
            strcpy(we.end_date, token);
            printf("End Date: %s\n", we.end_date);

            token = strtok(NULL, "\n");
            strcpy(we.job_title, token);
            printf("Job Title: %s\n", we.job_title);
        }
        else if (strcmp(token, "<<SKILLS>>") == 0) {
            printf("\n------------------SKILLS - FOUND-----------------------\n");
            token = strtok(NULL, "\n");

            strcpy(sk.skill_name, token);
            printf("Skill Name: %s\n", sk.skill_name);

            token = strtok(NULL, "\n");
            sk.years_of_experience = atoi(token);
            printf("Years of Experience: %d\n", sk.years_of_experience);
        }

        token = strtok(NULL, "\n");
    }
}

int main() {
    char resume_data[1000] = "<<PERSONAL INFORMATION>>\nJohn Smith\njohnsmith@gmail.com\n123-456-7890\n<<EDUCATION>>\nDegree: Bachelors in Computer Science\nInstitute: XYZ University\nStart Date: 09/2015\nEnd Date: 05/2019\n<<WORK EXPERIENCE>>\nCompany Name: ABC Pvt. Ltd.\nStart Date: 06/2019\nEnd Date: 01/2020\nJob Title: Software Engineer\n<<SKILLS>>\nSkill Name: Python\nYears of Experience: 3";

    parse_resume(resume_data);
    return 0;
}