//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recover_data(char *filename){
    FILE *file;
    char *data;
    int lSize; 
 
 
    file = fopen(filename , "rb" );
    if( !file ) perror(filename), exit(1);

    fseek( file , 0L , SEEK_END);
    lSize = ftell( file );
    rewind( file );

    data = calloc( 1, lSize+1 );
    if( !data ) fclose(file),fputs("memory alloc fails",stderr),exit(1);

    if( 1!=fread( data , lSize, 1 , file) )
    fclose(file),free(data),fputs("entire read fails",stderr),exit(1);

   char* backup_data = data;
   char* ptr = NULL;
   while ( (ptr = strstr(data, "RECOVER")) != NULL ) {
      int size = strlen(ptr) - 7;
      printf("%.*s", size, ptr + 7);
      ptr += size + 7;
   }

   fclose(file);
   free(backup_data);
}

int main(){
    char* filename = "data.bin";
    recover_data(filename);
    return 0;
}