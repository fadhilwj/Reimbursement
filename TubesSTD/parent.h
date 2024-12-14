#ifndef parent_H_INCLUDED
#define parent_H_INCLUDED

#define prevJ(j) (j)->prevJ
#define infoJ(j) (j)->infoJ
#define nextB(j) (j)->nextB
#define nextJ(j) (j)->nextJ
#define firstJ(LJ) (LJ).firstJ
#define lastJ(LJ) (LJ).lastJ

#include "child.h"

using namespace std;

typedef string infotypeJ;
typedef struct elmJenis *adrJenis;

struct elmJenis
{
    adrJenis prevJ;
    infotype infoJ;
    ListB lB;
    adrJenis nextJ;
};
struct ListJ
{
    adrJenis firstB;
    adrJenis lastB;
};

void createListJenis(ListJ &LJ);
adrJenis createElemenJenis(adrJenis j, infotypeJ x);
bool isEmptyJ(ListJ LJ);
void insertLastJenis(ListJ &LJ, adrJenis j);
void showJenis(ListJ LJ);
adrJenis searchJenis(ListJ LJ, string jenis);
void deleteFirstJenis(ListJ &LJ, adrJenis &j);
void deleteLastJenis(ListJ &LJ, adrJenis &j);
void deleteAfterJenis(ListJ &LJ, adrJenis &j);
void deleteJenisByNama(ListJ &LJ, string jenis, adrJenis &j);
void showJenisNBiaya(ListJ LJ, ListB LB);
int totalBiaya(ListJ LJ);


#endif // parent_H_INCLUDED
