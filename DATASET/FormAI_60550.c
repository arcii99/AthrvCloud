//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure to store resume information
struct Resume{
   char name[50];
   char email[50];
   char phone_number[20];
   char skills[100];
   char education[50];
}resume;

int main(){
   char resume_text[500]; //assume max length of resume is 500 characters
   
   printf("Enter the resume text: \n");
   fgets(resume_text, 500, stdin); //reading input from user
   
   //code for parsing the resume text
   char *token = strtok(resume_text, "\n"); //using strtok function to tokenize the input
   while(token != NULL){
      if(strstr(token, "Name:") != NULL){ //if the line contains name information
         strcpy(resume.name, token + 5); //copying the name to the respective field in the structure
      }
      else if(strstr(token, "Email:") != NULL){ //if the line containts email information
         strcpy(resume.email, token + 6); //copying the email to the respective field in the structure
      }
      else if(strstr(token, "Phone:") != NULL){ //if the line contains phone number information
         strcpy(resume.phone_number, token + 6); //copying the phone number to the respective field in the structure
      }
      else if(strstr(token, "Skills:") != NULL){ //if the line contains skills information
         strcpy(resume.skills, token + 7); //copying the skills to the respective field in the structure
      }
      else if(strstr(token, "Education:") != NULL){ //if the line contains education information
         strcpy(resume.education, token + 10); //copying the education to the respective field in the structure
      }
      token = strtok(NULL, "\n"); //moving to next line
   }
   
   //printing the parsed information
   printf("\nName: %s\n", resume.name);
   printf("Email: %s\n", resume.email);
   printf("Phone Number: %s\n", resume.phone_number);
   printf("Skills: %s\n", resume.skills);
   printf("Education: %s\n", resume.education);
   
   return 0;
}