#ifndef GAME_H
#define GAME_H

#include "structs.h"

int write_gbloc(TOF *tof, Gblock bloc, int position);
int read_gbloc(TOF *tof, Gblock *bloc, int position);
Game create_game(int gid, const char *name, float price);
void insert_g(Game s, TOF *tof, Gblock bloc, int position);
void addGame(TOF *gfile);
Game searchgame(TOF *tof, int id);
void displayGames(TOF *tof);

#endif // GAME_H
