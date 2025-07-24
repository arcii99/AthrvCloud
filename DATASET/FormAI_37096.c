//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000
#define MAX_RESUMES 100

typedef struct {
  char* name;
  char* email;
  char* phone;
  char* education;
  char* skills;
  char* experience;
} Resume;

Resume resumes[MAX_RESUMES];
int num_resumes = 0;

void parse_resume(char* filename) {
  // code to extract information from resume file goes here
  // for now, assume we've already extracted the relevant information
  // and stored it in separate variables
  char* name = "John Doe";
  char* email = "johndoe@email.com";
  char* phone = "555-555-5555";
  char* education = "Bachelor's degree in Computer Science";
  char* skills = "C, Python, Java";
  char* experience = "Software Developer at XYZ Company";

  Resume new_resume = {name, email, phone, education, skills, experience};
  resumes[num_resumes] = new_resume;
  num_resumes++;
}

void print_resume(Resume resume) {
  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Education: %s\n", resume.education);
  printf("Skills: %s\n", resume.skills);
  printf("Experience: %s\n", resume.experience);
  printf("\n");
}

int main() {
  parse_resume("resume1.txt");
  parse_resume("resume2.txt");

  // print all resumes
  for (int i = 0; i < num_resumes; i++) {
    print_resume(resumes[i]);
  }

  return 0;
}