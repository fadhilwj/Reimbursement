#include "child.h"
#include "parent.h"
#include <iostream>

using namespace std;

void createListBiaya(ListB &LB)
{
    //I.S. ListB terdefinisi belum terinisialisasi atau belum siap digunakan, struktur data untuk menyimpan data pada list biaya belum teralokasikan atau dalam keadaan kosong
//F.S. ListB terinisialisasi sebagai list kosong yang siap digunakan, semua atribut awal dari ListB di set NULL
    firstB(LB) = NULL;
    lastB(LB) = NULL;
}
adrBiaya createElemenBiaya(ListJ &LJ, adrBiaya b, infotypeB x, string jenis)
{
    //I.S. terdefinisi b suatu alamat biaya yang akan diaklokasi dengan x yang akan menjadi infotypeB dari elmBiaya b.
    //F.S. alamat elmBiaya b berhasil dialokasi dan dikembalikan
    b = new elmBiaya;
    infoB(b) = x;
    nextB(b) = NULL;
    adrJenis j = searchJenis(LJ,jenis);
    if (j==NULL)
    {
        j = createElemenJenis(j, jenis);
        insertLastJenis(LJ,j);
    }
    nextJ(b) = j;
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
adrBiaya searchBiayaByID(ListB LB, string id)
{
    adrBiaya b = firstB(LB);
    if (!isEmptyB(LB))
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
        return NULL;
    }
    return b;
}
adrBiaya searchBiayaByJenis(ListB LB, adrJenis x)
{
    adrBiaya b = firstB(LB);
    if (isEmptyB(LB))
    {
        cout << "\nList Biaya kosong.\n";
    }
    else
    {
        while (b!=NULL)
        {
            if (nextJ(b)==x)
            {
                return b;
            }
            b = nextB(b);
        }
    }
    return b;
}
void deleteFirstBiaya(ListB &LB, adrBiaya &b)
{
    if (isEmptyB(LB))
    {
        cout << "\nList Biaya kosong.\n";
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
        nextB(b) = NULL;
        prevB(firstB(LB)) = NULL;
    }
    nextJ(b) = NULL;
    cout << "\nrelasi terhapus" << endl;
}
void deleteLastBiaya(ListB &LB, adrBiaya &b)
{
    if (isEmptyB(LB))
    {
        cout << "\nList Biaya kosong.\n";
    }
    else if (firstB(LB)==lastB(LB))
    {
        b = lastB(LB);
        firstB(LB) = NULL;
        lastB(LB) = NULL;
    }
    else
    {
        b = lastB(LB);
        lastB(LB) = prevB(b);
        prevB(b) = NULL;
        nextB(lastB(LB)) = NULL;
    }
    nextJ(b) = NULL;
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
    else if (b==lastB(LB))// delete Last
    {
        b = lastB(LB);
        lastB(LB) = prevB(b);
        prevB(b) =  NULL;
        nextB(lastB(LB)) = NULL;
    }
    else //ini deleteAfter
    {
        nextB(prec) = nextB(b);
        prevB(nextB(b)) = prec;
        nextB(b) = NULL;
        prevB(b) = NULL;
    }
    nextJ(b) = NULL;
}
void deleteBiaya(ListB &LB, adrBiaya &b)
{
    // I.S. List tidak kosong. alamat b yang akan dihapus sudah diketahui.
    cout << infoB(b).id << endl;
    if (b == firstB(LB))
    {
        deleteFirstBiaya(LB,b);
        cout << "delete first";
    }
    else if (b == lastB(LB))
    {
        deleteLastBiaya(LB, b);
        cout << "delete last";
    }
    else
    {
        deleteAfterBiaya(LB, prevB(b), b);
        cout << "delete after";
    }

    /*error setelah delete:
    delete after: ga bisa*/
}
void deleteJenisByNama(ListJ &LJ, ListB &LB, string jenis, adrJenis &j)
{
    adrJenis x = searchJenis(LJ,jenis);
    if (x==NULL)
    {
        cout << "\nNama jenis tidak ditemukan.\n";
    }
    else
    {
        // menghapus biaya yang memliki relasi dengan jenis tsb
        deleteAllBiayaByJenis(LB, x);

        // menghapus jenis
        if (x == firstJ(LJ))
        {
            deleteFirstJenis(LJ, j);
        }
        else if (nextJ(x)==NULL)
        {
            deleteLastJenis(LJ,j);
        }
        else
        {
            adrJenis prec = firstJ(LJ);
            j = nextJ(prec);
            while (j!=x)
            {
                prec = j;
                j = nextJ(j);
            }
            deleteAfterJenis(LJ,prec,j);
        }
    }
}
void deleteAllBiayaByJenis(ListB &LB, adrJenis x)
{
    // I.S. nilai alamat jenis x sudah diketahui.
    adrBiaya b = searchBiayaByJenis(LB,x);
    int i=1;
    while (b!=NULL)
    {
        deleteBiaya(LB,b);
        b = searchBiayaByJenis(LB,x);
        cout << i << endl;
        i++;
    }
}
void updateElmBiaya(ListJ LJ, ListB &LB, adrBiaya &b, string pilihan)
{
    infotypeB tmp = infoB(b);
    infotypeJ newJenis;
    if (pilihan == "1")
    {
        // id
        cout << "\nInput 'x' untuk membatalkan update.\n";
        cout << "Masukkan ID Biaya yang baru: ";
        cin >> tmp.id;

        while (searchBiayaByID(LB,tmp.id) != NULL)
        {
            cout << "\nID Biaya sudah terdaftar. (ID Biaya harus unik)\n";
            cout << "Masukkan ID Biaya yang baru: ";
            cin >> tmp.id;
        }
        if (tmp.id=="x")
        {
            tmp.id = infoB(b).id;
        }
    }
    else if (pilihan == "2")
    {
        // idP
        cout << "Masukkan ID Pegawai yang baru: ";
        cin >> tmp.idP;
    }
    else if (pilihan == "3")
    {
        // deskripsi
        cout << "Masukkan Deskripsi yang baru: ";
        cin.ignore();
        getline(cin, tmp.deskripsi);
    }
    else if (pilihan == "4")
    {
        // jumlah
        cout << "Masukkan Jumlah yang baru: ";
        cin >> tmp.jumlah;
    }
    else if (pilihan == "5")
    {
        // biaya
        cout << "Masukkan Total Biaya yang baru: ";
        cin >> tmp.biaya;
    }
    else if (pilihan == "6")
    {
        // kategori jenis
        cout << "Masukkan Jenis Biaya yang baru: ";
        cin >> newJenis;
        adrJenis j = searchJenis(LJ,newJenis);
        while (j==NULL)
        {
            cout << "\nNama jenis tidak ditemukan.\n";
            cout << "Masukkan Jenis Biaya yang baru: ";
            cin >> newJenis;
            adrJenis j = searchJenis(LJ,newJenis);
        }
        nextJ(b) = j;

    }
    else if (pilihan == "7")
    {
        // all
        cout << "\nInput 'x' untuk membatalkan update.\n";
        cout << "Masukkan ID Biaya yang baru: ";
        cin >> tmp.id;

        while (searchBiayaByID(LB,tmp.id) != NULL)
        {
            cout << "\nID Biaya sudah terdaftar. (ID Biaya harus unik)\n";
            cout << "Masukkan ID Biaya yang baru: ";
            cin >> tmp.id;
        }
        if (tmp.id=="x")
        {
            tmp.id = infoB(b).id;
        }
        cout << "Masukkan ID Pegawai yang baru: ";
        cin >> tmp.idP;
        cout << "Masukkan Deskripsi yang baru: ";
        cin.ignore();
        getline(cin, tmp.deskripsi);
        cout << "Masukkan Jumlah yang baru: ";
        cin >> tmp.jumlah;
        cout << "Masukkan Total Biaya yang baru: ";
        cin >> tmp.biaya;
        cout << "Masukkan Jenis Biaya yang baru: ";
        cin >> newJenis;
        adrJenis j = searchJenis(LJ,newJenis);
        while (j==NULL)
        {
            cout << "\nNama jenis tidak ditemukan.\n";
            cout << "Masukkan Kategori Jenis yang baru: ";
            cin >> newJenis;
            adrJenis j = searchJenis(LJ,newJenis);
        }
        nextJ(b) = j;

    }

    infoB(b) = tmp;
}
void showJenisNBiaya(ListJ LJ, ListB LB)
{
    if (isEmptyJ(LJ))
    {
        cout << "\nList Jenis kosong.\n";
    }
    else
    {
        cout << "\n-----------------------------------\n";
        showJenis(LJ);

        //
        cout << "\nBanyaknya Child(Biaya) untuk setiap Jenis.\n";
        adrJenis j = firstJ(LJ);
        int i = 1;
        while (j!=NULL){
            cout << i << ". " << infoJ(j) << ": ";
            i++;
            int countB = 0;
            if (isEmptyB(LB)){
                cout << "\n";
            }
            else
            {
                adrBiaya b = firstB(LB);
                while (b!=NULL)
                {
                    if (nextJ(b)==j){
                        countB++;
                    }
                    b = nextB(b);
                }
                cout << countB << endl;
            }
            j = nextJ(j);
        }

        //
        cout << "\nList biaya untuk setiap jenisnya:\n";
        j = firstJ(LJ);
        i = 1;
        while (j!=NULL){
            cout << i << ". " << infoJ(j) << ": "<< endl;
            i++;
            if (isEmptyB(LB)){
                cout << "\n";
            }
            else
            {
                adrBiaya b = firstB(LB);
                while (b!=NULL)
                {
                    if (nextJ(b)==j){

                        cout << "  - ID Biaya  : " << infoB(b).id << endl;
                        cout << "    ID Pegawai: " << infoB(b).idP << endl;
                        cout << "    Deskripsi : " << infoB(b).deskripsi << endl;
                        cout << "    Jumlah    : " << infoB(b).jumlah << endl;
                        cout << "    Biaya     : " << infoB(b).biaya << endl;
                        cout << "\n";
                    }

                    b = nextB(b);
                }

            }
            j = nextJ(j);
        }
        cout << "\n-----------------------------------\n";
    }
}
int totalBiaya(ListB LB)
{
    int sum = 0;
    if (isEmptyB(LB))
    {
        cout << "\nList Biaya kosong.\n";
    }
    else
    {
        adrBiaya b = firstB(LB);
        while (b!=NULL)
        {
            sum += infoB(b).biaya;
            b = nextB(b);
        }
    }
    return sum;
}

