//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FIELD_LENGTH 20 /* assuming maximum length of a field in CSV is 20 characters */
#define MAX_FIELDS 10 /* assuming maximum number of fields is 10 in a CSV record */
#define MAX_RECORD_LENGTH ((MAX_FIELD_LENGTH+1)*MAX_FIELDS) /* the maximum length of a record including separators plus a null character */

/* function to read a CSV record and return the number of fields */
int readCSVRecord(FILE *fp, char records[][MAX_RECORD_LENGTH], int max_records){
    int i=0;
    char buffer[MAX_RECORD_LENGTH];
    while(fgets(buffer,MAX_RECORD_LENGTH,fp)){
        char *field=strtok(buffer,",\n"); /* assuming CSV records are comma separated */
        int j=0;
        while(field!=NULL && j<MAX_FIELDS){ /* read all the fields */
            strncpy(records[i*MAX_FIELDS+j],field,MAX_FIELD_LENGTH);
            records[i*MAX_FIELDS+j][MAX_FIELD_LENGTH]='\0'; /* add null character at the end of field */
            field=strtok(NULL,",\n");
            j++;
        }
        i++;
        if(i>=max_records){
            break;
        }
    }
    return i; /* return the number of records */
}

int main(){
    char records[1000][MAX_RECORD_LENGTH]; /* assuming maximum 1000 records in the file */
    FILE *fp=fopen("example.csv","r");
    if(fp==NULL){
        printf("Cannot open the file!\n");
        exit(1);
    }
    int num_records=readCSVRecord(fp,records,1000); /* read the CSV records */
    fclose(fp);

    /* print all the records */
    for(int i=0;i<num_records;i++){
        for(int j=0;j<MAX_FIELDS;j++){
            printf("%s ",records[i*MAX_FIELDS+j]);
        }
        printf("\n");
    }

    return 0;
}