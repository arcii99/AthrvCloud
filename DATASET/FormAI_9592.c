//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char method[10];
  char resource[50];
  char http_version[20];
} Request;

void check_for_intrusion(Request req) {
  // Check for SQL injection attempt
  if (strstr(req.resource, "'") != NULL) {
    printf("Possible SQL injection attempt detected!\n");
  }

  // Check for XSS attempt
  if (strstr(req.resource, "<script>") != NULL) {
    printf("Possible XSS attempt detected!\n");
  }

  // Check for directory traversal attempt
  if (strstr(req.resource, "../") != NULL) {
    printf("Possible directory traversal attempt detected!)\n");
  }
}

int main() {
  // Dummy request for testing
  Request req = {
    .method = "GET",
    .resource = "/index.php?id=1'",
    .http_version = "HTTP/1.1"
  };

  // Check for intrusion attempts
  check_for_intrusion(req);

  return 0;
}