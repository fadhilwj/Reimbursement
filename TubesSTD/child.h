#ifndef child_H_INCLUDED
#define child_H_INCLUDED
#include <iostream>

#define prevB(b) (b)->prevB
#define infoB(b) (b)->infoB
#define nextB(b) (b)->nextB
#define nextJ(b) (b)->nextJ
#define firstB(LB) (LB).firstB
#define lastB(LB) (LB).lastB

#include "parent.h"

using namespace std;

struct infoBiaya
{
    string id;
    string idP;
    string deskripsi;
    int jumlah;
    int biaya;
};

typedef infoBiaya infotypeB;
typedef struct elmBiaya *adrBiaya;

struct elmBiaya
{
    adrBiaya prevB;
    infotypeB infoB;
    adrBiaya nextB;
    adrJenis nextJ;
};
struct ListB
{
    adrBiaya firstB;
    adrBiaya lastB;
};

void createListBiaya(ListB &LB);
adrBiaya createElemenBiaya(ListJ &LJ, adrBiaya b, infotypeB x, string jenis);
bool isEmptyB(ListB LB);
adrBiaya searchBiayaByID(ListB LB, string id);
adrBiaya searchBiayaByJenis(ListB LB, adrJenis j);
void insertLastBiaya(ListB &LB, adrBiaya b);
void deleteFirstBiaya(ListB &LB, adrBiaya &b);
void deleteLastBiaya(ListB &LB, adrBiaya &b);
void deleteAfterBiaya(ListB &LB, adrBiaya prec, adrBiaya &b);
void deleteJenisByNama(ListJ &LJ, ListB &LB, string jenis, adrJenis &j);
void deleteBiaya(ListB &LB, adrBiaya &b);
void deleteAllBiayaByJenis(ListB &LB, adrJenis x);
void showJenisNBiaya(ListJ LJ, ListB LB);
void updateElmBiaya(ListJ LJ, ListB &LB, adrBiaya &b, string pilihan);
int totalBiaya(ListB LB);


#endif // child_H_INCLUDED
