//FormAI DATASET v1.0 Category: Browser Plugin ; Style: calm
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

/* Callback function for receiving data from the server */
static size_t incoming_data(void *buffer, size_t size, size_t nitems, void *mydata)
{
    char *data = (char *)buffer;
    FILE *fp = (FILE *)mydata;
    size_t num_bytes = size * nitems;
    size_t wrote;

    if (fp == NULL)
    {
        return num_bytes;
    }

    wrote = fwrite(buffer, size, nitems, fp);

    return wrote;
}

/* Function to download the contents of a URL to a file */
int download_file(char *url, char *filename)
{
    CURL *curl_handle;
    CURLcode res;
    FILE *fp;

    curl_global_init(CURL_GLOBAL_ALL);

    /* Create the curl handle */
    curl_handle = curl_easy_init();

    /* Set URL to retrieve */
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);

    /* Set callback function for incoming data */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, incoming_data);

    /* Set data destination */
    fp = fopen(filename, "wb");
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, fp);

    /* Perform the request */
    res = curl_easy_perform(curl_handle);

    /* Close file and curl handle */
    fclose(fp);
    curl_easy_cleanup(curl_handle);

    /* Check for errors */
    if (res != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return 1;
    }

    curl_global_cleanup();

    return 0;
}

/* Function to create a browser plugin */
int create_plugin(char *name)
{
    FILE *fp;
    char filename[256];

    /* Build filename from name */
    snprintf(filename, sizeof(filename), "%s.plugin", name);

    /* Create plugin file */
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error creating plugin file: %s\n", filename);
        return 1;
    }

    /* Plugin header */
    fprintf(fp, "/* %s plugin */\n", name);
    fprintf(fp, "#include <npapi.h>\n");
    fprintf(fp, "#include <npruntime.h>\n\n");

    /* Plugin entry points */
    fprintf(fp, "/* Plugin entry points */\n");
    fprintf(fp, "NP_EXPORT(NPError) NP_GetEntryPoints(NPPluginFuncs* pFuncs)\n");
    fprintf(fp, "{\n");
    fprintf(fp, "    /* Set function pointers */\n");
    fprintf(fp, "    pFuncs->version = (NP_VERSION_MAJOR << 8) | NP_VERSION_MINOR;\n");
    fprintf(fp, "    pFuncs->newp = my_newp;\n");
    fprintf(fp, "    pFuncs->destroy = my_destroy;\n");
    fprintf(fp, "    pFuncs->getvalue = my_getvalue;\n");
    fprintf(fp, "    pFuncs->setvalue = my_setvalue;\n");
    fprintf(fp, "    pFuncs->event = my_event;\n");
    fprintf(fp, "    pFuncs->urlnotify = my_urlnotify;\n");
    fprintf(fp, "    pFuncs->javaClass = NULL;\n");
    fprintf(fp, "    pFuncs->getJavaEnv = NULL;\n");
    fprintf(fp, "    pFuncs->getJavaPeer = NULL;\n");
    fprintf(fp, "    pFuncs->hasMethod = NULL;\n");
    fprintf(fp, "    pFuncs->invoke = NULL;\n");
    fprintf(fp, "    pFuncs->invokeDefault = NULL;\n");
    fprintf(fp, "    pFuncs->invalidate = NULL;\n");
    fprintf(fp, "    pFuncs->setWindow = NULL;\n");

    /* Plugin footer */
    fprintf(fp, "    return NPERR_NO_ERROR;\n");
    fprintf(fp, "}\n");
    fprintf(fp, "/* End of %s plugin */\n", name);

    fclose(fp);

    return 0;
}

int main(int argc, char *argv[])
{
    char url[256], filename[256], plugin_name[256];

    /* Get URL and output file name */
    printf("Enter URL to download: ");
    fgets(url, 256, stdin);
    url[strcspn(url, "\n")] = 0;

    printf("Enter filename to save to: ");
    fgets(filename, 256, stdin);
    filename[strcspn(filename, "\n")] = 0;

    /* Download the file */
    if (download_file(url, filename) != 0)
    {
        return 1;
    }

    /* Get name for new plugin */
    printf("Enter name for new plugin: ");
    fgets(plugin_name, 256, stdin);
    plugin_name[strcspn(plugin_name, "\n")] = 0;

    /* Create the plugin */
    if (create_plugin(plugin_name) != 0)
    {
        return 1;
    }

    printf("Plugin %s.plugin created successfully!\n", plugin_name);

    return 0;
}