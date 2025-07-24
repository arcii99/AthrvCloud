//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include<stdio.h>
#include<string.h>

int main(){
  char input[100];
  printf("Enter your cat's language: ");
  fgets(input, 100, stdin);
  
  //Translation begins here
  if(strcmp(input, "Meow")==0){
    printf("Translation: Feed me hooman!\n");
  }
  else if(strcmp(input, "Purr")==0){
    printf("Translation: I'm loving the head scratches, keep going!\n");
  }
  else if(strcmp(input, "Hiss")==0){
    printf("Translation: Back off, I'm in a bad mood and will attack if provoked.\n");
  }
  else if(strcmp(input, "Yowl")==0){
    printf("Translation: I'm in heat and looking for a mate, anyone interested?\n");
  }
  else if(strcmp(input, "Chirp")==0){
    printf("Translation: I'm happy and content, just enjoying the moment.\n");
  }
  else if(strcmp(input, "Growl")==0){
    printf("Translation: I'm feeling threatened and ready to defend myself!\n");
  }
  else if(strcmp(input, "Scratch")==0){
    printf("Translation: I'm itchy and need a scratching post, and if you don't have one, your furniture will do just fine.\n");
  }
  else{
    printf("Translation: I have no idea what your cat is trying to say, maybe try again with a different noise?\n");
  }
  
  return 0;
}