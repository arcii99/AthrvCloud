//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complete
#include<stdio.h>
#include<string.h>

int main(){
	char str[100];
	printf("Enter a C language syntax: ");
	fgets(str, 100, stdin);

	char keywords[32][10] = {
		"auto", "break", "case", "char", "const", "continue", "default",
		"do", "double", "else", "enum", "extern", "float", "for", "goto",
		"if", "int", "long", "register", "return", "short", "signed",
		"sizeof", "static", "struct", "switch", "typedef", "union",
		"unsigned", "void", "volatile", "while"
	};

	char identifiers[100][100];
	int identifierCount = 0;

	char operators[20][5] = {
		"+", "-", "*", "/", "%", "=", "==", "<", ">", "<=", ">=", "++",
		"--", "&", "|", "!", "<<", ">>", "^"
	};

	char literals[100][100];
	int literalCount = 0;

	char current[100];
	int k = 0, len = strlen(str);

	for(int i=0; i<len; i++){
		if(str[i] == ' ' || str[i] == '\n' || str[i] == '{' || str[i] == '(' || str[i] == ')' || str[i] == ',' || str[i] == ';' || str[i] == '"' || str[i] == '\''){
			if(k > 0){
				current[k] = '\0';
				int isKeyword = 0;
				for(int j=0; j<32; j++){
					if(strcmp(keywords[j], current) == 0){
						isKeyword = 1;
						break;
					}
				}

				if(isKeyword){
					printf("%s is a keyword\n", current);
				} else {
					int isLiteral = 0;
					if(current[0] == '\'' || current[0] == '\"'){
						isLiteral = 1;
					} else {
						for(int j=0; j<strlen(current); j++){
							if(current[j] == '.' || (current[j] >= 48 && current[j] <=57)){
								isLiteral = 1;
							} else {
								isLiteral = 0;
								break;
							}
						}
					}

					if(isLiteral){
						strcpy(literals[literalCount], current);
						literalCount++;
						printf("%s is a literal\n", current);

					} else {
						int isIdentifier = 0;

						for(int j=0; j<identifierCount; j++){
							if(strcmp(identifiers[j], current) == 0){
								isIdentifier = 1;
								break;
							}
						}

						if(!isIdentifier){
							strcpy(identifiers[identifierCount], current);
							identifierCount++;
						}

						printf("%s is an identifier\n", current);
					}
				}
				
				k = 0;
			}

			if(str[i] == '"' || str[i] == '\''){
				i++;
				while(str[i] != '"' && str[i] != '\''){
					i++;
				}
			}

		} else if(str[i] == '/' && str[i+1] == '/'){
			i = len-1;
		} else if(str[i] == '/' && str[i+1] == '*'){
			i += 2;
			while(str[i] != '*' || str[i+1] != '/'){
				i++;
			}
			i++;
		} else {
			current[k++] = str[i];
		}
	}

	printf("\nIdentifiers:\n");
	for(int i=0; i<identifierCount; i++){
		printf("%s\n", identifiers[i]);
	}

	printf("\nLiterals:\n");
	for(int i=0; i<literalCount; i++){
		printf("%s\n", literals[i]);
	}

	return 0;
}