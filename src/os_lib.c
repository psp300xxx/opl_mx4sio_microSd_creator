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

#include <stdio.h>

void list_devices() {
    #if defined(__linux__)
        printf("Eseguo il codice per Linux.\n");
        // Inserisci il codice per Linux qui
    #elif defined(_WIN32)
        printf("Eseguo il codice per Windows.\n");
        // Inserisci il codice per Windows qui
    #elif defined(__APPLE__) && defined(__MACH__)
        printf("Eseguo il codice per macOS.\n");
        // Inserisci il codice per macOS qui
    #else
        printf("Sistema operativo non supportato.\n");
    #endif
}

