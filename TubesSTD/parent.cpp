#include "parent.h"
#include <cstdio>
using namespace std;

void createListJenis(ListJ &LJ)
{
    firstJ(LJ) = NULL;
}
adrJenis createElemenJenis(adrJenis j, infotypeJ jenis)
{
    //nanti di main dicek dlu, kalo ada nama jenis yang sama, gakan manggil fungsi ini
    j = new elmJenis;
    infoJ(j) = jenis;
    nextJ(j) = NULL;
    return j;
}
bool isEmptyJ(ListJ LJ)
{
    return firstJ(LJ) == NULL;
}
void insertLastJenis(ListJ &LJ, adrJenis j)
{
    if(isEmptyJ(LJ)){
        firstJ(LJ) = j;
    } else {
        adrJenis q = firstJ(LJ);
        while(nextJ(q) != NULL) {
            q = nextJ(q);
        }
        nextJ(q) = j;
    }
}
void showJenis(ListJ LJ)
{
    adrJenis temp = firstJ(LJ);
    printf("\n%-3s| List Jenis Reimbursement: \n", "No.");
    int i = 1;
    while (temp != NULL) {
        cout << i << ". " << infoJ(temp) << endl;
        i++;
        temp = nextJ(temp);
    }
}
adrJenis searchJenis(ListJ LJ, string jenis)
{
    adrJenis j = NULL;
    if (isEmptyJ(LJ))
    {
        return NULL;
    }
    else
    {
        j = firstJ(LJ);
        while (j!=NULL)
        {
            if (infoJ(j)==jenis){
                return j;
            }
            j = nextJ(j);
        }
    }
}
void deleteFirstJenis(ListJ &LJ, adrJenis &j)
{
    j = firstJ(LJ);
    if (j==NULL)
    {
        cout << "\nList Jenis kosong.\n";
    }
    else if (nextJ(j)==NULL)
    {
        firstJ(LJ) == NULL;
    }
    else
    {
        firstJ(LJ)=nextJ(j);
        nextJ(j)=NULL;
    }

}
void deleteLastJenis(ListJ &LJ, adrJenis &j)
{
    adrJenis q = firstJ(LJ);
    if (q == NULL)
    {
        cout << "\nList Jenis kosong.\n";
    }
    else if (nextJ(q)==NULL)
    {
        j = q;
        firstJ(LJ) = NULL;
    }
    else
    {
        j = nextJ(q);
        while (nextJ(j)!=NULL)
        {
            q = j;
            j = nextJ(j);
        }
        nextJ(q) = NULL;
    }
}
void deleteAfterJenis(ListJ &LJ, adrJenis prec, adrJenis &j)
{
    // I.S. list tidak kosong. prec sudah terdefinisi suatu alamat elmJenis dalam list jenis.
    // F.S. elemen list setelah prec terhapus dari list.
    j = nextJ(prec);
    if (nextJ(j)!=NULL)
    {
        nextJ(prec) = nextJ(j);
        nextJ(j) = NULL;
    }
    else
    {
        nextJ(prec) = NULL;
    }
}
