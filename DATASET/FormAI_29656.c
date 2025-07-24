//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct Index{
    char key[20];
    int position;
};

int main(){
    int index_size;
    printf("Enter the size of the index: ");
    scanf("%d", &index_size);

    struct Index *index = (struct Index*) malloc(index_size * sizeof(struct Index));

    for(int i=0; i<index_size; i++){
        printf("Enter key[%d]: ", i);
        scanf("%s", index[i].key);
        printf("Enter position[%d]: ", i);
        scanf("%d", &index[i].position);
    }

    char search_key[20];
    printf("Enter the key to search: ");
    scanf("%s", search_key);

    //Searching the index
    int flag = 0;
    for(int i=0; i<index_size; i++){
        if(strcmp(index[i].key, search_key)==0){
            printf("Key found at position %d\n", index[i].position);
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("Key not found\n");
    }

    free(index);
    return 0;
}