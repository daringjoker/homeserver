/*
*Author:-Pukar Giri
*Created On:-12Th September 2018 at 11:56
*File Name:-server.h
*Project Name:-Homeserver
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/

#ifndef HOMESERVER_SERVER_H
#define HOMESERVER_SERVER_H


#include "socketsetup.h"
#include <arpa/inet.h>
#include <unistd.h>

void *broadcastserver();
int responseServer();
#endif //HOMESERVER_SERVER_H
