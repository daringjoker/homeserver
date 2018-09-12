#include <stdio.h>
#include "server.h"
#include <pthread.h>





int main()
    {
        pthread_t id;
        pthread_create(&id, NULL, broadcastserver, NULL);
        responseServer();
        pthread_join(id, NULL);
        return 0;
    }
