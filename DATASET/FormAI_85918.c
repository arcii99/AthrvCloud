//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// JSON Parser function
void parseJSON(char* jsonString) {
   int i, j, k = 0;
   char* key = NULL;
   char* value = NULL;
   char* token = NULL;
   char* tokens[50];

   // Split the JSON string into tokens
   token = strtok(jsonString, "{},:\"");
   while (token != NULL) {
      tokens[k++] = token;
      token = strtok(NULL, "{},:\"");
   }

   // Create key-value pairs
   for (i = 1; i < k; i++) {
      if (i % 2 != 0) {
         // Handle key
         key = tokens[i];
      } else {
         // Handle value
         value = tokens[i];
         // Remove quotes from value
         memmove(value, value + 1, strlen(value));
         value[strlen(value) - 2] = '\0';
         // Print key-value pair
         printf("%s : %s\n", key, value);
      }
   }
}

int main() {
   char jsonString[] = "{ \"name\":\"John\", \"age\":30, \"car\":null }";

   printf("Parsing JSON string: %s\n", jsonString);
   printf("=========================\n");

   // Call JSON Parser function
   parseJSON(jsonString);

   return 0;
}