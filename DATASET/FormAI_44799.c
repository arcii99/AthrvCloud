//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: medieval
#include <stdio.h>
#include <string.h>

void sanitize(char *url){
  int len = strlen(url);
  char newUrl[len];
  int count = 0;
  for(int i=0;i<len;i++){
    if(url[i] != ' '){
      newUrl[count++] = url[i];
    }
  }
  newUrl[count] = '\0';
  printf("Sanitized URL: %s\n", newUrl);
}

int main(){
  printf("Greetings traveller! What is thy URL?\n");
  char url[1000];
  fgets(url, 1000, stdin);
  printf("Thou hast entered: %s\n", url);
  printf("Allow me to cleanse thy URL of malicious intent...\n");
  sanitize(url);
  printf("Now, thy URL is pure and harmless. Go forth and browse the world wide web with peace of mind!\n");
  return 0;
}