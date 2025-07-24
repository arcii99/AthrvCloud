//FormAI DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a database entry
typedef struct {
   int id;
   char name[50];
   int age;
} Entry;

// Define structure for an index entry
typedef struct {
   int id;
   int offset;
} IndexEntry;

void createIndexFile(char *filename, int numEntries) {
   FILE *indexFile;
   IndexEntry *indexEntries;

   // Allocate memory for the index
   indexEntries = (IndexEntry *) malloc(numEntries * sizeof(IndexEntry));

   // Open the index file
   indexFile = fopen(filename, "wb");

   // Write the index to the file
   fwrite(indexEntries, sizeof(IndexEntry), numEntries, indexFile);

   // Close the index file
   fclose(indexFile);

   // Free the allocated memory
   free(indexEntries);
}

void updateIndex(char *filename, int id, int offset) {
   FILE *indexFile;
   IndexEntry indexEntry;

   // Open the index file
   indexFile = fopen(filename, "r+b");

   // Find the index entry with the matching id and update its offset
   while (fread(&indexEntry, sizeof(IndexEntry), 1, indexFile)) {
      if (indexEntry.id == id) {
         indexEntry.offset = offset;
         fseek(indexFile, -sizeof(IndexEntry), SEEK_CUR);
         fwrite(&indexEntry, sizeof(IndexEntry), 1, indexFile);
         break;
      }
   }

   // Close the index file
   fclose(indexFile);
}

int findEntryOffsetById(char *filename, int id) {
   FILE *indexFile, *dataFile;
   IndexEntry indexEntry;
   Entry entry;
   int offset = -1;

   // Open the index file and data file
   indexFile = fopen(filename, "rb");
   dataFile = fopen("data.db", "rb");

   // Find the index entry with the matching id
   while (fread(&indexEntry, sizeof(IndexEntry), 1, indexFile)) {
      if (indexEntry.id == id) {
         // Read the entry at the offset in the data file
         fseek(dataFile, indexEntry.offset, SEEK_SET);
         fread(&entry, sizeof(Entry), 1, dataFile);
         offset = indexEntry.offset;
         break;
      }
   }

   // Close the index file and data file
   fclose(indexFile);
   fclose(dataFile);

   return offset;
}

void addEntry(char *filename, Entry entry) {
   FILE *dataFile, *indexFile;
   IndexEntry indexEntry;

   // Open the data file and index file
   dataFile = fopen(filename, "ab");
   indexFile = fopen("index.bin", "ab");

   // Write the entry to the data file
   fwrite(&entry, sizeof(Entry), 1, dataFile);

   // Write an index entry for the new entry to the index file
   indexEntry.id = entry.id;
   indexEntry.offset = ftell(dataFile) - sizeof(Entry);
   fwrite(&indexEntry, sizeof(IndexEntry), 1, indexFile);

   // Close the data file and index file
   fclose(dataFile);
   fclose(indexFile);
}

int main() {
   createIndexFile("index.bin", 0);

   Entry entry1 = {1, "John Doe", 25};
   Entry entry2 = {2, "Jane Smith", 30};

   addEntry("data.db", entry1);
   addEntry("data.db", entry2);

   updateIndex("index.bin", 1, 56);

   int offset = findEntryOffsetById("index.bin", 2);
   if (offset != -1) {
      printf("Found entry at offset %d\n", offset);
   } else {
      printf("Entry not found\n");
   }

   return 0;
}