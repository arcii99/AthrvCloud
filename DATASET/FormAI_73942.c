//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
/* Romeo and Juliet: A C URL Sanitizer */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to sanitize a URL */
void sanitizeURL(char *url) {
  int i, j;
  char temp[strlen(url)];
  
  /* Convert URL to lowercase */
  for(i = 0; url[i]; i++) {
    temp[i] = tolower(url[i]);
  }
  
  temp[i] = '\0';
  
  /* Replace spaces with HTML encoding */
  for(i = 0, j = 0; temp[i]; i++, j++) {
    if(temp[i] == ' ') {
      url[j] = '%';
      url[++j] = '2';
      url[++j] = '0';
    } else {
      url[j] = temp[i];
    }
  }
  
  url[j] = '\0';
}

int main() {
  char url[100];
  
  printf("Oh, dear URL, why must thou be so cruel?\nPlease, dear friend, do tell\nWhat tale of woe dost thou wish to sell?\n");
  scanf("%s", url);
  
  sanitizeURL(url);
  
  printf("Ah, now I see what thou art, dear URL.\nWith thy %s encoding, thou art quite swell\nI shall use thee with aplomb, and all shall be well\n", url);
  
  return 0;
}