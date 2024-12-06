#ifndef RENTAL_H
#define RENTAL_H

#include "structs.h"
int daysInMonth(int month, int year);
int dateDifference( Date d1, Date d2) ;
int  write_rbloc(TOF *tof, Rblock bloc, int position);
int read_rbloc(TOF *tof, Rblock *bloc, int position);
Rental createRental(Custumer s, Game i, Date f, Date l);
void insert_rent(Rentalf s, TOF *tof, Rblock bloc, int position);
Rentalf searchRental(TOF *tof,int id);
void displayRental(const Rental *rental);
void displayRentals(TOF *tof, TOF *ctof, TOF *gtof);
void addRental(TOF *rfile, TOF *cfile, TOF *gfile);

#endif // RENTAL_H
