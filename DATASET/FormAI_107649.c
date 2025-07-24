//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include<stdio.h>

int main(){
  printf("Are you ready to see an amazing C pattern printing program?!\n");

  //Initializing variables
  int rows, i, j, k, space = 1;

  printf("Enter the number of rows you want in the pattern: ");
  scanf("%d", &rows);

  for(i = 1; i <= rows; i++){
    for(j = 1; j < space; j++){
      printf(" ");
    }
    for(k = i; k <= rows; k++){
      printf("* ");
    }
    printf("\n");
    space++;
  }

  space = rows - 1;

  for(i = rows; i >= 1; i--){
    for(j = 1; j < space; j++){
      printf(" ");
    }
    for(k = i; k <= rows; k++){
      printf("* ");
    }
    printf("\n");
    space--;
  }

  printf("Wasn't that fantastic? I hope you enjoyed seeing the pattern being printed as much as I enjoyed printing it!\n");
  return 0;
}