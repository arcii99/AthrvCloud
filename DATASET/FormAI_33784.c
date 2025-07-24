//FormAI DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include<stdio.h>
#include<string.h>

int main(){

char buf[100];
char *token = NULL;
char delim[] = " ;\n";
int count=0;

printf("Enter your C code: \n");

while(fgets(buf, 100, stdin)!= NULL){
token = strtok(buf, delim);
while(token != NULL){
printf("%d): %s\n", count++, token);
token = strtok(NULL, delim);
}
}

return 0;
}