#ifndef parent_H_INCLUDED
#define parent_H_INCLUDED
#include <iostream>

#define infoJ(j) (j)->infoJ
#define nextJ(j) (j)->nextJ
#define firstJ(LJ) (LJ).firstJ

using namespace std;

typedef string infotypeJ;
typedef struct elmJenis *adrJenis;

struct ListJ
{
    adrJenis firstJ;
};

struct elmJenis
{
    infotypeJ infoJ;
    adrJenis nextJ;
};

void createListJenis(ListJ &LJ);
adrJenis createElemenJenis(adrJenis j, infotypeJ jenis);
bool isEmptyJ(ListJ LJ);
void insertLastJenis(ListJ &LJ, adrJenis j);
void showJenis(ListJ LJ);
adrJenis searchJenis(ListJ LJ, string jenis);
void deleteFirstJenis(ListJ &LJ, adrJenis &j);
void deleteLastJenis(ListJ &LJ, adrJenis &j);
void deleteAfterJenis(ListJ &LJ, adrJenis prec, adrJenis &j);



#endif // parent_H_INCLUDED
