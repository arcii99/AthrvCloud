//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

//create a structure to hold resume data
struct Resume {
  char name[50];
  char email[50];
  char phone[15];
  char education[100];
  char experience[100];
};

//function to parse resume data
void parse_resume(struct Resume* resume, char* data) {
  char* token = strtok(data, "\n");

  while(token != NULL) {
    if(strstr(token, "Name:") != NULL) {
      strcpy(resume->name, token+5);
    }
    else if(strstr(token, "Email:") != NULL) {
      strcpy(resume->email, token+6);
    }
    else if(strstr(token, "Phone:") != NULL) {
      strcpy(resume->phone, token+6);
    }
    else if(strstr(token, "Education:") != NULL) {
      strcpy(resume->education, token+10);
    }
    else if(strstr(token, "Experience:") != NULL) {
      strcpy(resume->experience, token+12);
    }

    token = strtok(NULL, "\n");
  }
}

int main() {
  char resume_data[] = "Name: Ada Lovelace\nEmail: ada@lovelace.com\nPhone: 123-456-7890\nEducation: Mathematics, University of London\nExperience: Analytical Engine, Babbage Computing\n";

  struct Resume resume = {"", "", "", "", ""};

  parse_resume(&resume, resume_data);

  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Education: %s\n", resume.education);
  printf("Experience: %s\n", resume.experience);

  return 0;
}