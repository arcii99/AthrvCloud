//FormAI DATASET v1.0 Category: Syntax parsing ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

int main() {
  char str[MAX_SIZE];
  int i, j, k, len;
  printf("Enter a String: \n");
  fgets(str, MAX_SIZE, stdin);
  len = strlen(str);
  
  for(i=0; i<len - 1; i++) {
    if(str[i] == '/') {
      if(str[i+1] == '/') {
        printf("Single Line Comment Found At Index %d \n", i);
        for(j= i + 2; j<len - 1; j++) {
          if(str[j] == '\n') {
            printf("\n");
            break;
          } else {
            printf("%c", str[j]);
          }
        }
      } else if(str[i+1] == '*') {
        printf("Multiline Comment Found At Index %d \n", i);
        for(j = i + 2; j < len - 1; j++) {
          if(str[j] == '*' && str[j + 1] == '/') {
            printf("\n");
            break;
          } else {
            printf("%c", str[j]);
          }
        }
      }
    } else if(str[i] == '#') {
      printf("Directive Found At Index %d \n", i);
      for(j = i + 1; j < len - 1; j++) {
        if(str[j] == '\n') {
          printf("\n");
          break;
        } else {
          printf("%c", str[j]);
        }
      }
    } else if(str[i] == 'f' && str[i+1] == 'o' && str[i+2] == 'r') {
      printf("For Loop Found At Index %d \n", i);
      for(j = i + 2; j < len - 1; j++) {
        if(str[j] == '(') {
          printf("\n");
          break;
        } else {
          printf("%c", str[j]);
        }
      }
      for(k = j; k < len - 1; k++) {
        if(str[k] == ')') {
          printf(")\n");
          break;
        } else {
          printf("%c", str[k]);
        }
      }
    } else if(str[i] == 'w' && str[i+1] == 'h' && str[i+2] == 'i' && str[i+3] == 'l' && str[i+4] == 'e'){
        printf("While Loop Found At Index %d \n", i);
        for(j = i + 4; j < len - 1; j++) {
            if(str[j] == '(') {
                printf("\n");
                break;
            } else {
                printf("%c", str[j]);
            }
        }
        for(k = j; k < len - 1; k++) {
            if(str[k] == ')') {
                printf(")\n");
                break;
            } else {
                printf("%c", str[k]);
            }
        }
    } else if(str[i] == 'd' && str[i+1] == 'o' && str[i+2] == '{'){
        printf("Do While Loop Found At Index %d \n", i);
        for(j = i + 2; j < len - 1; j++) {
            if(str[j] == '(') {
                printf("\n");
                break;
            } else {
                printf("%c", str[j]);
            }
        }
        for(k = j; k < len - 1; k++) {
            if(str[k] == ')') {
                printf(")\n");
                break;
            } else {
                printf("%c", str[k]);
            }
        }
    }
  }
  return 0;
}