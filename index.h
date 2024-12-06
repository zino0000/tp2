#ifndef INDEX_H
#define INDEX_H
  
#include "structs.h"
int write_cbloc(TOF *tof, Indexblock bloc, int position);
int read_ibloc(TOF *tof, Indexblock *bloc, int position);
Dindex search(TOF *tof, int id);
#endif // INDEX_H