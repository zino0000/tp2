#ifndef FILE_H
#define FILE_H

#include "structs.h" // To include the structure definitions

// Function declarations
void read_entete(TOF *tof);
void write_entete(Entete e, TOF *tof);
TOF *open_file(char *path, char mode);

#endif // FILE_H
