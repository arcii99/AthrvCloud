//FormAI DATASET v1.0 Category: Password management ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 50   //maximum length of password
#define MAX_USER 10   //maximum number of users the program can store

//structure of User for storing multiple users and passwords
struct User {
   char userid[MAX_LEN];
   char password[MAX_LEN];
};

//function to check if a user exists in the list of users
int checkUserExists(struct User userList[], char newUserID[]) {
   for(int i=0; i<MAX_USER; i++) {
      if(strcmp(userList[i].userid, newUserID)==0)
         return 1;
   }
   return 0;
}

//function to update the password of an existing user
void updatePassword(struct User userList[], char searchUser[]) {
   char newPassword[MAX_LEN];
   int found = 0;
   for(int i=0; i<MAX_USER; i++) {
      if(strcmp(userList[i].userid, searchUser)==0) {
         printf("\nEnter new password for user %s: ", searchUser);
         scanf("%s", newPassword);
         strcpy(userList[i].password, newPassword);
         printf("\nPassword updated successfully!");
         found = 1;
         break;
      }
   }
   if(found==0)
      printf("\nUser not found!");
}

//function to add a new user and password to the list
void addUserPassword(struct User userList[]) {
   char newUserID[MAX_LEN], newPassword[MAX_LEN];
   printf("\nEnter new user ID: ");
   scanf("%s", newUserID);
   if(checkUserExists(userList, newUserID)==1) {
      printf("\nUser ID is already taken. Please choose a different user ID.");
   }
   else {
      printf("\nEnter password for user %s: ", newUserID);
      scanf("%s", newPassword);
      for(int i=0; i<MAX_USER; i++) {
         if(strlen(userList[i].userid)==0) {
            strcpy(userList[i].userid, newUserID);
            strcpy(userList[i].password, newPassword);
            printf("\nUser %s added successfully!", newUserID);
            break;
         }
      }
   }
}

int main() {
   struct User userList[MAX_USER];  //array of User for storing multiple users and passwords
   int choice;
   char searchUser[MAX_LEN];
   //initialize the userList with empty strings
   for(int i=0; i<MAX_USER; i++) {
      strcpy(userList[i].userid, "");
      strcpy(userList[i].password, "");
   }
   printf("PASSWORD MANAGEMENT SYSTEM\n");
   do {
      printf("\n\n1. Add New User & Password\n2. Update Existing User Password\n3. Exit");
      printf("\nEnter your choice(1,2,3): ");
      scanf("%d",&choice);
      switch(choice) {
         case 1:
            addUserPassword(userList);
            break;
         case 2:
            printf("\nEnter user to update the password: ");
            scanf("%s", searchUser);
            updatePassword(userList, searchUser);
            break;
         case 3:
            printf("\nExiting the program...");
            exit(0);
         default:
            printf("\nInvalid choice. Please enter 1, 2 or 3.");
      }
   }while(choice!=3);
   return 0;
}