//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char url[1000];
  char sanitized_url[1000];

  printf("Enter URL to sanitize: ");
  scanf("%s", url);

  int url_len = strlen(url);
  int sanitized_url_idx = 0;

  printf("The sanitized URL is: ");

  for(int i=0; i<url_len; i++){
    if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9')){
      sanitized_url[sanitized_url_idx++] = url[i];
    }
    else if(url[i] == '.' || url[i] == '-' || url[i] == '_'){
      sanitized_url[sanitized_url_idx++] = url[i];
    }
  }
  sanitized_url[sanitized_url_idx] = '\0';

  printf("%s\n", sanitized_url);

  return 0;
}