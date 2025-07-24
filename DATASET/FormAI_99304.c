//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    int experience_years;
    char skills[200];
};

int main() {
    // assume we have a list of candidates' resumes in a database
    
    // we want to parse each resume and extract relevant information
    // for example, we may want to know:
    // - the candidate's name and contact information
    // - their education and experience
    // - their skills and areas of expertise
    
    // let's define a function to parse a single resume
    void parse_resume(char *resume_text) {
        // first, let's split the text into sections based on delimiters
        char delim[] = "\n";
        char *section;
        
        // declare a struct to store the relevant information
        struct Resume resume;
        
        // use strtok to split the text into sections based on the delimiter
        section = strtok(resume_text, delim);
        
        while (section != NULL) {
            // for each section, let's check if it contains relevant information
            if (strstr(section, "Name:")) {
                // extract the name and store it in the struct
                sscanf(section, "Name: %s", resume.name);
            } else if (strstr(section, "Email:")) {
                // extract the email and store it in the struct
                sscanf(section, "Email: %s", resume.email);
            } else if (strstr(section, "Phone:")) {
                // extract the phone number and store it in the struct
                sscanf(section, "Phone: %s", resume.phone);
            } else if (strstr(section, "Education:")) {
                // extract the education details and store it in the struct
                int i = 0;
                section += strlen("Education: ");
                while (*section != '\0') {
                    if (*section == ',') {
                        resume.education[i++] = '\n';
                    } else {
                        resume.education[i++] = *section;
                    }
                    section++;
                }
                resume.education[i] = '\0';
            } else if (strstr(section, "Experience:")) {
                // extract the experience details and store it in the struct
                sscanf(section, "Experience: %d years", &resume.experience_years);
            } else if (strstr(section, "Skills:")) {
                // extract the skills and store them in the struct
                int i = 0;
                section += strlen("Skills: ");
                while (*section != '\0') {
                    if (*section == ',') {
                        resume.skills[i++] = '\n';
                    } else {
                        resume.skills[i++] = *section;
                    }
                    section++;
                }
                resume.skills[i] = '\0';
            }
            
            // move to the next section
            section = strtok(NULL, delim);
        }
        
        // now we have parsed the resume and stored the relevant information in a struct
        // we can do whatever we want with this information, such as print it to the console
        printf("Name: %s\n", resume.name);
        printf("Email: %s\n", resume.email);
        printf("Phone: %s\n", resume.phone);
        printf("Education:\n%s\n", resume.education);
        printf("Experience: %d years\n", resume.experience_years);
        printf("Skills:\n%s\n", resume.skills);
        
        printf("\n------------------------------------\n");
    }
    
    // assume we have a list of resumes in a text file
    FILE *file = fopen("resumes.txt", "r");
    char line[1000];
    
    // read each line of the file and parse the resume
    while (fgets(line, sizeof(line), file)) {
        parse_resume(line);
    }
    
    fclose(file);
    
    return 0;
}