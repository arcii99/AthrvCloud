//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int main() {
  	char password[100],chr;
  	int length, i, upper_count = 0, lower_count = 0, num_count = 0, sym_count = 0, score = 0;

  	printf("Enter Password: ");
  	scanf("%s", password);

  	length = strlen(password);

  	for(i = 0; i < length; i++) {
        chr = password[i];

        if(chr >= 'A' && chr <= 'Z') {
            upper_count++;
        }
        else if (chr >= 'a' && chr <= 'z') {
            lower_count++;
        }
        else if (chr >= '0' && chr <= '9') {
            num_count++;
        }
        else {
            sym_count++;
        }
  	}

    score = upper_count*3 + lower_count*2 + num_count*4 + sym_count*5;

  	if(length < 8) {
        printf("Your Password is too Short\n");
  	}
    else if(score <= 20) {
        printf("Your Password is Weak\n");
  	}
    else if(score > 20 && score <= 35) {
        printf("Your Password is Moderate\n");
  	}
    else {
        printf("Your Password is Strong\n");
    }

  	return 0;
}