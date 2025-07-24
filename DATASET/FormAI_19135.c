//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to hold information about a person's work experience
typedef struct {
    char company[50];
    char position[50];
    char start_date[10];
    char end_date[10];
} WorkExperience;

// Function to parse a resume and extract work experience
WorkExperience* parse_resume(char* resume_text, int* num_work_experiences) {
    // Allocate memory for an array of work experiences
    WorkExperience* work_experiences = (WorkExperience*) malloc(sizeof(WorkExperience) * 10);
    
    // Initialize the number of work experiences to 0
    *num_work_experiences = 0;
    
    // Loop through the resume text to look for work experience sections
    int i = 0;
    while (resume_text[i] != '\0') {
        // Look for a section that starts with "Work Experience" or "Experience"
        if (resume_text[i] == 'W' && resume_text[i+1] == 'o' && resume_text[i+2] == 'r' && resume_text[i+3] == 'k' &&
            resume_text[i+4] == ' ' && resume_text[i+5] == 'E' && resume_text[i+6] == 'x' && resume_text[i+7] == 'p' &&
            resume_text[i+8] == 'e' && resume_text[i+9] == 'r' && resume_text[i+10] == 'i' && resume_text[i+11] == 'e' &&
            resume_text[i+12] == 'n' && resume_text[i+13] == 'c' && resume_text[i+14] == 'e') {
            // Skip to the next line, which should contain the first work experience
            while (resume_text[i] != '\n') {
                i++;
            }
            i++;
            
            // Parse each line of the work experience section and add it to the array
            while (resume_text[i] != '\n' && *num_work_experiences < 10) {
                // Allocate memory for the new work experience
                WorkExperience* new_work_experience = (WorkExperience*) malloc(sizeof(WorkExperience));
                
                // Initialize the fields of the new work experience
                int j = 0;
                while (resume_text[i] != ':') {
                    new_work_experience->company[j] = resume_text[i];
                    i++;
                    j++;
                }
                new_work_experience->company[j] = '\0';
                i++;
                
                j = 0;
                while (resume_text[i] != ':') {
                    new_work_experience->position[j] = resume_text[i];
                    i++;
                    j++;
                }
                new_work_experience->position[j] = '\0';
                i++;
                
                j = 0;
                while (resume_text[i] != '-') {
                    new_work_experience->start_date[j] = resume_text[i];
                    i++;
                    j++;
                }
                new_work_experience->start_date[j] = '\0';
                i++;
                
                j = 0;
                while (resume_text[i] != '\n' && resume_text[i] != '\0') {
                    new_work_experience->end_date[j] = resume_text[i];
                    i++;
                    j++;
                }
                new_work_experience->end_date[j] = '\0';
                
                // Add the new work experience to the array and increment the counter
                work_experiences[*num_work_experiences] = *new_work_experience;
                *num_work_experiences++;
            }
        }
        i++;
    }
        
    // Return the array of work experiences
    return work_experiences;
}

int main() {
    char* resume_text = "John Doe\n123 Main St\nAnytown, USA 12345\n555-555-1234\njohndoe@email.com\n\n\
Objective: Seeking a challenging position in software development\n\n\
Education: Bachelor of Science in Computer Science, XYZ University, May 20XX\n\
          Master of Science in Computer Science, XYZ University, May 20XX\n\n\
Work Experience:\n\
ABC Company: Software Engineer: 06/20XX-07/20XX\n\
- Developed and maintained web applications using Python and Django\n\
- Collaborated with cross-functional teams to design, develop, and test software\n\n\
XYZ Company: Junior Developer: 08/20XX-09/20XX\n\
- Assisted with the development and maintenance of Java applications\n\
- Worked with senior developers to troubleshoot and fix bugs\n";
    
    int num_work_experiences;
    WorkExperience* work_experiences = parse_resume(resume_text, &num_work_experiences);
    
    // Print out the extracted work experiences
    for (int i = 0; i < num_work_experiences; i++) {
        printf("%s\n", work_experiences[i].company);
        printf("%s\n", work_experiences[i].position);
        printf("%s\n", work_experiences[i].start_date);
        printf("%s\n", work_experiences[i].end_date);
        printf("\n");
    }
    
    // Free memory allocated for the work experiences array
    free(work_experiences);
    
    return 0;
}