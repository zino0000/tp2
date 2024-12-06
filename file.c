
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

void read_entete(TOF *tof){
    FILE *f = fopen(tof->fil, "r+b");
    fread(&(tof->ent), sizeof(Entete), 1, f);
    fclose(f);}
void write_entete(Entete e, TOF *tof){
    FILE *f = fopen(tof->fil, "r+b");
    fwrite(&(tof->ent), sizeof(Entete), 1, f);
    fflush(f);
    fclose(f);}
TOF *open_file(char *path, char mode){
    FILE *f;
    TOF *tof = (TOF *)malloc(sizeof(TOF));
    strcpy(tof->fil, path);
    switch (mode)
    {
    // ouverture d'un fichier existant
    case 'A':
        read_entete(tof);
        return tof;

    case 'N':
        f = fopen(path, "w");
        fclose(f);
        tof->ent.nbb = 0;
        write_entete(tof->ent, tof);
        return tof;
    }
}
