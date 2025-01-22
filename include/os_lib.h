#ifndef LDMOSLIB_H
#define LDMOSLIB_H

typedef enum OperatingSystemEntry {
    LINUX = 0,
    WINDOWS = 1,
    MAC_OS = 2,
    INVALID = 3
} OSEntry;

OSEntry detectCurrentOS();

#endif // LDMQUEUE_H
