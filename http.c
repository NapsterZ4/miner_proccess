//
// Created by Pedro Guzmán on 12/10/19.
//
#include "http.h"

int send_http_post(char * resource, char * payload, char * contentType){

    CURL* httpClient = curl_easy_init();
    CURLcode ret;
    int result = -1;
    struct curl_slist* headers;

    if(httpClient){

        // SETUP HEADER PARAMS ----------

        char accept[50] = "Accept: ";
        strcat(accept, contentType);
        char encoding[strlen("charset: utf-8")] = "charset: utf-8";



        // SETUP URI --------------------
        char endpoint[250] = "https://metrics.appsecurity.info/api/v1";
        strcat(endpoint, resource);



        // SETUP HEADERS ----------------
        headers = NULL;
        headers = curl_slist_append(headers, accept);
        headers = curl_slist_append(headers, encoding);
        headers = curl_slist_append(headers, "Content-Type: application/json");

        // POST DATA
        curl_easy_setopt(httpClient, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(httpClient, CURLOPT_URL, endpoint);
        curl_easy_setopt(httpClient, CURLOPT_USERAGENT,  "Linux PerfMiner");
        curl_easy_setopt(httpClient, CURLOPT_POST, 1L);
        curl_easy_setopt(httpClient, CURLOPT_POSTFIELDS, payload);
        curl_easy_setopt(httpClient, CURLOPT_POSTFIELDSIZE, strlen(payload));
        curl_easy_setopt(httpClient, CURLOPT_VERBOSE, 1L);

        // PERFORM POST OPERATION ------
        ret = curl_easy_perform(httpClient);
        if(ret == CURLE_OK){
            result = 0;
        } // IF ENDS
        else{
            printf("Error %s \n", curl_easy_strerror(ret));
        } // ELSE ENDS

        // CLEANUP ---------------------
        curl_slist_free_all(headers);
        curl_easy_cleanup(httpClient);
        httpClient = NULL;
        payload = NULL;
        resource = NULL;
    } // IF ENDS
    else{
        printf("No CURL!");
    }
    return result;
}

