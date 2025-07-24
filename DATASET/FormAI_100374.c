//FormAI DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 20
#define MAX_LINES 50
#define DICTIONARY_FILE "dictionary.txt" 

int line_number = 0; 

void to_upper(char *str){
  while(*str){
    *str = toupper(*str);
    str++;
  }
}

int is_word_valid(char *word){
  FILE *fp;
  char dict_word[MAX_WORD_LENGTH];

  fp = fopen(DICTIONARY_FILE, "r");

  if(!fp){
    printf("\nError: Unable to open dictionary file");
    return 1;
  }

  while(fgets(dict_word, MAX_WORD_LENGTH, fp)){
    to_upper(dict_word);
    if(!strcmp(dict_word, word)){
      fclose(fp);
      return 0;
    }
  }

  fclose(fp);
  return 1;
}

void check_line(char *line){
  char word[MAX_WORD_LENGTH];
  char *p = strtok(line, " ");

  while(p != NULL){
    if(strlen(p) > MAX_WORD_LENGTH){
      printf("\nError: Invalid word '%s'", p);
    }else{
      strcpy(word, p);
      to_upper(word);
      if(is_word_valid(word)){
        printf("\nPossible spelling mistake in line %d: '%s'", line_number, p);
      }
    }
    p = strtok(NULL, " ");
  }
}

int main(){
  char input_line[MAX_LINES][MAX_WORD_LENGTH];
  char *result;
  int i = 0;
  printf("Enter a paragraph with maximum %d lines:\n", MAX_LINES);
  while(i < MAX_LINES && fgets(input_line[i], MAX_WORD_LENGTH, stdin)){
    result = strchr(input_line[i], '\n');
    if(result){
      *result = '\0';
    }else{
      scanf("%*[^\n]");
      scanf("%*c");
    }
    line_number++;
    i++;
  }

  for(i = 0; i < MAX_LINES; i++){
    check_line(input_line[i]);
  }
  
  return 0;
}