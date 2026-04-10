#include "writeval.h"
#include <string.h>
#include <stdio.h>

void *nextAlignedAddress(void *faddr, size_t size) {
    size_t addr = (size_t) faddr;
    if (addr % size == 0) {
        return faddr;
    } else {
        return (void *)(addr + (size - addr % size));
    }
}

void *writeValue(void *writeLoc, const char *type, void *payload) {
    char *loc = (char *) writeLoc;
    
    if (strcmp(type, "int") == 0) {
        *loc = 0;  
        loc++;    
        loc = (char *) nextAlignedAddress(loc, sizeof(int));
        memcpy(loc, payload, sizeof(int));
        return loc + sizeof(int);
    } else if (strcmp(type, "char") == 0) {
        *loc = 1;  
        loc++;
        loc = (char *) nextAlignedAddress(loc, sizeof(char));
        memcpy(loc, payload, sizeof(char));
        return loc + sizeof(char);
    } else if (strcmp(type, "ptr") == 0) {
        *loc = 2; 
        loc++;
        loc = (char *) nextAlignedAddress(loc, sizeof(void *));
        memcpy(loc, payload, sizeof(void *));
        return loc + sizeof(void *);
    } else if (strcmp(type, "str") == 0) {
        *loc = 3;  
        loc++;
        // no alignment needed for char
        memcpy(loc, payload, strlen((char *)payload) + 1);
        return loc + strlen((char *)payload) + 1;
    }
    return writeLoc;
}


void printValues(void *dataStart){
    unsigned char *loc = (unsigned char *) dataStart;
    int count = 0; 

    while (*loc != 0xFF) { 
        unsigned char type = *loc;
        loc++;
        if (type == 0) { 
            loc = (unsigned char *) nextAlignedAddress(loc, sizeof(int));
            int value;
            memcpy(&value, loc, sizeof(int));
            printf("Value %d at %p: %d\n", count, (void *)loc, value);
            loc += sizeof(int);
        } else if (type == 1) { 
            loc = (unsigned char *) nextAlignedAddress(loc, sizeof(char));
            char value;
            memcpy(&value, loc, sizeof(char));
            printf("Value %d at %p: %c\n", count, (void *)loc, value);
            loc += sizeof(char);
        } else if (type == 2) { 
            loc = (unsigned char *) nextAlignedAddress(loc, sizeof(void *));
            void *value;
            memcpy(&value, loc, sizeof(void *));
            printf("Value %d at %p: %p\n", count, (void *)loc, value);
            loc += sizeof(void *);
        } else if (type == 3) { 
            printf("Value %d at %p: \"%s\"\n", count, (void *)loc, (char *)loc);
            loc += strlen((char *)loc) + 1; 
        }
        count++;
    }
}