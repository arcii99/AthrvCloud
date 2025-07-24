//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include<stdio.h>
#include<string.h>

int main(){
  //declaring variables
  char dict[10][20]={"hello","world","happy","cheerful","code","spell","checking","example","program","fun"};
  char input[20];
  int i,j,flag=0;

  //greeting the user
  printf("Hey there! Welcome to the Spell Checker program!\n");
  printf("Enter a word and we'll check if it's spelled correctly!\n");

  //taking input from the user
  printf("Enter a word: ");
  scanf("%s",input);

  //checking if the input matches any word in the dictionary
  for(i=0;i<10;i++){
    if(strcmp(dict[i],input)==0){
      printf("Yay! The word %s is spelled correctly!\n",input);
      flag=1;
      break;
    }
  }

  //if the input does not match any word in the dictionary
  if(flag==0){
    printf("Oops! The word %s is misspelled. Here are some suggestions:\n",input);

    //finding suggestions for the misspelled word
    for(i=0;i<10;i++){
      for(j=0;j<strlen(dict[i]);j++){
        if(input[j]!=dict[i][j]){
          strcpy(dict[i],input); //replacing the incorrect letter with the correct one
          printf("%s\n",dict[i]); //printing the corrected word
          break;
        }
      }
    }
  }

  printf("Thank you for using our program! Have a cheerful day!\n");

  return 0;
}