//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

#define MAX_INPUT_LENGTH 100

char* process_resume(char *resume_text);

int main(){
    char resume_text[MAX_INPUT_LENGTH];
    printf("Enter the resume text:\n");
    fgets(resume_text, MAX_INPUT_LENGTH, stdin);

    char *parsed_text = process_resume(resume_text);

    printf("\nParsed Resume:\n");
    printf("%s", parsed_text);

    free(parsed_text);
    return 0;
}

char* process_resume(char *resume_text){
    // Insert your parsing logic here
    // For example, this function can extract the name, email, phone number and education details from the resume

    // Dummy parsed text for demonstration purposes
    char *parsed_text = (char*)malloc(sizeof(char) * MAX_INPUT_LENGTH);
    sprintf(parsed_text, "Name: John Doe\nEmail: john.doe@example.com\nPhone: (123) 456-7890\nEducation: B.E. Computer Science");

    return parsed_text;
}