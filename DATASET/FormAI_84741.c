//FormAI DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>

int main() {
  char name[30], location[30], language[30];
  int age, experience;
  
  printf("Let's create a profile, shall we?\n");
  
  printf("What is your name? ");
  scanf("%[^\n]", name);
  
  printf("Where are you from? ");
  scanf(" %[^\n]", location);
  
  printf("What programming language do you know best? ");
  scanf(" %[^\n]", language);
  
  printf("How old are you? ");
  scanf(" %d", &age);
  
  printf("How many years of programming experience do you have? ");
  scanf(" %d", &experience);
  
  FILE *file = fopen("profile.txt", "w");
  
  if (file == NULL) {
    printf("Uh oh, something went wrong!\n");
    return 1;
  }
  
  fprintf(file, "Name: %s\n", name);
  fprintf(file, "From: %s\n", location);
  fprintf(file, "Language: %s\n", language);
  fprintf(file, "Age: %d\n", age);
  fprintf(file, "Years of experience: %d\n", experience);
  
  fclose(file);
  
  printf("\nCongratulations %s, your profile has been created!\n", name);
  printf("Check your profile at profile.txt\n");
  printf("Thank you for using our program! Have a nice day!\n");
  
  return 0;
}