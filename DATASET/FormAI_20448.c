//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the employee structure
typedef struct Employee {
    char name[50];
    int age;
    char department[50];
    char job_title[50];
    double salary;
} Employee;

// Define the parse resume function
Employee parse_resume(char* resume) {
    Employee emp;
    // Use string manipulation to extract information from resume
    char* name = strstr(resume, "Name:");
    char* age_str = strstr(resume, "Age:");
    char* dept = strstr(resume, "Department:");
    char* job_title = strstr(resume, "Job Title:");
    char* salary_str = strstr(resume, "Salary:");
    
    // Extract and format name
    sscanf(name, "Name:%s", emp.name);
    emp.name[0] = toupper(emp.name[0]);
    for (int i = 1; i < strlen(emp.name); i++) {
        emp.name[i] = tolower(emp.name[i]);
    }
    
    // Extract age
    sscanf(age_str, "Age:%d", &emp.age);
    
    // Extract and format department
    sscanf(dept, "Department:%s", emp.department);
    emp.department[0] = toupper(emp.department[0]);
    for (int i = 1; i < strlen(emp.department); i++) {
        emp.department[i] = tolower(emp.department[i]);
    }
    
    // Extract and format job title
    sscanf(job_title, "Job Title:%s", emp.job_title);
    emp.job_title[0] = toupper(emp.job_title[0]);
    for (int i = 1; i < strlen(emp.job_title); i++) {
        emp.job_title[i] = tolower(emp.job_title[i]);
    }
    
    // Extract salary
    sscanf(salary_str, "Salary:%lf", &emp.salary);
    
    return emp;
}

int main() {
    // Define sample resumes
    char resume1[500] = "Name: John Smith\nAge: 35\nDepartment: Marketing\nJob Title: Marketing Manager\nSalary: 75000.00";
    char resume2[500] = "Name: Emily Lee\nAge: 28\nDepartment: Human Resources\nJob Title: HR Specialist\nSalary: 50000.00";
    
    // Parse the resumes
    Employee emp1 = parse_resume(resume1);
    Employee emp2 = parse_resume(resume2);
    
    // Print employee information
    printf("Employee 1:\nName: %s\nAge: %d\nDepartment: %s\nJob Title: %s\nSalary: %.2lf\n", emp1.name, emp1.age, emp1.department, emp1.job_title, emp1.salary);
    printf("Employee 2:\nName: %s\nAge: %d\nDepartment: %s\nJob Title: %s\nSalary: %.2lf\n", emp2.name, emp2.age, emp2.department, emp2.job_title, emp2.salary);
    
    return 0;
}