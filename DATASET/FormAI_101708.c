//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include<stdio.h>
#include<string.h>

int main(){
  char input[100];
  printf("Welcome to Cat Translator! Ready to translate? (y/n)\n");
  scanf("%c",&input[0]);

  if(input[0] == 'y' || input[0] == 'Y'){
    printf("Great! Please enter your cat's meow:\n");
    scanf("%s",input);

    if(strcmp(input,"meow") == 0 || strcmp(input,"Meow") == 0){
      printf("Translation: I demand food immediately!\n");
    }else if(strcmp(input,"purr") == 0 || strcmp(input,"Purr") == 0){
      printf("Translation: I am happy and content, do not disturb me.\n");
    }else if(strcmp(input,"hiss") == 0 || strcmp(input,"Hiss") == 0){
      printf("Translation: You have offended me, prepare for my wrath!\n");
    }else if(strcmp(input,"yowl") == 0 || strcmp(input,"Yowl") == 0){
      printf("Translation: I am in great pain and need urgent attention.\n");
    }else{
      printf("Translation: I have absolutely no idea what you are saying, hooman.\n");
    }
  }else{
    printf("Well, what are you waiting for? Go play with your cat!\n");
  }

  return 0;
}