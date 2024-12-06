#ifndef CUSTUMER_H
#define CUSTUMER_H

#include "structs.h"

int write_cbloc(TOF *tof, Cblock bloc, int position);
int read_cbloc(TOF *tof, Cblock *bloc, int position);
Custumer createCustomer(char a[50], char b[50], char c[50], int i);
void insert_custumer(Custumer s, TOF *tof, Cblock bloc, int position);
void addCustomer(TOF *cfile);
Custumer searchcust(TOF *tof, int id);
void displayCustomers(TOF *tof);

#endif // CUSTUMER_H
