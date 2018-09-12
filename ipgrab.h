/*
*Author:-Pukar Giri
*Created On:-11Th September 2018 at 12:23
*File Name:-ipgrab.h
*Project Name:-Homeserver
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/

#ifndef HOMESERVER_IPGRAB_H
#define HOMESERVER_IPGRAB_H


#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <regex.h>


struct ip
    {
        char local[16];
        char broadcast[16];
    };
char *match(char *pattern, char *text);
struct ip getip();
#endif //HOMESERVER_IPGRAB_H
