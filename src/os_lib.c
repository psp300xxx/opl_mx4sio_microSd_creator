#include <stdio.h>
#include "../include/os_lib.h"
#include <stdlib.h> // Per malloc e free

OSEntry detectCurrentOS(){
    #if defined(__linux__)
        return LINUX;
        // Inserisci il codice per Linux qui
    #elif defined(_WIN32)
        return WINDOWS;
        // Inserisci il codice per Windows qui
    #elif defined(__APPLE__) && defined(__MACH__)
        return MAC_OS;
        // Inserisci il codice per macOS qui
    #else
        return INVALID;
    #endif
}
