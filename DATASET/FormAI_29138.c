//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>

int main(){
	int num_lines = 9; // number of lines to print
	int num_spaces = num_lines-1; // number of spaces to start with
	int num_stars = 1; // stars to start with

	// loop through each line
	for(int i=0; i<num_lines; i++){
		// add spaces
		for(int j=0; j<num_spaces; j++){
			printf(" ");
		}
		// add stars
		for(int k=0; k<num_stars; k++){
			printf("*");
		}
		// switch to next line
		printf("\n");

		// update number of spaces and stars
		num_spaces--;
		num_stars+=2;

		// check if halfway through the pattern
		if(i==num_lines/2){
			printf("Keep going, halfway there!\n");
		}
	}

	printf("Pattern completed! Nice job!\n");

	return 0;
}