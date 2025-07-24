//FormAI DATASET v1.0 Category: File system simulation ; Style: multi-threaded
#include <stdio.h> 
#include <pthread.h> 
#include <unistd.h> 
  
void* thread1(void * arg) 
{ 
    printf("Thread 1 is running\n"); 
    printf("Creating file system.. \n"); 
  
    // Creating file system 
    system("gcc mkfs.c -o mkfs"); 
    system("./mkfs -t EXT2 -b 1024 -F testfile"); 
  
    printf("File system created.\n"); 
    pthread_exit(NULL); 
} 
  
void* thread2(void * arg) 
{ 
    printf("\nThread 2 is running\n"); 
    printf("Mounting file system..\n"); 
  
    // Mounting file system 
    system("gcc mount.c -o mount"); 
    system("./mount testfile /mnt/"); 
  
    printf("File system mounted successfully.\n"); 
    pthread_exit(NULL); 
} 
  
void* thread3(void * arg) 
{ 
    printf("\nThread 3 is running\n"); 
    printf("Copying files to file system..\n"); 
  
    // Copying files to file system 
    system("gcc cp.c -o cp"); 
    system("./cp -r /home/user/files /mnt/"); 
  
    printf("File copying completed.\n"); 
    pthread_exit(NULL); 
} 
  
int main() 
{ 
    pthread_t th1, th2, th3; 
  
    // Creating three threads 
    pthread_create(&th1, NULL, thread1, NULL); 
    pthread_create(&th2, NULL, thread2, NULL); 
    pthread_create(&th3, NULL, thread3, NULL); 
  
    // Joining threads 
    pthread_join(th1, NULL); 
    pthread_join(th2, NULL); 
    pthread_join(th3, NULL); 
  
    return 0; 
}