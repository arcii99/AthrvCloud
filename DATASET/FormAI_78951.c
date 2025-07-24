//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure of the index record
typedef struct indexRecord {
    int key;
    int pointer;
} indexRecord;

// Define the structure of the data record
typedef struct dataRecord {
    int id;
    char name[20];
    int age;
} dataRecord;

void createIndexFile(char* filename, int num_records) {
    // Create an empty binary index file with num_records * sizeof(indexRecord) bytes
    indexRecord empty_record;
    memset(&empty_record, 0, sizeof(empty_record));
    
    FILE* fp;
    fp = fopen(filename, "wb");
    for(int i = 0; i < num_records; i++) {
        fwrite(&empty_record, sizeof(indexRecord), 1, fp);
    }
    fclose(fp);
}

void insertRecord(char* data_file, char* index_file, dataRecord rec) {
    // Open the data file in append mode and write the record to the end
    FILE* fp;
    fp = fopen(data_file, "ab");
    fwrite(&rec, sizeof(dataRecord), 1, fp);
    fclose(fp);

    // Open the index file in binary mode and find the correct position to insert the index record
    fp = fopen(index_file, "rb+");
    indexRecord index_rec;
    int position = 0;
    while(fread(&index_rec, sizeof(indexRecord), 1, fp)) {
        if(index_rec.pointer == 0) {
            break;
        }
        if(index_rec.key > rec.id) {
            break;
        }
        position++;
    }
    fseek(fp, position * sizeof(indexRecord), SEEK_SET);

    // Shift all subsequent index records to the right and insert the new index record
    indexRecord temp_rec;
    while(fread(&temp_rec, sizeof(indexRecord), 1, fp)) {
        fseek(fp, -2 * sizeof(indexRecord), SEEK_CUR);
        fwrite(&temp_rec, sizeof(indexRecord), 1, fp);
        fseek(fp, sizeof(indexRecord), SEEK_CUR);
    }
    indexRecord new_index_rec;
    new_index_rec.key = rec.id;
    new_index_rec.pointer = ftell(fp) - sizeof(dataRecord);
    fwrite(&new_index_rec, sizeof(indexRecord), 1, fp);

    fclose(fp);
}

dataRecord readRecord(char* filename, int record_num) {
    // Open the data file in binary mode and read the record at the given position
    FILE* fp;
    fp = fopen(filename, "rb");
    dataRecord rec;
    fseek(fp, record_num * sizeof(dataRecord), SEEK_SET);
    fread(&rec, sizeof(dataRecord), 1, fp);
    fclose(fp);

    return rec;
}

dataRecord searchRecord(char* data_file, char* index_file, int key) {
    // Open the index file in binary mode and perform binary search to find the address of the record
    FILE* fp;
    fp = fopen(index_file, "rb");
    int lo = 0, hi, mid;
    fseek(fp, 0, SEEK_END);
    hi = ftell(fp) / sizeof(indexRecord) - 1;
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        fseek(fp, mid * sizeof(indexRecord), SEEK_SET);
        indexRecord index_rec;
        fread(&index_rec, sizeof(indexRecord), 1, fp);
        if(index_rec.key == key) {
            fclose(fp);
            return readRecord(data_file, index_rec.pointer / sizeof(dataRecord));
        }
        if(key < index_rec.key) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    fclose(fp);
    dataRecord empty_rec;
    memset(&empty_rec, 0, sizeof(empty_rec));
    return empty_rec;
}

void printRecord(dataRecord rec) {
    printf("ID: %d\nName: %s\nAge: %d\n", rec.id, rec.name, rec.age);
}

int main() {
    // Create an empty data file and index file with 10 records each
    createIndexFile("index.bin", 10);
    FILE* fp;
    fp = fopen("data.bin", "wb");
    fclose(fp);

    // Insert some sample records
    dataRecord rec1 = {3, "John", 30};
    insertRecord("data.bin", "index.bin", rec1);
    dataRecord rec2 = {1, "Alice", 25};
    insertRecord("data.bin", "index.bin", rec2);
    dataRecord rec3 = {5, "David", 40};
    insertRecord("data.bin", "index.bin", rec3);

    // Search for a record by ID
    dataRecord search_result = searchRecord("data.bin", "index.bin", 1);
    if(search_result.id == 0) {
        printf("Record not found\n");
    } else {
        printRecord(search_result);
    }

    // Delete the data and index files to clean up
    remove("data.bin");
    remove("index.bin");

    return 0;
}