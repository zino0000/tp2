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
void insert_index(Custumer s, TOF *tof, Indexblock bloc, int position) {
    // Implementation...
int i = read_ibloc(tof,&bloc,position);
if (i==-1){
        bloc.nc =0;
    bloc.d[bloc.ni]=s;
       bloc.nc++;
       write_ibloc(tof,bloc,position);
        tof->ent.lid++;
        tof->ent.nbb++;
       write_entete(tof->ent,tof);

}
if(bloc.nc>=100){
    write_cbloc(tof,bloc,position);
    Indexblock a;a.ni=0;
    a.d[0] = s;
    write_cbloc(tof,a,position);
        tof->ent.lid++;
        tof->ent.nbb++;
       write_entete(tof->ent,tof);
}else{bloc.d[bloc.ni]=s;
       bloc.ni++;
       write_ibloc(tof,bloc,position);tof->ent.lid++;
      write_entete(tof->ent,tof); }

}
