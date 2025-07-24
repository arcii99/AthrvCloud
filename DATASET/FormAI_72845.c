//FormAI DATASET v1.0 Category: Database Indexing System ; Style: creative
#include<stdio.h>
#include<string.h>

struct student{
    char name[20];
    int id;
    float cgpa;
};

struct index_node{
    int id;
    int offset;
};

int main(){
    struct student st;
    struct index_node in;
    FILE *fp,*ip;
    int size, count=0, i;

    fp = fopen("studentrecords.txt", "rb+");
    ip = fopen("index.txt", "wb+");

    if(fp == NULL || ip == NULL){
        printf("Error opening file.\n");
        return 0;
    }

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp)/sizeof(st);

    struct index_node index[size];

    // Create the index table
    rewind(fp);
    while(fread(&st, sizeof(st), 1, fp)){
        in.id = st.id;
        in.offset = ftell(fp) - sizeof(st);

        index[count++] = in;
    }

    // Sort the index table
    for(i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++){
            if(index[i].id>index[j].id){
                in = index[i];
                index[i] = index[j];
                index[j] = in;
            }
        }
    }

    // Write the sorted index table to index.txt
    fwrite(index, sizeof(index), 1, ip);

    // Search for a record using binary search
    int searchid;
    int l=0, r=count-1, mid;
    printf("Enter the ID to search for: ");
    scanf("%d", &searchid);

    while(l<=r){
        mid = (l+r)/2;
        if(index[mid].id == searchid){
            fseek(fp, index[mid].offset, SEEK_SET);
            fread(&st, sizeof(st), 1, fp);
            printf("Name: %s\nID: %d\nCGPA: %f\n", st.name, st.id, st.cgpa);
            break;
        }
        else if(index[mid].id > searchid){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    fclose(fp);
    fclose(ip);

    return 0;
}