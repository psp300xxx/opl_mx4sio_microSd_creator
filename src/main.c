#include "../include/ldm_queue.h"
#include "../include/os_lib.h"
#include <stdlib.h>
#include <stdio.h>


int main(){
    printf("Hello! This util will help you in creating a valid MicroSD card for loading games in OPL!\n");
    OSEntry operatingSystem = detectCurrentOS();
    if( operatingSystem==INVALID ){
        printf("You OS is not supported yet\n");
        return 0;
    }
    return 0;
}