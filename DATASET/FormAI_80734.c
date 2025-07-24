//FormAI DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE_RANGE 120

/* define structure to hold user information */
struct User {
  char name[MAX_NAME_LENGTH];
  int age;
};

int main() {
  int num_users;
  
  /* get number of users to input */
  printf("Enter number of users to input: ");
  scanf("%d", &num_users);
  
  /* create array of users with specified size */
  struct User users[num_users];
  
  /* prompt user for name and age for each user */
  for(int i = 0; i < num_users; i++) {
    printf("\nEnter name for user %d: ", i+1);
    scanf("%s", &users[i].name);
    
    printf("Enter age for user %d: ", i+1);
    scanf("%d", &users[i].age);
    
    /* error check age input */
    if(users[i].age < 0 || users[i].age > MAX_AGE_RANGE) {
      printf("Invalid age input for user %d, please try again.\n", i+1);
      i--;
    }
  }
  
  /* open file to write user information */
  FILE *file = fopen("users.txt", "w");
  
  /* check if file opened successfully */
  if(file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }
  
  /* write user information to file */
  for(int i = 0; i < num_users; i++) {
    fprintf(file, "Name: %s, Age: %d\n", users[i].name, users[i].age);
  }
  
  /* close file */
  fclose(file);
  
  /* read user information from file */
  file = fopen("users.txt", "r");
  
  /* check if file opened successfully */
  if(file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }
  
  /* print user information to console */
  printf("\nUser information:\n");
  char line[100];
  while(fgets(line, sizeof(line), file)) {
    printf("%s", line);
  }
  
  /* close file */
  fclose(file);
  
  return 0;
}