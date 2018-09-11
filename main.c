#include <stdio.h>
#include"ipgrab.h"


int main()
    {
        struct ip ipaddr;
        ipaddr=getip();
        printf("%s",ipaddr.local);
    }