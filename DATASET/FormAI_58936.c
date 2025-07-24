//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include<stdio.h>
#include<string.h>

int main(){

	char code[1000];
	char formattedCode[1000];
	int indent = 0;
	
	//getting code from user
	printf("Enter your HTML code:\n");
	fgets(code,1000,stdin);
	
	//counters
	int i,j;
	
	//checking if a new line should be inserted
	int newLine = 1;
	
	//formatting the code
	for(i = 0; i < strlen(code); i++){
		
		//checking for opening tag
		if(code[i] == '<' && code[i+1] != '/'){
			for(j = 0; j < indent * 4; j++){
				formattedCode[strlen(formattedCode)] = ' ';
			}
			strcpy(&formattedCode[strlen(formattedCode)],"<");
			newLine = 1;
			indent += 1;
		}
		
		//checking for closing tag
		else if(code[i] == '<' && code[i+1] == '/'){
			indent -= 1;
			if(newLine){
				formattedCode[strlen(formattedCode)] = '\n';
				for(j = 0; j < indent * 4; j++){
					formattedCode[strlen(formattedCode)] = ' ';
				}
			}
			strcpy(&formattedCode[strlen(formattedCode)],"</");
			newLine = 1;
		}
		
		//copying other characters
		else{
			if(newLine){
				formattedCode[strlen(formattedCode)] = '\n';
				for(j = 0; j < indent * 4; j++){
					formattedCode[strlen(formattedCode)] = ' ';
				}
				newLine = 0;
			}
			formattedCode[strlen(formattedCode)] = code[i];
		}
		
	}
	
	//printing formatted code
	printf("Formatted HTML code:\n%s\n", formattedCode);
	
	return 0;
}