//FormAI DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file_record{
    int start_sector;
    int end_sector;
    char file_data[100];
};

int main(){
    struct file_record records[10]; // Assuming there are 10 records
    int n=0; // Counter for number of records
    // Code to read the data from a file and fill the records array
    FILE *fp;
    fp = fopen("data.bin", "rb");
    if(fp==NULL){
        printf("Error opening file!");
        exit(1);
    }
    while(fread(&records[n],sizeof(struct file_record),1,fp)){
        n++;
    }
    fclose(fp);

    // Code to recover the data
    int data_size = 0;
    for(int i=0;i<n;i++){
        data_size += records[i].end_sector - records[i].start_sector + 1;
    }
    char *data = (char*) malloc(data_size * sizeof(char));
    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=records[i].start_sector;j<=records[i].end_sector;j++){
            data[index++] = records[i].file_data[j-records[i].start_sector];
        }
    }
    printf("Recovered Data:\n");
    printf("%s",data);
    free(data);
    return 0;
}