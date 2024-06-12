#include <iostream>
#include "tubes.h"
#include "tubes.cpp"
#include <string>

using namespace std;

int main() {
    list_warteg W;
    list_makanan M;
    list_relation R;

    createListWarteg(W);
    createListMakanan(M);
    createListRelation(R);

   int pilihan;
    string namawarteg, namamakanan, id_warteg, id_makanan,id;
    do
    {
        system("cls");
        cout << "================ Program Menu Warteg ====================" << endl;
       
        viewWarteg(W);
        viewMakanan(M);
        viewRelation(R);

        cout << "Menu" << endl;
        cout << "1.Masukkan data Warteg " << endl;
        cout << "2.Masukkan data Makanan  " << endl;
        cout << "3.Tambahkan Relasi Warteg dan Makanan  " << endl;
        cout << "4.Hapus Data Warteg  " << endl;
        cout << "5.Hapus Data Makanan " << endl;
        cout << "6.Lihat Data " << endl; 
        cout << "7.Lihat Data Makanan Paling Banyak dan Sedikit Peminat" << endl;
        cout << "8.Lihat Data Warteg Berdasarkan Makanan" << endl;
        cout << "9.Lihat Data Makanan Berdasarkan Warteg " << endl;
        cout << "10.Keluar" << endl;
        cout << "Pilih Menu :";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Masukkan Nama Warteg :";
            cin >> namawarteg;
            cout<< "masukan id warteg :";
            cin >> id;
            system("pause");
            insertWarteg(W, createElmWarteg(id,namawarteg));
            break;
        case 2:
            cout << "Masukkan Nama Makanan :";
            cin >> namamakanan;
            cout << "masukan id Makanan :";
            cin >> id;
            insertMakanan(M, createElmMakanan(id,namamakanan));
            break;
        case 3:
            cout << "Masukkan id Warteg :";
            cin >> id_warteg;
            cout << "Masukkan id Makanan : ";
            cin >> id_makanan;
            addMakanan(W,M,R,id_warteg,id_makanan);
            break;
            
         case 4:
            cout << "Masukkan id warteg :";
            cin >> id_warteg;
            deleteWarteg(W,R,id_warteg);
            break;
        case 5:
            cout << "Masukkan id Makanan : ";
            cin >> id_makanan;

            deleteMakanan(M,R,id_makanan);
            break;
        case 6:
            view(W,R);
            system("pause");
            break;

        case 7:
            lihatPeminatmakanan(W,M,R);
            system("pause");
            break;
        case 8:
            cout << "Masukkan id makanan : ";
            cin >> id_makanan;
            searchWarteg_Makanan(M,R,id_makanan);
            system("pause");
            break;
        case 9:
            cout << "Masukkan Id warteg :";
            cin >> id_warteg;
            searchMakanan_Warteg(W,R,id_warteg);
            system("pause");
            break;
        case 10:
            return 0;
            break;

        default:
            break;
        }
    } while (pilihan != 0);
    return 0;
}
    
