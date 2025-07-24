//FormAI DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum file path and name length
#define MAX_FILEPATH 256

// define sector size (in bytes) of storage device
#define SECTOR_SIZE 512

// define error codes
#define SUCCESS 0
#define INVALID_ARGUMENTS -1
#define INVALID_DEVICE_PATH -2
#define UNABLE_TO_OPEN_FILE -3
#define OUT_OF_MEMORY -4

// function to read a sector from a storage device
int ReadSector(char *devicePath, int sectorNum, unsigned char *buffer) {
  FILE *device;
  int bytesRead;

  // open the storage device
  device = fopen(devicePath, "rb");
  if (device == NULL) {
    printf("Error: unable to open device: %s\n", devicePath);
    return INVALID_DEVICE_PATH;
  }

  // seek to the sector position
  fseek(device, sectorNum * SECTOR_SIZE, SEEK_SET);

  // read the sector
  bytesRead = fread(buffer, 1, SECTOR_SIZE, device);
  if (bytesRead != SECTOR_SIZE) {
    printf("Error: unable to read sector %d from device\n", sectorNum);
    fclose(device);
    return UNABLE_TO_OPEN_FILE;
  }

  // close the device
  fclose(device);

  return SUCCESS;
}

// function to recover a file from a storage device
int RecoverFile(char *devicePath, char *filename) {
  unsigned char *sectorBuffer;
  unsigned char *fileBuffer;
  int fileOffset, sectorNum, bytesRead, fileSize;
  FILE *outputFile;

  // allocate memory for sector buffer
  sectorBuffer = (unsigned char*)malloc(SECTOR_SIZE);
  if (sectorBuffer == NULL) {
    printf("Error: out of memory\n");
    return OUT_OF_MEMORY;
  }

  // allocate memory for file buffer
  fileBuffer = (unsigned char*)malloc(1);
  if (fileBuffer == NULL) {
    printf("Error: out of memory\n");
    free(sectorBuffer);
    return OUT_OF_MEMORY;
  }

  // set initial file size
  fileSize = 0;

  // loop through sectors to find file data
  sectorNum = 0;
  while (ReadSector(devicePath, sectorNum, sectorBuffer) == SUCCESS) {

    // check for file signature (signature can be customized)
    if (sectorBuffer[0] == 0x46 && sectorBuffer[1] == 0x49 && sectorBuffer[2] == 0x4C && sectorBuffer[3] == 0x45) {

      // calculate file size
      fileSize = sectorBuffer[4] << 24 | sectorBuffer[5] << 16 | sectorBuffer[6] << 8 | sectorBuffer[7];

      // allocate memory for file buffer
      fileBuffer = (unsigned char*)realloc(fileBuffer, fileSize);
      if (fileBuffer == NULL) {
        printf("Error: out of memory\n");
        free(sectorBuffer);
        return OUT_OF_MEMORY;
      }

      // copy file data from sector buffer to file buffer
      memcpy(fileBuffer, &sectorBuffer[8], SECTOR_SIZE - 8);
      fileOffset = SECTOR_SIZE - 8;

      // read additional sectors until entire file is recovered
      sectorNum++;
      while (fileOffset < fileSize) {
        if (ReadSector(devicePath, sectorNum, sectorBuffer) != SUCCESS) {
          printf("Error: unable to read sector %d from device\n", sectorNum);
          free(fileBuffer);
          free(sectorBuffer);
          return UNABLE_TO_OPEN_FILE;
        }
        bytesRead = SECTOR_SIZE;
        if (fileOffset + SECTOR_SIZE > fileSize) {
          bytesRead = fileSize - fileOffset;
        }
        memcpy(&fileBuffer[fileOffset], sectorBuffer, bytesRead);
        fileOffset += bytesRead;
        sectorNum++;
      }

      // write recovered file to disk
      outputFile = fopen(filename, "wb");
      if (outputFile == NULL) {
        printf("Error: unable to open output file: %s\n", filename);
        free(fileBuffer);
        free(sectorBuffer);
        return UNABLE_TO_OPEN_FILE;
      }
      fwrite(fileBuffer, 1, fileSize, outputFile);
      fclose(outputFile);

      // cleanup and exit
      free(fileBuffer);
      free(sectorBuffer);
      printf("File successfully recovered to: %s\n", filename);
      return SUCCESS;
    }

    // check for end of device
    if (++sectorNum == (1 << 20)) {
      printf("Error: end of device reached\n");
      free(fileBuffer);
      free(sectorBuffer);
      return UNABLE_TO_OPEN_FILE;
    }
  }

  // cleanup and exit
  free(fileBuffer);
  free(sectorBuffer);
  printf("File not found on device: %s\n", devicePath);
  return UNABLE_TO_OPEN_FILE;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: data-recovery <device-path> <output-file>\n");
    return INVALID_ARGUMENTS;
  }
  return RecoverFile(argv[1], argv[2]);
}