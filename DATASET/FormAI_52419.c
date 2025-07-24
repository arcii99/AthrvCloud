//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>

int main(void) {
  char input[100];
  printf("Welcome to the URL sanitizer! \n");
  printf("Please enter a URL you want to sanitize: ");
  fgets(input, sizeof(input), stdin);                           //Get input from user

  if(input[strlen(input)-1] == '\n'){                            //Strip new line character from input
      input[strlen(input)-1] = '\0';
  }

  while(strstr(input, "https://") == NULL && strstr(input, "http://") == NULL){          //Check if the input is a valid URL
    printf("Sorry, %s is not a valid URL. Please enter a valid URL starting with https:// or http://: ", input);
    fgets(input, sizeof(input), stdin);
    if(input[strlen(input)-1] == '\n'){                           //Strip new line character from input
      input[strlen(input)-1] = '\0';
    }
  }

  char* sanitized_URL = input;
  if (strstr(input, "?") != NULL) {                    //Remove query parameters
    sanitized_URL = strtok(input, "?");
  }

  if (strstr(sanitized_URL, "www.") != NULL) {          //Remove www from URL
    sanitized_URL = strstr(sanitized_URL, "www.") + 4;
  }

  if (strchr(sanitized_URL, '/') != NULL){             //Remove any paths
    sanitized_URL = strtok(sanitized_URL, "/");
  }

  printf("Your sanitized URL is: %s\n", sanitized_URL);      //Output sanitized URL

  return 0;
}