//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <regex.h>

int main() {

   regex_t regex;
   int reti;
   char resume[] = "Name: John Doe Experience: 5 years Education: Bachelor's in Computer Science. Skills: Java, Python, C++";

   // Compile regular expression that matches relevant information in resume
   // using named capturing groups
   reti = regcomp(&regex, "Name: (?<name>[[:alpha:][:space:]]+) Experience: (?<experience>[[:digit:]]+) years Education: (?<education>.+) Skills: (?<skills>.+)", 0);
   if (reti) {
      printf("Could not compile regex\n");
      return 1;
   }

   // Execute regular expression and extract relevant information
   regmatch_t pmatch[5];
   reti = regexec(&regex, resume, 5, pmatch, 0);
   if (!reti) {
      // Extract information using named capturing groups
      char name[100], experience[10], education[1000], skills[1000];
      memcpy(name, &resume[pmatch[1].rm_so], pmatch[1].rm_eo - pmatch[1].rm_so);
      name[pmatch[1].rm_eo - pmatch[1].rm_so] = '\0';
      memcpy(experience, &resume[pmatch[2].rm_so], pmatch[2].rm_eo - pmatch[2].rm_so);
      experience[pmatch[2].rm_eo - pmatch[2].rm_so] = '\0';
      memcpy(education, &resume[pmatch[3].rm_so], pmatch[3].rm_eo - pmatch[3].rm_so);
      education[pmatch[3].rm_eo - pmatch[3].rm_so] = '\0';
      memcpy(skills, &resume[pmatch[4].rm_so], pmatch[4].rm_eo - pmatch[4].rm_so);
      skills[pmatch[4].rm_eo - pmatch[4].rm_so] = '\0';

      // Print out extracted information from resume
      printf("Name: %s\n", name);
      printf("Experience: %s years\n", experience);
      printf("Education: %s\n", education);
      printf("Skills: %s\n", skills);
   } else if (reti == REG_NOMATCH) {
      printf("No match found\n");
   } else {
      printf("Regex match failed\n");
      return 1;
   }

   // Free regular expression memory
   regfree(&regex);

   return 0;
}