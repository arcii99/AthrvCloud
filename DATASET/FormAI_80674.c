//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {

  printf("Welcome to HTTP Client!\n");
  printf("Enter a URL: ");
  
  char url[100];
  scanf("%s", url);
  
  // Check if the URL is valid
  if (strstr(url, "http://") == NULL) {
    printf("Invalid URL format. Please make sure it starts with 'http://'\n");
    return 1;
  }

  printf("Connecting to server...\n");
  
  // Simulate server response time
  sleep(3);
  printf("Server response received!\n");

  printf("Response Body:\n");
  printf("<html>\n<head>\n<title>Welcome to %s</title>\n</head>\n<body>\n<h1>Hello World!</h1>\n</body>\n</html>", url);

  printf("\n");
  printf("Thanks for using HTTP Client!\n");
  
  return 0;
}