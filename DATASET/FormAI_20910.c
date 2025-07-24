//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_LENGTH  256

int total_log_entries = 0;
char log_entries[MAX_LOG_ENTRIES][MAX_LOG_LENGTH];

void log_entry(char* message){
  if(total_log_entries == MAX_LOG_ENTRIES) {
    printf("Error: Maximum log entries exceeded!\n");
    return;
  }
  strcpy(log_entries[total_log_entries], message);
  total_log_entries++;
}

// Simple Intrusion detection function:
int is_intrusion_attempt(char* message) {
  // Check for the presence of common intrusion keywords
  if(strstr(message, "password") || strstr(message, "security") || strstr(message, "admin")) {
    return 1;
  }
  return 0;
}

int main() {
  // A pretend web server
  char* web_log[] = {
    "Visited homepage",
    "Logged in with username: user1",
    "Failed login attempt with username: admin",
    "Viewed secure documents",
    "Changed password",
    "Logout",
    "SQL Injection attempt: DROP TABLE users",
    "PORT SCAN WARNING: 192.168.0.1"
  };
  int num_entries = sizeof(web_log)/sizeof(char*);
  
  // Check each log entry
  for(int i=0; i<num_entries; i++) {
    if(is_intrusion_attempt(web_log[i])) {
      char message[MAX_LOG_LENGTH];
      sprintf(message, "Possible Intrusion Attempt! Log entry: %s", web_log[i]);
      log_entry(message);
    }
  }
  
  // Print the log entries
  printf("Intrusion detection log:\n");
  for(int i=0; i<total_log_entries; i++) {
    printf("%s\n", log_entries[i]);
  }
  
  return 0;
}