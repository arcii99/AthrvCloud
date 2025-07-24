//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: irregular
#include<stdio.h>
#define MAX_LEN 1000                       //define maximum length of user input

int main(){

	char input[MAX_LEN];                    //declare character array for user input
	int i=0;                                //iterator
	char c;                                 //character holder

	printf("Enter your input: ");
	while((c=getchar())!='\n' && i<MAX_LEN){ //loop the input until the maximum length or enter key is reached
		input[i++]=c;                       //store the character
	}

	input[i]='\0';                          //end the string with null character

	for(i=0;input[i]!='\0';i++){            //iterate through the user input

		//replacing all non-alphabetic characters with space
		if((input[i]<65 || input[i]>122) || (input[i]>90 && input[i]<97)){
			input[i]=' ';
		}

		//replacing all uppercase characters with lowercase
		if(input[i]>=65 && input[i]<=90){
			input[i]+=32;
		}
	}

	printf("The sanitized input is: %s\n",input);  //print the sanitized input

	return 0;
}