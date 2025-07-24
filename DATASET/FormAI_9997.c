//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SSID_LEN 32
#define MAX_SIGNAL_STRENGTH 100
#define MAX_TIME_INTERVAL_SEC 10

typedef struct WifiAP
{
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} WifiAP;

void _clear_screen()
{
    system("clear");
}

void _get_wpa_cli_output(char* output)
{
    FILE* fp;
    char path[1035];
    fp = popen("wpa_cli scan_results", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        strcat(output, path);
    }
    pclose(fp);
}

void _parse_wifi_data(char* wifi_scan_results, WifiAP* wifi_data, int* num_wifi_aps)
{
    char* token = strtok(wifi_scan_results, "\n");
    while (token != NULL) {
        char* ssid = strtok(token, "\t");
        char* bssid = strtok(NULL, "\t");
        char* frequency = strtok(NULL, "\t");
        char* signal_strength = strtok(NULL, "\t");
        if (ssid != NULL && bssid != NULL && signal_strength != NULL) {
            strcpy(wifi_data[*num_wifi_aps].ssid, ssid);
            wifi_data[*num_wifi_aps].signal_strength = atoi(signal_strength);
            (*num_wifi_aps)++;
        }
        token = strtok(NULL, "\n");
    }
}

void print_wifi_data(WifiAP wifi_data[], int num_wifi_aps)
{
    _clear_screen();
    printf("SSID\t\tSignal Strength\n");
    printf("==========================================\n");
    for (int i = 0; i < num_wifi_aps; i++) {
        printf("%s\t\t%d\n", wifi_data[i].ssid, wifi_data[i].signal_strength);
    }
}

void analyze_wifi_signal_strength()
{
    char wifi_scan_results[65535] = {0};
    WifiAP wifi_data[100] = {0};
    int num_wifi_aps = 0;
    int max_signal_strength = 0;
    char strongest_ssid[MAX_SSID_LEN] = {0};

    _get_wpa_cli_output(wifi_scan_results);
    _parse_wifi_data(wifi_scan_results, wifi_data, &num_wifi_aps);
    print_wifi_data(wifi_data, num_wifi_aps);

    for (int i = 0; i < num_wifi_aps; i++) {
        if (wifi_data[i].signal_strength > max_signal_strength) {
            max_signal_strength = wifi_data[i].signal_strength;
            strcpy(strongest_ssid, wifi_data[i].ssid);
        }
    }
    printf("\nStrongest Wi-Fi Signal: %s (%d)\n", strongest_ssid, max_signal_strength);
}

int main()
{
    int time_interval_sec = MAX_TIME_INTERVAL_SEC;
    int num_iterations = 0;

    while (1) {
        analyze_wifi_signal_strength();
        num_iterations++;
        if (num_iterations * time_interval_sec >= MAX_TIME_INTERVAL_SEC) {
            num_iterations = 0;
            sleep(time_interval_sec);
        }
    }

    return 0;
}