#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct infotype_warteg {
    string id_warteg;
    string name_warteg;
};

struct infotype_makanan {
    string id_makanan;
    string name_makanan;
    int price;
};

typedef struct elm_warteg *adr_warteg;
typedef struct elm_makanan *adr_makanan;
typedef struct elm_relation *adr_relation;

struct list_warteg {
    adr_warteg first_warteg;
    adr_warteg last_warteg;
};

struct list_makanan {
    adr_makanan first_makanan;
};

struct list_relation {
    adr_relation first_relation;
};

struct elm_warteg {
    infotype_warteg info_warteg;
    adr_warteg next_warteg;
    adr_warteg prev_warteg;
};

struct elm_makanan {
    infotype_makanan info_makanan;
    adr_makanan next_makanan;
};

struct elm_relation {
    adr_warteg next_warteg;
    adr_makanan next_makanan;
    adr_relation next_relation;
};

void createListWarteg(list_warteg &w);
adr_warteg createElmWarteg(string id, string name);
void createListMakanan(list_makanan &m);
adr_makanan createElmMakanan(string id, string name, int price);
void createListRelation(list_relation &r);
adr_relation createElmRelation();

adr_warteg searchWarteg(list_warteg w, string id_warteg);
adr_makanan searchMakanan(list_makanan m, string id_makanan);
adr_relation searchRelation(list_relation r, string id_warteg, string id_makanan);

void insertWarteg(list_warteg &w, adr_warteg p);
void insertMakanan(list_makanan &m, adr_makanan q);
void insertRelation(list_relation &r, adr_relation p);

void addMakanan(list_warteg w, list_makanan m, list_relation &r, string id_warteg, string id_makanan);

void deleteElmRelation(list_relation &r, adr_relation p);
void deleteRelation(list_warteg w, list_makanan m, list_relation &r, string id_warteg, string id_makanan);
void deleteWarteg(list_warteg &w, list_relation &r, string id_warteg);

void searchWarteg_Makanan(list_makanan m,list_relation r, string id_makanan);//------
void searchMakanan_Warteg(list_warteg w, list_relation r, string id_warteg);//-------
void viewRelation(list_relation r);
void view(list_warteg w, list_relation r);

#endif // TUBES_H_INCLUDED
