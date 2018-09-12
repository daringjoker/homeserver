#include <stdio.h>
#include "server.h"
#include"socketsetup.h"
#include <pthread.h>





int main()
    {
        pthread_t id;
        pthread_create(&id, NULL, broadcastserver, NULL);
        pthread_join(id, NULL);
        return 0;
    }
