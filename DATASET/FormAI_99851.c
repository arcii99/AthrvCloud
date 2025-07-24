//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("\n\n\tThis program is brought to you by Bob's Discount QoS Monitoring Services!\n\n");
  
  char* service = "Internet";
  char* provider = "Comcast";
  int speed = 10;
  int latency = 50;
  
  // Let's check the quality of service for our internet connection
  printf("\tLet's check the quality of service for our %s connection with %s...", service, provider);

  // We won't be giving up our actual log in information to check these speeds. 
  //So, let's just fake our results with random values
  srand(time(NULL));
  int download = rand() % 20 + 10;
  int upload = rand() % 5 + 1;

  // Calculate the QoS based on the Speedtest.net methodology 
  float qos = (2 * download + upload) / (2 * latency);

  // Output the results of our test
  printf("\n\n\tSpeed Test Results: \n");
  printf("\t---------------------\n");
  printf("\tDownload: %d Mbps\n", download);
  printf("\tUpload: %d Mbps\n", upload);
  printf("\tLatency: %d ms\n", latency);
  printf("\t---------------------\n");
  printf("\n\tYour Quality of Service (QoS) score is: %.2f\n\n", qos);

  if (qos >= 4.0) {
    printf("\tCongratulations! Your internet connection quality of service is excellent!\n\n");
  } else if (qos >= 3.0 && qos < 4.0) {
    printf("\tYour internet connection quality of service is good, but could be better. You might want to consider an upgrade.\n\n");
  } else if (qos >= 2.0 && qos < 3.0) {
    printf("\tYour internet connection quality of service is average, but there is room for improvement. You might want to consider switching providers or upgrading your plan.\n\n");
  } else {
    printf("\tYikes! Your internet connection quality of service is very poor. You should definitely look into switching providers or upgrading your plan.\n\n");
  }

  printf("\tThank you for using Bob's Discount QoS Monitoring Services. Have a great day!\n\n");

  return 0;
}