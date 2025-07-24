//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct experience {
   char title[50];
   char company[50];
   char start_date[20];
   char end_date[20];
};

typedef struct experience Exp;

struct education {
   char degree[50];
   char school[50];
   char start_date[20];
   char end_date[20];
};

typedef struct education Edu;

struct candidate {
   char name[50];
   char email[50];
   char phone[20];
   Exp* experience_list[10];
   Edu* education_list[10];
   int exp_count;
   int edu_count;
};

typedef struct candidate Cand;

void add_experience(Cand* cand, char* title, char* company, char* start_date, char* end_date) {
   if (cand->exp_count == 10) {
      printf("Max experience entries exceeded, cannot add new entries\n");
      return;
   }
   Exp* exp = (Exp*) malloc(sizeof(Exp));
   strcpy(exp->title, title);
   strcpy(exp->company, company);
   strcpy(exp->start_date, start_date);
   strcpy(exp->end_date, end_date);
   cand->experience_list[cand->exp_count] = exp;
   cand->exp_count++;
}

void add_education(Cand* cand, char* degree, char* school, char* start_date, char* end_date) {
   if (cand->edu_count == 10) {
      printf("Max education entries exceeded, cannot add new entries\n");
      return;
   }
   Edu* edu = (Edu*) malloc(sizeof(Edu));
   strcpy(edu->degree, degree);
   strcpy(edu->school, school);
   strcpy(edu->start_date, start_date);
   strcpy(edu->end_date, end_date);
   cand->education_list[cand->edu_count] = edu;
   cand->edu_count++;
}

void print_candidate(Cand* cand) {
   printf("Name: %s\n", cand->name);
   printf("Email: %s\n", cand->email);
   printf("Phone: %s\n", cand->phone);
   
   printf("Experience:\n");
   for (int i = 0; i < cand->exp_count; i++) {
      Exp* exp = cand->experience_list[i];
      printf("%d. %s, %s, %s - %s\n", i+1, exp->title, exp->company, exp->start_date, exp->end_date);
   }
   
   printf("Education:\n");
   for (int i = 0; i < cand->edu_count; i++) {
      Edu* edu = cand->education_list[i];
      printf("%d. %s, %s, %s - %s\n", i+1, edu->degree, edu->school, edu->start_date, edu->end_date);
   }
}

int main() {
   Cand cand;
   strcpy(cand.name, "John Doe");
   strcpy(cand.email, "johndoe@example.com");
   strcpy(cand.phone, "555-1234");

   add_experience(&cand, "Software Developer", "ABC Inc.", "Jan 2018", "Present");
   add_experience(&cand, "QA Analyst", "XYZ Corp.", "Jun 2016", "Dec 2017");

   add_education(&cand, "Bachelor of Science", "University of Michigan", "Sep 2011", "May 2015");

   print_candidate(&cand);

   return 0;
}