//FormAI DATASET v1.0 Category: Email Client ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 50

int main(){
  char recipient[MAX_SIZE];
  char subject[MAX_SIZE];
  char body[MAX_SIZE];
  
  printf("Enter recipient's email address: ");
  scanf("%s", recipient);
  if(strlen(recipient) <=0){
      printf("Error: no recipient specified\n");
      return 1;
  }
  
  printf("Enter email subject: ");
  scanf("%s", subject);
  if(strlen(subject) <=0){
      printf("Error: no subject specified\n");
      return 1;
  }
  
  printf("Enter email body: ");
  scanf("%s", body);
  if(strlen(body) <=0){
      printf("Error: no body specified\n");
      return 1;
  }
  
  printf("Sending email to %s with subject %s and body %s.\nEmail sent successfully!",recipient,subject,body);
  
  return 0;
}