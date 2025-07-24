//FormAI DATASET v1.0 Category: Spell checking ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char input[50];
  printf("Welcome to the \"Spello!\" spell checker.\n");
  printf("Please enter a sentence to spell check: ");
  
  fgets(input,50,stdin);
  printf("Checking...\n");
  char* buffer = strtok(input," ,\n");

  while(buffer!=NULL){
    if(strcmp(buffer,"porcupine")==0){
      printf("Did you mean 'pineapple'? (y/n): ");
      char response = getchar();
      if(response=='y'){
        printf("pineapple ");
      }else{
        printf("porcupine ");
      }
    }else if(strcmp(buffer,"pangolin")==0){
      printf("Did you mean 'penguin'? (y/n): ");
      char response= getchar();
      if(response=='y'){
        printf("penguin ");
      }else{
        printf("pangolin ");
      }
    }else if(strcmp(buffer,"giraffe")==0){
      printf("Did you mean 'guitar'? (y/n): ");
      char response = getchar();
      if(response=='y'){
        printf("guitar ");
      }else{
        printf("giraffe ");
      }
    }else{
      printf("%s ", buffer);
    }
  buffer = strtok(NULL," ,\n");
  }
  printf("\nThank you for using Spello! Have a nice day! :D\n");
  return 0;
}