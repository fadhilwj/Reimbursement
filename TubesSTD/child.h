#ifndef child_H_INCLUDED
#define child_H_INCLUDED

#define prevB(b) (b)->prevB
#define infoB(b) (b)->infoB
#define nextB(b) (b)->nextB
#define firstB(LB) (LB).firstB
#define lastB(LB) (LB).lastB

#include "parent.h"

using namespace std;

struct infoBiaya
{
    string nama;
    int id;
    string deskripsi;
    int jumlah;
    int biaya;
};

typedef infoBiaya infotypeB;
typedef struct elmBiaya *adrBiaya;

struct elmBiaya
{
    adrBiaya prevB;
    infotype infoB;
    adrBiaya nextB;
};
struct ListB
{
    adrBiaya firstB;
    adrBiaya lastB;
};

void createListBiaya(ListB &LB);
adrBiaya createElemenBiaya(adrBiaya b, infotypeB x);
bool isEmptyB(ListB LB);
adrBiaya searchBiaya(ListB LB, int id);
void insertLastBiaya(ListB &LB, adrBiaya b);
void deleteFirstBiaya(ListB &LB, adrBiaya &b);
void deleteLastBiaya(ListB &LB, adrBiaya &b);
void deleteAfterBiaya(ListB &LB, adrBiaya prec, adrBiaya &b);
deleteBiayaByIDnJenis(ListJ &LJ, string jenis, int id, adrBiaya &b)
void updateElmBiaya(ListJ &LJ, int id, string jenis, string desk, int jumlah, int biaya);


#endif // child_H_INCLUDED
