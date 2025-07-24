//FormAI DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include<stdio.h>

int main(){
  FILE *fp;
  char file_name[50], ch;
  int choice;
  printf("\nEnter the name of the ebook to be read: ");
  scanf("%s", file_name);
  fp = fopen(file_name, "r");
  if (fp == NULL){
    printf("File does not exist.");
    return 1;
  }
  printf("\nChoose a mode to read the file:\n1. Mind-bending Mode\n2. Normal Mode\nEnter your choice: ");
  scanf("%d", &choice);
  switch (choice){
    case 1:
      printf("\nWelcome to Mind-bending Mode!\n");
      while ((ch = fgetc(fp)) != EOF){
        if (ch >= 97 && ch <= 122){
          ch = ch - 32;
        }
        if (ch == '.' || ch == '?' || ch == '!'){
          printf("%c", ch);
          printf("?! ");
        }else{
          printf("%c", ch);
        }
      }
      break;
    case 2:
      printf("\nWelcome to Normal Mode!\n");
      while ((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
      }
      break;
    default:
      printf("\nInvalid choice!");
  }
  fclose(fp);
  return 0;
}