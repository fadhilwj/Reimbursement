#include "child.h"
#include <iostream>

using namespace std;

void createListBiaya(ListB &LB)
{
    //I.S. ListB terdefinisi belum terinisialisasi atau belum siap digunakan, struktur data untuk menyimpan data pada list biaya belum teralokasikan atau dalam keadaan kosong
//F.S. ListB terinisialisasi sebagai list kosong yang siap digunakan, semua atribut awal dari ListB di set NULL
    first(LB) = NULL;
    last(LB) = NULL;
}
adrBiaya createElemenBiaya(adrBiaya b, infotypeB x)
{
    //I.S. terdefinisi b suatu alamat biaya yang akan diaklokasi dengan x yang akan menjadi infotypeB dari elmBiaya b.
    //F.S. alamat elmBiaya b berhasil dialokasi dan dikembalikan
    b = new elmBiaya;
    info(b) = infotypeB;
    return b;
}
bool isEmptyB(ListB LB)
{
    //I.S. List LB telah terdefinisi, namun belum diketahui apakah list tersebut kosong atau tidak, pointer first pada list LB menunjuk ke elemen pertama atau bernilai NULL
//F.S. Fungsi mengembalikan nilai true jika list LB kosong, fungsi mengembalikan nilai false juka list LB memiliki setidaknya satu elemen
    return (firstB(LB)==NULL and lastB(LB)==NULL);
}
void insertLastBiaya(ListB &LB, adrBiaya b)
{
    //I.S. list LB telah terdefinisi dapat berupa list kosong atau berisi beberapa elemen, adrBiaya b adalah pointer ke elemen jenis baru yang telah teralokasi dan akan ditambahkan ke akhir list, elemen baru belum dimasukkan ke dalam list.
// F.S elemen jenis yang direferensikan oleh b telah ditambahkan ke akhir list LB, jika list kosong sebelumnya, elemen baru menjadi elemen pertama. jika list tidak kosong, elemen terakhir sebelumnya kini menunjuk ke elemen baru sebagai next

    if (firstB(LB) == NULL)
    {
        firstB(LB) = b;
        lastB(LB) = b;
    }
    else
    {
        nextB(lastB(LB))=b;
        prevB(b)=lastB(LB);
        lastB(LB)=b;
    }
}
adrBiaya searchBiaya(ListB LB, int id)
{
    adrBiaya b = firstB(LB));
    if (b!=NULL)
    {
        while (b!=NULL)
        {
            if (infoB(b).id==id)
            {
                return b;
            }
            b = nextB(b);
        }
    }
    else
    {
        cout << "\nList Biaya pada List Jenis kosong.\n";
    }
    cout << "\nData biaya dengan id " << id << " tidak ditemukan.\n";
    return b;
}
void deleteFirstBiaya(ListB &LB, adrBiaya &b)
{
    if (isEmptyB(LB))
    {
        cout << "\nList Biaya kosong.\n"
    }
    else if (firstB(LB)==lastB(LB))
    {
        b = firstB(LB);
        firstB(LB) =  NULL;
        lastB(LB) = NULL;
    }
    else
    {
        b = firstB(LB);
        firstB(LB) = nextB(b);
        nextB(b) =  NULL;
        prev(firstB(LB) = NULL);
    }
}
void deleteLastBiaya(ListB &LB, adrBiaya &b)
{
    if (isEmptyB(LB))
    {
        cout << "\nList Biaya kosong.\n"
    }
    else if (firstB(LB)==lastB(LB))
    {
        b = lastB(LB);
        firstB(LB) =  NULL;
        lastB(LB) = NULL;
    }
    else
    {
        b = lastB(LB);
        lastB(LB) = prevB(b);
        prevB(b) =  NULL;
        nextB(lastB(LB) = NULL);
    }
}
void deleteAfterBiaya(ListB &LB, adrBiaya prec, adrBiaya &b)
{
    if (isEmptyB(LB))
    {
        cout << "\nList Biaya kosong.\n";
    }
    else if (firstB(LB)==lastB(LB))
    {
        b = lastB(LB);
        firstB(LB) =  NULL;
        lastB(LB) = NULL;
    }
    else if (next(prec)!=lastB(LB))
    {
        b = nextB(prec);
        nextB(prec) = lastB(LB);
        prevB(LastB(LB)) = prec;
        nextB(b) = NULL;
        prevB(b) = NULL;
    }
    else
    {
        b = lastB(LB);
        lastB(LB) = prevB(b);
        prevB(b) =  NULL;
        nextB(lastB(LB) = NULL);
    }
}
void deleteBiayaByIDnJenis(ListJ &LJ, string jenis, int id, adrBiaya &b)
{
    if (isEmptyJ(LJ))
    {
        cout << "\nList Jenis kosong.\n";
    }
    else
    {
        adrJenis j = searchJenis(LJ,jenis);
        if (j==NULL)
        {
            cout << "\nJenis tidak ditemukan.\n";
        }
        else
        {
            listb = lB(j)
            adrBiaya b = searchBiaya(listb,id);
            if (b == NULL)
            {
                cout << "\nData biaya dengan id tersebut tidak ditemukan.\n";
            }
            else if (b == firstB(listb))
            {
                deleteFirstBiaya(listb,b);
            }
            else if (b == lastB(listb))
            {
                deleteLastBiaya(listb, b);
            }
            else
            {
                deleteAfterBiaya(listb, prev(b),b);
            }
        }
    }

}
void updateElmBiaya(ListJ &LJ, int id, string jenis, string desk, int jumlah, int biaya)
{

}

