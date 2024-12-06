#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX 100

typedef struct entete {
    int nbb;
    int lid;
} Entete;

typedef struct TOF {
    Entete ent;
    char fil[200];
} TOF;

typedef struct Game {
    int gid;
    char name[50];
    float price;
} Game;

typedef struct Custumer {
    int cid;
    char fname[50];
    char sname[50];
    char contact[50];
} Custumer;

typedef struct Date {
    int y;
    int m;
    int d;
} Date;

typedef struct Rental {
    int rid;
    Custumer a;
    Game b;
    Date ren;
    Date rut;
    float price;
} Rental;

typedef struct Rentalf {
    int rid;
    int cid;
    int gid;
    Date t1;
    Date t2;
    float price;
} Rentalf;
typedef struct Dindex{
    int block_number;
    int enbr;
    int id;
}Dindex;
typedef struct Indexblock
{
    Dindex d[MAX];
    int ni;
}Indexblock;


typedef struct cblock {
    Custumer c[MAX];
    int nc;
} Cblock;

typedef struct gblock {
    Game g[MAX];
    int nc;
} Gblock;

typedef struct rblock {
    Rentalf r[MAX];
    int nr;
} Rblock;

#endif // STRUCTS_H
