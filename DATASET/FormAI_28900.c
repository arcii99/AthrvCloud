//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include<stdio.h>
#include<string.h>

int main() {
    char resume[] = "John Doe\n\nObjective:\nTo obtain a software developer position at XYZ Company.\n\nSummary:\nExperienced software developer with a strong background in C++ and Python programming languages.\n\nSkills:\n- C++\n- Python\n- SQL\n- Agile Development\n\nEducation:\nBachelor of Science in Computer Science, XYZ University, 2015-2019\n\nExperience:\nSoftware Developer, ABC Company, 2019-Present\n- Worked on multiple C++ projects to enhance system efficiency\n- Contributed to development of Python-based applications for data analysis\n- Collaborated with team members in Agile development environment\n\nProjects:\n- Developed a C++ program to optimize file handling in a large-scale data environment\n- Created a Python-based web scraper to extract data from dynamic sources\n- Conceived and implemented a database management system in SQL to streamline data storage\n\nCertifications:\n- Oracle Certified Associate Java Programmer\n- AWS Certified Solutions Architect - Associate\n\nReferences:\nAvailable upon request.";
    
    char name[50];
    char objective[200];
    char summary[1000];
    char skills[400];
    char education[500];
    char experience[1000];
    char projects[1000];
    char certifications[200];
    char references[200];
    
    int i;
    
    // Extracting Name
    i = 0;
    while(resume[i] != '\n') {
        name[i] = resume[i];
        i++;
    }
    name[i] = '\0';
    
    // Extracting Objective
    char* obj_start = strstr(resume, "Objective:");
    char* obj_end = strstr(obj_start, "\n\n");
    int obj_size = obj_end - obj_start - 10;
    i = 0;
    for(int j=10; j<obj_size+10; j++) {
        objective[i] = obj_start[j];
        i++;
    }
    objective[i] = '\0';
    
    // Extracting Summary
    char* summary_start = strstr(resume, "Summary:");
    char* summary_end = strstr(summary_start, "\n\n");
    int summary_size = summary_end - summary_start - 8;
    i = 0;
    for(int j=8; j<summary_size+8; j++) {
        summary[i] = summary_start[j];
        i++;
    }
    summary[i] = '\0';
    
    // Extracting Skills
    char* skills_start = strstr(resume, "Skills:");
    char* skills_end = strstr(skills_start, "\n\n");
    int skills_size = skills_end - skills_start - 7;
    i = 0;
    for(int j=7; j<skills_size+7; j++) {
        skills[i] = skills_start[j];
        i++;
    }
    skills[i] = '\0';
    
    // Extracting Education
    char* education_start = strstr(resume, "Education:");
    char* education_end = strstr(education_start, "\n\n");
    int education_size = education_end - education_start - 10;
    i = 0;
    for(int j=10; j<education_size+10; j++) {
        education[i] = education_start[j];
        i++;
    }
    education[i] = '\0';
    
    // Extracting Experience
    char* experience_start = strstr(resume, "Experience:");
    char* experience_end = strstr(experience_start, "\n\n");
    int experience_size = experience_end - experience_start - 11;
    i = 0;
    for(int j=11; j<experience_size+11; j++) {
        experience[i] = experience_start[j];
        i++;
    }
    experience[i] = '\0';
    
    // Extracting Projects
    char* projects_start = strstr(resume, "Projects:");
    char* projects_end = strstr(projects_start, "\n\n");
    int projects_size = projects_end - projects_start - 9;
    i = 0;
    for(int j=9; j<projects_size+9; j++) {
        projects[i] = projects_start[j];
        i++;
    }
    projects[i] = '\0';
    
    // Extracting Certifications
    char* certifications_start = strstr(resume, "Certifications:");
    char* certifications_end = strstr(certifications_start, "\n\n");
    int certifications_size = certifications_end - certifications_start - 15;
    i = 0;
    for(int j=15; j<certifications_size+15; j++) {
        certifications[i] = certifications_start[j];
        i++;
    }
    certifications[i] = '\0';
    
    // Extracting References
    char* references_start = strstr(resume, "References:");
    char* references_end = strstr(references_start, ".");
    int references_size = references_end - references_start - 12;
    i = 0;
    for(int j=12; j<references_size+12; j++) {
        references[i] = references_start[j];
        i++;
    }
    references[i] = '\0';
    
    // Printing extracted data
    printf("Name: %s\n", name);
    printf("Objective: %s\n", objective);
    printf("Summary: %s\n", summary);
    printf("Skills: %s\n", skills);
    printf("Education: %s\n", education);
    printf("Experience: %s\n", experience);
    printf("Projects: %s\n", projects);
    printf("Certifications: %s\n", certifications);
    printf("References: %s\n", references);
    
    return 0;
}