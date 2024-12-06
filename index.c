#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
int write_cbloc(TOF *tof, Indexblock bloc, int position) {
    // Implementation...

{

    if (position == -1)
        position = 0;
    FILE *f = fopen(tof->fil, "r+b");
    if (tof->ent.nbb < position)
        return 0;
    // decaler le poiteur de lecture après l'entete
    fseek(f, sizeof(Entete) + (sizeof(Indexblock) * position), SEEK_SET);
    fwrite(&bloc, sizeof(Indexblock), 1, f);
    fclose(f);
    return 1;
}
}
int read_ibloc(TOF *tof, Indexblock *bloc, int position) {
    // Implementation...


    if (position == -1)
        position = 0;

    FILE *f = fopen(tof->fil, "r+b");
    if (tof->ent.nbb == 0 || tof->ent.nbb < position)
        return -1;

    // decaler le poiteur de lecture après l'entete
    fseek(f, sizeof(Entete) + (sizeof(Indexblock) * position), SEEK_SET);
    fread(bloc, sizeof(Indexblock), 1, f);
    fclose(f);
    return 1;
}

Dindex search(TOF *tof, int id) {
    // Implementation...

int i =0;Indexblock cb;int j =0;
while(i<tof->ent.nbb){
   if(read_Ibloc(tof,&cb,i) == -1){
    printf("error"); exit (1) ;
    }else{j=0;
        while(j<cb.ni){
            if (id==cb.d[j].id){
                return cb.d[j];
            }
            j++;
        }

    }
   i++;
}
exit (1);
}
