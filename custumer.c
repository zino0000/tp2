#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custumer.h"
#include "file.h"
int write_cbloc(TOF *tof, Cblock bloc, int position) {
    // Implementation...

{

    if (position == -1)
        position = 0;
    FILE *f = fopen(tof->fil, "r+b");
    if (tof->ent.nbb < position)
        return 0;
    // decaler le poiteur de lecture après l'entete
    fseek(f, sizeof(Entete) + (sizeof(Cblock) * position), SEEK_SET);
    fwrite(&bloc, sizeof(Cblock), 1, f);
    fclose(f);
    return 1;
}
}

int read_cbloc(TOF *tof, Cblock *bloc, int position) {
    // Implementation...


    if (position == -1)
        position = 0;

    FILE *f = fopen(tof->fil, "r+b");
    if (tof->ent.nbb == 0 || tof->ent.nbb < position)
        return -1;

    // decaler le poiteur de lecture après l'entete
    fseek(f, sizeof(Entete) + (sizeof(Cblock) * position), SEEK_SET);
    fread(bloc, sizeof(Cblock), 1, f);
    fclose(f);
    return 1;
}


Custumer createCustomer(char a[50], char b[50], char c[50], int i) {
    Custumer s;
    strcpy(s.fname, a);
    strcpy(s.sname, b);
    strcpy(s.contact, c);
    s.cid = i;
    return s;
}

void insert_custumer(Custumer s, TOF *tof, Cblock bloc, int position) {
    // Implementation...
int i = read_cbloc(tof,&bloc,position);
if (i==-1){
        bloc.nc =0;
    bloc.c[bloc.nc]=s;
       bloc.nc++;
       write_cbloc(tof,bloc,position);
        tof->ent.lid++;
        tof->ent.nbb++;
       write_entete(tof->ent,tof);

}
if(bloc.nc>=100){
    write_cbloc(tof,bloc,position);
    Cblock a;a.nc=0;
    a.c[0] = s;
    write_cbloc(tof,a,position);
        tof->ent.lid++;
        tof->ent.nbb++;
       write_entete(tof->ent,tof);
}else{bloc.c[bloc.nc]=s;
       bloc.nc++;
       write_cbloc(tof,bloc,position);tof->ent.lid++;
      write_entete(tof->ent,tof); }

}


void addCustomer(TOF *cfile) {
    // Implementation...
    char s[50],s1[50],s2[50];
    Cblock cb ;
    printf("give the first name of the custumer");
    scanf("%s",&s);
     printf("give the last name of the custumer");
    scanf("%s",&s1);
     printf("give contacts of the custumer");
    scanf("%s",&s2);
    Custumer cu = createCustomer(s,s1,s2,rand()%1000);
    printf("\n your id is \n: %d \n",cu.cid);
    insert_custumer(cu,cfile,cb,cfile->ent.nbb-1);
    // Implement customer addition logic here
}


Custumer searchcust(TOF *tof, int id) {
    // Implementation...

int i =0;Cblock cb;int j =0;
while(i<tof->ent.nbb){
   if(read_cbloc(tof,&cb,i) == -1){
    printf("error"); exit (1) ;
    }else{j=0;
        while(j<cb.nc){
            if (id==cb.c[j].cid){
                return cb.c[j];
            }
            j++;
        }

    }
   i++;
}
exit (1);
}


void displayCustomers(TOF *tof) {
    // Implementation...
    printf("Displaying the customers list...\n");
    int i =0;Cblock cb;int j =0;
while(i<tof->ent.nbb){
   if(read_cbloc(tof,&cb,i) == -1){
    printf("error"); exit (1) ;
    }else{j=0;
        while(j<cb.nc){
           printf("first name: %s \n second name %s\n contacts :%s \n ID:%d \n",cb.c[j].fname,cb.c[j].sname,cb.c[j].contact,cb.c[j].cid);
            j++;
        }

    }
   i++;
}


}
