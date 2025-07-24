//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure to hold the download information
struct dl_info {
  double speed;
  double time_taken;
  double size;
  char metric[3];
};

// Callback function to handle the data received during download
size_t write_data(void *ptr, size_t size, size_t nmemb, struct dl_info *info)
{
  double download_size = size * nmemb;
  info->size += download_size;
  info->time_taken = (double)info->size / info->speed;

  return size * nmemb;
}

// Function to test the internet speed
struct dl_info test_speed(double speed)
{
  CURL *curl;
  CURLcode res;
  struct dl_info info = { .speed = speed, .time_taken = 0, .size = 0, .metric = "B/s" };

  // Initiate curl session and set speed limit
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://speedtest.tele2.net/50MB.zip"); // Test file
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // Set callback function
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &info); // Pass info struct to the callback function
    curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, speed); // Set speed limit
    curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, 30L); // Set time duration to achieve the speed limit
    res = curl_easy_perform(curl); // Initiate the download

    // Check for errors
    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
  }

  // Convert the size and download speed to appropriate metric
  if(info.size >= 1000000000) {
    info.size /= 1000000000.0;
    strcpy(info.metric, "GB/s");
  }
  else if(info.size >= 1000000) {
    info.size /= 1000000.0;
    strcpy(info.metric, "MB/s");
  }
  else if(info.size >= 1000) {
    info.size /= 1000.0;
    strcpy(info.metric, "KB/s");
  }

  return info;
}

int main(void) 
{
  double speed = 100000; // Set initial speed limit to 100 KB/s
  struct dl_info info;

  // Loop until speed limit achieves
  while(1) {
    printf("Testing internet speed at %.2lf %s...\n", speed, "B/s");
    info = test_speed(speed);

    printf("Download speed: %.2lf %s\n", info.speed, info.metric);
    printf("Download size: %.2lf MB\n", info.size / 1000.0 / 1000.0);
    printf("Time taken: %.2lf s\n\n", info.time_taken);

    // Check if speed limit achieved
    if(info.speed >= speed) {
      printf("Speed limit achieved at %.2lf %s\n", speed, "B/s");
      break;
    }
    speed += 100000; // Increment speed limit by 100 KB/s
  }

  return 0;
}