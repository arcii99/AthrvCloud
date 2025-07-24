//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
  	char password[25];
  	char verify[25];
  	int match;
  
  	printf("Welcome to your Password Manager\n");
  
  	// Ask for a new password
  	printf("Enter a new password: ");
  	scanf("%s", password);
  
  	// Verify the Password
  	printf("Verify your Password: ");
  	scanf("%s", verify);
  
  	// Compare Passwords
  	match = strcmp(password, verify);
  	
  	// Password match
  	if (match == 0){
  	    printf("Passwords Match!\n");
  	    printf("Your password is: %s\n", password);
  	} else {
  	   
  	    // Password mismatch
  	       printf("Passwords do not match!\n");
           printf("Sorry, you have to create another password.\n");
           return 0;
  	}
  	
  	return 0;
}