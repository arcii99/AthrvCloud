//FormAI DATASET v1.0 Category: modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 4

// Encryption function
void encrypt(char *str) {
   int i;
   for(i = 0; str[i] != '\0'; i++) {
      str[i] += 3; // Add 3 to each character
   }
}

// Thread function to encrypt a set of strings
void *encrypt_strings(void *args) {
   char **strings = (char **)args; // Typecast the arguments
   int i;
   for(i = 0; i < NUM_THREADS; i++) {
      encrypt(strings[i]); // Call the encryption function
   }
   return NULL;
}

int main() {
   char *strings[NUM_THREADS] = {"Hello world!", "This is a test.", "Encryption is fun!", "Multi-threading too!"};
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   
   // Print the original strings
   printf("Original strings:\n");
   for(t = 0; t < NUM_THREADS; t++) {
      printf("%s\n", strings[t]);
   }
   
   // Create the threads
   for(t = 0; t < NUM_THREADS; t++) {
      rc = pthread_create(&threads[t], NULL, encrypt_strings, (void *)strings);
      if(rc) {
         printf("ERROR: pthread_create returned error code %d\n", rc);
         exit(-1);
      }
   }
   
   // Wait for the threads to finish
   for(t = 0; t < NUM_THREADS; t++) {
      rc = pthread_join(threads[t], NULL);
      if(rc) {
         printf("ERROR: pthread_join returned error code %d\n", rc);
         exit(-1);
      }
   }
   
   // Print the encrypted strings
   printf("\nEncrypted strings:\n");
   for(t = 0; t < NUM_THREADS; t++) {
      printf("%s\n", strings[t]);
   }
   
   return 0;
}