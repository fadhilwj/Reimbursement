#include <iostream>
#include "menu.h"
#include "parent.h"
#include "child.h"

using namespace std;

int main()
{
    ListJ LJ;
    createListJenis(LJ);
    ListB LB;
    createListBiaya(LB);

    int pilihan;
    pilihan = displayMenu();
    while (pilihan != 0)
    {
        switch (pilihan) {
            case 1: {
                //"1. Tambah Jenis Barang/Reimbursement\n"
                infotypeJ namaJenis;
                cout << "\nInput 'x' untuk mengakhiri inputan.\n";
                cout << "Masukkan nama jenis reimbursement: ";
                cin.ignore();
                getline(cin, namaJenis);
                if (searchJenis(LJ,namaJenis)!=NULL)
                {
                    cout << "\nGagal ditambahkan: Nama Jenis tersebut sudah terdaftar.\n";
                }
                else
                {
                    while (namaJenis != "x")
                    {
                        adrJenis j = createElemenJenis(j, namaJenis);
                        insertLastJenis(LJ, j);
                        cout << "Jenis barang berhasil ditambahkan!\n";
                        cout << "Masukkan nama jenis reimbursement: ";
                        getline(cin, namaJenis);
                    }
                }
                break;
            }
            case 2: {
                // "2. Tambah Biaya untuk Jenis Reimbursement\n"
                infotypeJ namaJenis;
                infotypeB x;
                cout << "\nInput 'x' untuk mengakhiri inputan.\n";
                cout << "Masukkan ID biaya: ";
                cin >> x.id;
                while (x.id != "x"){

                    if (searchBiayaByID(LB,x.id)!=NULL){
                        cout << "ID biaya tersebut sudah terdaftar. (ID biaya harus unik)\n";
                    }
                    else
                    {
                        cout << "Masukkan ID Pegawai: ";
                        cin >> x.idP;
                        cout << "Masukkan deskripsi biaya: ";
                        cin.ignore();
                        getline(cin, x.deskripsi);
                        cout << "Masukkan jumlah: ";
                        cin >> x.jumlah;
                        cout << "Masukkan biaya: ";
                        cin >> x.biaya;
                        cout << "Masukkan jenis: ";
                        cin >> namaJenis;
                        adrBiaya b = createElemenBiaya(LJ,b,x,namaJenis);
                        insertLastBiaya(LB,b);

                        cout << "Biaya berhasil ditambahkan!\n\n";
                    }
                    cout << "Masukkan ID biaya: ";
                    cin >> x.id;
                }
                break;
            }
            case 3: {
                // "3. Hapus Jenis Barang\n"

                infotypeJ namaJenis;
                cout << "Masukkan nama jenis barang yang akan dihapus: ";
                cin >> namaJenis;

                adrJenis j = NULL;
                deleteJenisByNama(LJ, LB, namaJenis, j);
                if (j != NULL) {
                    cout << "Jenis barang berhasil dihapus!\n";
                }

                break;
            }
            case 4: {
                // "4. Hapus Biaya (...)\n"
                // "\n============= OPSI HAPUS BIAYA =============\n";
                // "1. Hapus Biaya berdasarkan ID              \n";
                // "2. Hapus Semua Biaya berdasarkan Jenis     \n";
                // "0. kembali                                 \n";
                string delOpt = displayHapusBiaya();

                if (delOpt == "1")
                {
                    cout << "\nBerikut list sebagai petunjuk ID Biaya.\n";
                    showJenisNBiaya(LJ, LB);

                    string id;
                    cout << "\nMasukkan ID Biaya yang ingin dihapus: ";
                    cin >> id;
                    adrBiaya b = searchBiayaByID(LB, id);
                    if (b!=NULL)
                    {
                        deleteBiaya(LB,b);
                        cout << "\nData Biaya berhasil dihapus!\n";
                    }
                    else
                    {
                        cout << "\nData biaya dengan ID tersebut tidak ditemukan.\n";
                    }

                }
                else if (delOpt == "2")
                {
                    infotypeJ namaJenis;
                    cout << "Masukkan nama jenis barang: ";
                    cin >> namaJenis;
                    adrJenis x = searchJenis(LJ, namaJenis);
                    if (x!=NULL){
                        deleteAllBiayaByJenis(LB,x);
                        cout << "\nData berhasil dihapus!\n";
                    } else {
                        cout << "\nNama jenis tidak ditemukan.\n";
                    }

                }
                else
                {

                }

                break;
            }
            case 5: {
                // "5. Edit Data\n"
                string choice;
                cout << "\n========== OPSI UPDATE ==========\n";
                cout << "1. Data Jenis                  \n";
                cout << "2. Data Biaya                  \n";
                cout << "0. kembali                     \n";
                cout << "Pilihan: ";
                cin >> choice;

                if (choice == "1")
                {
                    infotypeJ namaJenis;
                    cout << "Masukkan nama jenis yang akan diupdate: ";
                    cin >> namaJenis;

                    adrJenis j = searchJenis(LJ, namaJenis);
                    if (j!=NULL){
                        infotypeJ newJenis;
                        cout << "Masukkan nama jenis yang baru: ";
                        cin >> newJenis;
                        adrJenis j2 = searchJenis(LJ, newJenis);
                        while (j2!=NULL)
                        {
                            cout << "\nData gagal diperbarui. (Nama jenis harus unik)\n";
                            cout << "Masukkan nama jenis yang baru: ";
                            cin >> newJenis;
                            j2 = searchJenis(LJ, newJenis);
                            if (newJenis == infoJ(j))
                            {
                                j2 = NULL;
                            }
                        }
                        infoJ(j) = newJenis;
                        cout << "\nData berhasil diperbarui!\n";
                    } else {
                        cout << "\nNama jenis tidak ditemukan.\n";
                    }
                }
                else if (choice == "2")
                {
                    cout << "\nMasukkan ID Biaya yang akan diupdate: ";
                    string id;
                    cin >> id;
                    adrBiaya b = searchBiayaByID(LB,id);
                    if (b == NULL)
                    {
                        cout << "\nID Biaya tidak ditemukan.\n";
                    }
                    else
                    {
                        string upOpt = displayUpdateBiaya();
                        updateElmBiaya(LJ, LB, b, upOpt);
                        cout << "\Data Biaya berhasil diperbarui\n";
                    }

                }

                break;
            }
            case 6: {
                // " Tampilkan Semua Jenis\n"
                showJenis(LJ);
                break;
            }
            case 7: {
                // " Tampilkan Semua Jenis dan Biaya\n"
                showJenisNBiaya(LJ, LB);
                break;
            }
            case 8: {
                // " Tampilkan Total Biaya\n"
                int total = totalBiaya(LB);
                cout << "\nTotal biaya: " << total << endl;
                break;
            }
            case 9: {
                cout << "\nMasukkan nama jenis yang ingin dicari: ";
                infotypeJ namaJenis;
                cin >> namaJenis;
                adrJenis j = searchJenis(LJ,namaJenis);
                if (j==NULL)
                {
                    cout << "\nData Jenis tidak ditemukan.\n";
                }
                else
                {
                    cout << "\nData ditemukan!\n";
                    cout << "Alamat Jenis   : " << j << endl;
                    cout << "Info" << endl;
                    cout << "Nama Jenis     : " << infoJ(j) << endl;
                }
                break;
            }
            case 10: {
                cout << "\nMasukkan ID Biaya yang ingin dicari: ";
                string id;
                cin >> id;
                adrBiaya b = searchBiayaByID(LB,id);
                if (b==NULL)
                {
                    cout << "\nData Biaya tidak ditemukan.\n";
                }
                else
                {
                    cout << "\nData ditemukan!\n";
                    cout << "Alamat Biaya   : " << b << endl;
                    cout << "Info" << endl;
                    cout << "ID Biaya       : " << infoB(b).id << endl;
                    cout << "ID Pegawai     : " << infoB(b).id << endl;
                    cout << "Deskripsi      : " << infoB(b).deskripsi << endl;
                    cout << "Jumlah         : " << infoB(b).id << endl;
                    cout << "Total Biaya    : " << infoB(b).id << endl;
                    cout << "Jenis Biaya    : " << infoB(b).id << endl;
                }
                break;
            }
            case 0:
                // " Keluar\n"
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
        pilihan = displayMenu();
    }
}
