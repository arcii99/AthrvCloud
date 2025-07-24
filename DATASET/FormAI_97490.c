//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THRESHOLD 10 // Maximum number of failed login attempts allowed before triggering alert

// Structure to represent a failed login attempt
typedef struct {
  char ip[16];
  char username[32];
  char password[32];
} LoginAttempt;

// Function to detect intrusions
void detectIntrusion(LoginAttempt* attempts, int size) {
  int count = 0; // Number of failed login attempts for a single IP
  char cur_ip[16]; // Current IP address being analyzed
  for (int i = 0; i < size; i++) {
    // If a new IP address is detected, reset the count
    if (strcmp(cur_ip, attempts[i].ip) != 0) {
      strcpy(cur_ip, attempts[i].ip);
      count = 0;
    }
    count++;
    if (count >= THRESHOLD) {
      printf("Potential intrusion detected from IP address %s\n", cur_ip);
      printf("Last failed login attempt:\n");
      printf("Username: %s\n", attempts[i].username);
      printf("Password: %s\n", attempts[i].password);
      count = 0;
    }
  }
}

int main() {
  LoginAttempt attempts[] = {
    {"192.168.0.1", "admin", "12345"},
    {"192.168.0.1", "root", "password1"},
    {"192.168.0.1", "testuser", "letmein"},
    {"192.168.0.2", "admin", "password1"},
    {"192.168.0.2", "root", "admin"},
    {"192.168.0.3", "testuser", "password1"},
    {"192.168.0.3", "admin", "admin"},
    {"192.168.0.4", "root", "letmein"},
    {"192.168.0.4", "testuser", "admin"},
    {"192.168.0.4", "admin", "password1"},
    {"192.168.0.4", "root", "password1"},
    {"192.168.0.4", "testuser", "letmein"},
    {"192.168.0.5", "root", "admin"},
    {"192.168.0.5", "testuser", "password1"},
    {"192.168.0.5", "admin", "12345"},
    {"192.168.0.6", "testuser", "letmein"},
    {"192.168.0.6", "root", "password1"},
    {"192.168.0.7", "admin", "password1"},
    {"192.168.0.7", "root", "admin"},
    {"192.168.0.7", "testuser", "12345"}
  };
  int size = sizeof(attempts) / sizeof(LoginAttempt);
  detectIntrusion(attempts, size);
  return 0;
}