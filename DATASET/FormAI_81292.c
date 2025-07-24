//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
    char* address;
    char* phone_number;
    char* degree;
    char* university;
    char* cgpa;
    char* company_name;
    char* job_title;
    char* job_description;
    char* start_date;
    char* end_date;
} Resume;

void parseResume(char* input, Resume* resume) {
    char* token = strtok(input, "\n");
    while (token != NULL) {
        if (strstr(token, "Name:")) {
            resume->name = strtok(token+6, "\r");
        } else if (strstr(token, "Email:")) {
            resume->email = strtok(token+7, "\r");
        } else if (strstr(token, "Address:")) {
            resume->address = strtok(token+9, "\r");
        } else if (strstr(token, "Phone Number:")) {
            resume->phone_number = strtok(token+14, "\r");
        } else if (strstr(token, "Degree:")) {
            resume->degree = strtok(token+7, "\r");
        } else if (strstr(token, "University:")) {
            resume->university = strtok(token+11, "\r");
        } else if (strstr(token, "CGPA:")) {
            resume->cgpa = strtok(token+5, "\r");
        } else if (strstr(token, "Company Name:")) {
            resume->company_name = strtok(token+13, "\r");
        } else if (strstr(token, "Job Title:")) {
            resume->job_title = strtok(token+10, "\r");
        } else if (strstr(token, "Job Description:")) {
            resume->job_description = strtok(token+16, "\r");
        } else if (strstr(token, "Start Date:")) {
            resume->start_date = strtok(token+11, "\r");
        } else if (strstr(token, "End Date:")) {
            resume->end_date = strtok(token+9, "\r");
        }
        token = strtok(NULL, "\n");
    }
}

int main() {
    char input[] = "Name: John Doe\r\nEmail: john.doe@email.com\r\nAddress: 123 Main St\r\nPhone Number: (555) 555-5555\r\n"
                   "Degree: Bachelor of Science\r\nUniversity: University of Example\r\nCGPA: 3.5\r\n"
                   "Company Name: Example Corp\r\nJob Title: Software Developer\r\nJob Description: Developed software\r\n"
                   "Start Date: Jan 2015\r\nEnd Date: Dec 2017\r\n";
    Resume resume;
    parseResume(input, &resume);
    printf("Name: %s\nEmail: %s\nAddress: %s\nPhone Number: %s\nDegree: %s\nUniversity: %s\nCGPA: %s\n"
           "Company Name: %s\nJob Title: %s\nJob Description: %s\nStart Date: %s\nEnd Date: %s\n",
           resume.name, resume.email, resume.address, resume.phone_number, resume.degree, resume.university, resume.cgpa,
           resume.company_name, resume.job_title, resume.job_description, resume.start_date, resume.end_date);
    return 0;
}