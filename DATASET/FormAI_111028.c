//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to hold information parsed from the resume
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char work_experience[200];
} Resume;

// Function to parse the name from the resume
void parse_name(char* resume_text, Resume* resume) {
    // Find the first space in the text
    char* first_space = strchr(resume_text, ' ');

    // Set the name as the characters before the first space
    strncpy(resume->name, resume_text, first_space - resume_text);
}

// Function to parse the email from the resume
void parse_email(char* resume_text, Resume* resume) {
    // Find the first '@' character in the text
    char* at_sign = strchr(resume_text, '@');

    // Find the start position of the email by searching backwards for the first space before the '@' character
    char* start_pos = at_sign;
    while (*start_pos != ' ') start_pos--;

    // Find the end position of the email by searching forwards for the first space after the '@' character
    char* end_pos = at_sign;
    while (*end_pos != ' ') end_pos++;

    // Copy the email into the resume struct
    strncpy(resume->email, start_pos + 1, end_pos - start_pos - 1);
}

// Function to parse the phone number from the resume
void parse_phone(char* resume_text, Resume* resume) {
    // Find the first phone number in the text using a regex pattern
    char* phone_number = strstr(resume_text, "\\d{3}-\\d{3}-\\d{4}");

    // Copy the phone number into the resume struct
    strncpy(resume->phone, phone_number, 12);
}

// Function to parse the education from the resume
void parse_education(char* resume_text, Resume* resume) {
    // Find the start position of the education section by finding the first instance of the word "Education" in the text
    char* start_pos = strstr(resume_text, "Education");

    // Find the end position of the education section by finding the next instance of the word "Experience" in the text
    char* end_pos = strstr(start_pos, "Experience");

    // Copy the education section into the resume struct
    strncpy(resume->education, start_pos, end_pos - start_pos);
}

// Function to parse the work experience from the resume
void parse_work_experience(char* resume_text, Resume* resume) {
    // Find the start position of the work experience section by finding the first instance of the word "Experience" in the text
    char* start_pos = strstr(resume_text, "Experience");

    // Find the end position of the work experience section by finding the end of the text
    char* end_pos = resume_text + strlen(resume_text);

    // Copy the work experience section into the resume struct
    strncpy(resume->work_experience, start_pos, end_pos - start_pos);
}

int main() {
    // Sample resume text
    char* resume_text = "John Smith\nEmail: johnsmith@example.com\nPhone: 123-456-7890\n\nEducation:\nBachelor of Science in Computer Science\nXYZ University\n\nExperience:\nSoftware Engineer\nABC Company\nJune 2018 - Present\n";

    // Create a Resume struct to hold the parsed information
    Resume resume;

    // Parse the name, email, phone number, education, and work experience from the resume text
    parse_name(resume_text, &resume);
    parse_email(resume_text, &resume);
    parse_phone(resume_text, &resume);
    parse_education(resume_text, &resume);
    parse_work_experience(resume_text, &resume);

    // Print the parsed information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education:\n%s\n", resume.education);
    printf("Work Experience:\n%s\n", resume.work_experience);

    return 0;
}