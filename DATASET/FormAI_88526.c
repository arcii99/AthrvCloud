//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a resume
typedef struct resume {
    char* name;
    char* email;
    char* phone;
    char* address;
    char* education;
    char* experience;
} Resume;

// Define a function to create a new resume struct
Resume* create_resume(char* name, char* email, char* phone, char* address, char* education, char* experience) {
    // Allocate memory for the new resume
    Resume* new_resume = malloc(sizeof(Resume));
    if (new_resume == NULL) {
        printf("Error: Failed to allocate memory for new resume\n");
        exit(1);
    }
    // Set the values of the resume struct
    new_resume->name = strdup(name);
    new_resume->email = strdup(email);
    new_resume->phone = strdup(phone);
    new_resume->address = strdup(address);
    new_resume->education = strdup(education);
    new_resume->experience = strdup(experience);
    return new_resume;
}

// Define a function to parse the resume and output statistics
void parse_resume(Resume* resume) {
    printf("-------- Resume Parsing System --------\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("---------------------------------------\n");

    // Find the number of years of experience
    int num_years_exp = 0;
    char* exp_str = resume->experience;
    char* num_str = malloc(sizeof(char) * 10);
    while (*exp_str != '\0') {
        if (isdigit(*exp_str)) {
            int num_index = 0;
            while (isdigit(*exp_str)) {
                num_str[num_index] = *exp_str;
                num_index++;
                exp_str++;
            }
            num_str[num_index] = '\0';
            int years = atoi(num_str);
            if (strstr(exp_str, "years") != NULL || strstr(exp_str, "Year") != NULL) {
                num_years_exp += years;
            }
        }
        exp_str++;
    }
    free(num_str);

    // Output the statistics
    printf("Education Level: %s\n", strstr(resume->education, ",") + 2);
    printf("Number of Years of Experience: %d\n", num_years_exp);
    printf("---------------------------------------\n");
}

int main() {
    // Create a new resume
    Resume* my_resume = create_resume("John Doe", "johndoe@gmail.com", "555-1234", "123 Main St.", "Bachelor of Science in Computer Science, University of California, Berkeley", "Software Developer with 2 years of experience in Java and C++");

    // Parse the resume and output statistics
    parse_resume(my_resume);

    // Free memory and exit program
    free(my_resume->name);
    free(my_resume->email);
    free(my_resume->phone);
    free(my_resume->address);
    free(my_resume->education);
    free(my_resume->experience);
    free(my_resume);
    return 0;
}