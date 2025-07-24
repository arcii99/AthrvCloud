//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1000 // Maximum length of a URL
#define MAX_SAFE_LENGTH 100 // Maximum length of a safe prefix or suffix 

// A function to check if a given string is a valid URL
bool is_valid_url(char* str) {
  // A valid URL should start with "http://" or "https://"
  char safe_prefixes[][MAX_SAFE_LENGTH] = {"http://", "https://"};
  bool has_safe_prefix = false;
  for(int i = 0; i < sizeof(safe_prefixes) / sizeof(safe_prefixes[0]); i++) {
    if(strncmp(str, safe_prefixes[i], strlen(safe_prefixes[i])) == 0) {
      has_safe_prefix = true;
      break;
    }
  }
  
  if(!has_safe_prefix) {
    return false;
  }
  
  // A valid URL should contain at least one period (.)
  char* period = strchr(str, '.');
  if(period == NULL) {
    return false;
  }
  
  // A valid URL should not contain any whitespace characters
  char* whitespace = strpbrk(str, " \t\r\n");
  if(whitespace != NULL) {
    return false;
  }
  
  return true;
}

// A function to sanitize a URL string by removing any unsafe characters or paths
char* sanitize_url(char* url) {
  char* safe_url = (char*) malloc(sizeof(char) * MAX_URL_LENGTH);
  int safe_index = 0;
  
  // Copy the safe prefix (i.e. "http://" or "https://")
  char safe_prefix[][MAX_SAFE_LENGTH] = {"http://", "https://"};
  for(int i = 0; i < sizeof(safe_prefix) / sizeof(safe_prefix[0]); i++) {
    if(strncmp(url, safe_prefix[i], strlen(safe_prefix[i])) == 0) {
      strncpy(&safe_url[safe_index], safe_prefix[i], strlen(safe_prefix[i]));
      safe_index += strlen(safe_prefix[i]);
      break;
    }
  }
  
  // Copy the safe domain name
  char* period = strchr(url, '.');
  int domain_length = strlen(period);
  strncpy(&safe_url[safe_index], period, domain_length);
  safe_index += domain_length;
  
  // Copy the safe suffix (i.e. ".com", ".org", etc.)
  char safe_suffix[][MAX_SAFE_LENGTH] = {".com", ".org", ".net", ".int", ".edu", ".gov", ".mil"};
  for(int i = 0; i < sizeof(safe_suffix) / sizeof(safe_suffix[0]); i++) {
    if(strstr(period, safe_suffix[i]) != NULL) {
      strncpy(&safe_url[safe_index], safe_suffix[i], strlen(safe_suffix[i]));
      safe_index += strlen(safe_suffix[i]);
      break;
    }
  }
  
  // Add the null terminator to the safe URL string
  safe_url[safe_index] = '\0';
  
  return safe_url;
}

int main() {
  char url[MAX_URL_LENGTH];
  printf("Enter a URL to sanitize: ");
  fgets(url, MAX_URL_LENGTH, stdin);
  
  // Remove any newline characters from the input string
  char* newline = strchr(url, '\n');
  if(newline != NULL) {
    *newline = '\0';
  }
  
  if(!is_valid_url(url)) {
    printf("Invalid URL.\n");
    return 1;
  }
  
  char* safe_url = sanitize_url(url);
  printf("Safe URL: %s\n", safe_url);
  
  return 0;
}