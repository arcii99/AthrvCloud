//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
  char name[MAX_SIZE];
  char email[MAX_SIZE];
  char password[MAX_SIZE];
} User;

void encrypt(char* text, int key) {
  int i;
  char cipher;

  for(i = 0; i < strlen(text); i++) {
    if(text[i] >= 'a' && text[i] <= 'z') {
      cipher = (text[i] + key - 'a') % 26 + 'a';
    } else if(text[i] >= 'A' && text[i] <= 'Z') {
      cipher = (text[i] + key - 'A') % 26 + 'A';
    } else {
      cipher = text[i];
    }
    text[i] = cipher;
  }
}

void decrypt(char* text, int key) {
  int i;
  char plain;

  for(i = 0; i < strlen(text); i++) {
    if(text[i] >= 'a' && text[i] <= 'z') {
      plain = (text[i] - key - 'a' + 26) % 26 + 'a';
    } else if(text[i] >= 'A' && text[i] <= 'Z') {
      plain = (text[i] - key - 'A' + 26) % 26 + 'A';
    } else {
      plain = text[i];
    }
    text[i] = plain;
  }
}

void saveUser(User user) {
  FILE* file = fopen(user.email, "w");
  if(file == NULL) {
    printf("Error creating user file.\n");
    exit(1);
  }

  encrypt(user.password, 5);
  fwrite(&user, sizeof(User), 1, file);
  fclose(file);
}

void authenticateUser(char* email, char* password) {
  User user;
  FILE* file = fopen(email, "r");
  if(file == NULL) {
    printf("User not found.\n");
    exit(1);
  }

  fread(&user, sizeof(User), 1, file);
  decrypt(user.password, 5);
  if(strcmp(user.password, password) == 0) {
    printf("Authentication successful!\n");
  } else {
    printf("Authentication failed. Try again.\n");
  }
  fclose(file);
}

int main() {
  User newUser;
  char email[MAX_SIZE], password[MAX_SIZE];

  printf("Welcome to the User Authentication System\n\n");
  printf("Enter your name: ");
  fgets(newUser.name, MAX_SIZE, stdin);
  printf("Enter your email: ");
  fgets(newUser.email, MAX_SIZE, stdin);
  printf("Enter your password: ");
  fgets(newUser.password, MAX_SIZE, stdin);

  saveUser(newUser);

  printf("User registered successfully!\n\n");
  printf("Enter your email: ");
  fgets(email, MAX_SIZE, stdin);
  printf("Enter your password: ");
  fgets(password, MAX_SIZE, stdin);

  authenticateUser(email, password);

  return 0;
}