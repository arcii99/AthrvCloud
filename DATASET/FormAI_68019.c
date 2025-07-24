//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_ROWS 100

char* tokenize(char *line, char delim);
void parse_csv(FILE* file);
void print_table();
void remove_newline(char *str);

char grid[MAX_ROWS][MAX_COLS][256] = {'\0'};
int rows = 0,cols = 0;

int main()
{
    FILE* file = fopen("data.csv","r");
    if(!file)
        perror("Error opening file");
    else{
        parse_csv(file);
        print_table();
        fclose(file);
    }
    return 0;
}

char* tokenize(char *line, char delim){
    static char *next_token = NULL;
    char *current_token;
    if(line!=NULL)
        next_token = line;
    if(next_token==NULL)
        return NULL;
    current_token = next_token;
    next_token = strchr(current_token,delim);
    if(next_token!=NULL)
        *next_token++='\0';
    return current_token;
}

void parse_csv(FILE* file){
    char line[1024];
    while(fgets(line,sizeof(line),file)!=NULL){
        remove_newline(line);
        char *token = tokenize(line,',');
        cols = 0;
        while(token!=NULL){
            strcpy(grid[rows][cols++],token);
            token = tokenize(NULL,',');
        }
        rows++;
    }
}

void print_table(){
    printf("Rows: %d, Cols: %d\n",rows,cols);
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%s\t",grid[i][j]);
        }
        printf("\n");
    }
}

void remove_newline(char *str){
    char *newline = strchr(str,'\n');
    if(newline)
        *newline='\0';
}