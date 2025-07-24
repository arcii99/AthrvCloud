//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: irregular
/* Halt! Who goes there? */ 
/* Be ye friend or be ye foe? */

#include<stdio.h> 
#include<string.h> 

void sanitize(char *url){
  int len = strlen(url);
  char clean_url[len];
  int clean_len = 0;
  
  for(int i=0;i<len;i++){
    char current_char = url[i];
    if(current_char == '/' && i>0 && url[i-1] == '/') continue;
    if(current_char >= 'a' && current_char <= 'z' || current_char >= '0' && current_char <= '9' || current_char == '/' || current_char == '.') clean_url[clean_len++] = current_char;
  }
  clean_url[clean_len] = '\0';
  strcpy(url, clean_url);
}

int main(){
  char url[100];
  
  printf("Enter a URL: ");
  scanf("%s", url);
  
  printf("Before santization: %s\n", url);
  
  sanitize(url);
  
  printf("After santization: %s\n", url);
  
  return 0;
}