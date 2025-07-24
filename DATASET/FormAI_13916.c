//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <string.h>

// Define a function to parse resumes
void parse_resume(char resume[]) {
  // Split the resume into sections based on keywords
  char* intro = strstr(resume, "Objective");
  char* education = strstr(resume, "Education");
  char* experience = strstr(resume, "Experience");
  char* skills = strstr(resume, "Skills");

  // Print out each section of the parsed resume
  printf("Intro: %s\n\n", intro);
  printf("Education: %s\n\n", education);
  printf("Experience: %s\n\n", experience);
  printf("Skills: %s\n\n", skills);
  
  // Count the number of times each letter appears in the resume
  int letter_counts[26] = {0};
  for (int i = 0; i < strlen(resume); i++) {
    if (resume[i] >= 'a' && resume[i] <= 'z') {
      letter_counts[resume[i] - 'a']++;
    }
  }
  
  // Print out the letter counts
  printf("Letter Counts:\n");
  for (int i = 0; i < 26; i++) {
    printf("%c: %d\n", 'a' + i, letter_counts[i]);
  }
}

int main() {
  // Define a surreal resume to parse
  char* surreal_resume = "I am a rockstar ninja astronaut\nwith a passion for octopus farming\nand an insatiable appetite for rainbow waffles";
  
  // Parse the surreal resume
  parse_resume(surreal_resume);
  
  return 0;
}