#include "tubes.h"

// list warteg
void createListWarteg(list_warteg &w)
{
    w.first_warteg = NULL;
    w.last_warteg = NULL;
}

// list elemen warteg
adr_warteg createElmWarteg(string id, string name)
{
    adr_warteg p = new elm_warteg;
    p->info_warteg.id_warteg = id;
    p->info_warteg.name_warteg = name;
    p->next_warteg = NULL;
    return p;
}

// list makanan
void createListMakanan(list_makanan &m)
{
    m.first_makanan = NULL;
}

// elemen makanan
adr_makanan createElmMakanan(string id, string name)
{
    adr_makanan p = new elm_makanan;
    p->info_makanan.id_makanan = id;
    p->info_makanan.name_makanan = name;
    p->next_makanan = NULL;
    return p;
}

// list relasi
void createListRelation(list_relation &r)
{
    r.first_relation = NULL;
}

// elemen relasi
adr_relation createElmRelation()
{
    adr_relation p = new elm_relation;
    p->next_warteg = NULL;
    p->next_makanan = NULL;
    p->next_relation = NULL;
    return p;
}

// insert warteg
void insertWarteg(list_warteg &w, adr_warteg p)
{
    if (w.first_warteg == NULL)
    {
        w.first_warteg = p;
        w.last_warteg = p;
    }
    else
    {
        p->prev_warteg=w.first_warteg;
        w.last_warteg->next_warteg=p;
        w.last_warteg=p;
    }
}

// insert makanan
void insertMakanan(list_makanan &m, adr_makanan q)
{
    if (m.first_makanan == NULL)
    {
        m.first_makanan = q;
    }
    else
    {
        q->next_makanan=m.first_makanan;
        m.first_makanan =q;
    }
}

// insert relasi
void insertRelation(list_relation &r, adr_relation p)
{
    if (r.first_relation == NULL)
    {
        r.first_relation = p;
    }
    else
    {
        adr_relation q = r.first_relation;
        while (q->next_relation != NULL)
        {
            q = q->next_relation;
        }
        q->next_relation = p;
    }
}

// search warteg
adr_warteg searchWarteg(list_warteg w, string id_warteg)
{
    adr_warteg p = w.first_warteg;
    while ((p != NULL) && (p->info_warteg.id_warteg != id_warteg))
    {
        p = p->next_warteg;
    }
    return p;
}

// menampilkan makanan berdasarkan warteg
void searchMakanan_Warteg(list_warteg w, list_relation r, string id_warteg)
{ // dalam percobaan
    adr_warteg p = searchWarteg(w, id_warteg);
    if (p != NULL)
    {
        cout << "Makanan yang tersedia di " << p->info_warteg.name_warteg << ":\n";
        adr_relation rel = r.first_relation;
        while (rel != NULL)
        {
            if (rel->next_warteg == p)
            {
                cout << "- " << rel->next_makanan->info_makanan.name_makanan << endl;
            }
            rel = rel->next_relation;
        }
    }
    else
    {
        cout << "Warteg dengan id " << id_warteg << " tidak ditemukan.\n";
    }
}

// search makanan
adr_makanan searchMakanan(list_makanan m, string id_makanan)
{
    adr_makanan p = m.first_makanan;
    while ((p != NULL) && (p->info_makanan.id_makanan != id_makanan))
    {
        p = p->next_makanan;
    }
    return p;
}

// menampilkan warteg berdasarkan makanan
void searchWarteg_Makanan(list_makanan m, list_relation r, string id_makanan)
{ // dalam percobaan
    adr_makanan p = searchMakanan(m, id_makanan);
    if (p != NULL)
    {
        cout << "Wartg yang tersedia di " << p->info_makanan.name_makanan << ":\n";
        adr_relation rel = r.first_relation;
        while (rel != NULL)
        {
            if (rel->next_makanan == p)
            {
                cout << "- " << rel->next_warteg->info_warteg.name_warteg << endl;
            }
            rel = rel->next_relation;
        }
    }
    else
    {
        cout << "Makanan dengan id " << id_makanan << " tidak ditemukan.\n";
    }
}

// search relasi
adr_relation searchRelation(list_relation r, string id_warteg, string id_makanan)
{
    adr_relation p = r.first_relation;
    while ((p != NULL) && ((p->next_warteg->info_warteg.id_warteg != id_warteg) || (p->next_makanan->info_makanan.id_makanan != id_makanan)))
    {
        p = p->next_relation;
    }
    return p;
}

// add relasi antara warteg dan makanan
void addMakanan(list_warteg w, list_makanan m, list_relation &r, string id_warteg, string id_makanan)
{
    adr_warteg pWarteg = searchWarteg(w, id_warteg);
    adr_makanan pMakanan = searchMakanan(m, id_makanan);
    if (pWarteg != NULL && pMakanan != NULL)
    {
        adr_relation pRel = createElmRelation();
        pRel->next_warteg = pWarteg;
        pRel->next_makanan = pMakanan;
        insertRelation(r, pRel);
    }
}

// delete elemen relasi
void deleteElmRelation(list_relation &r, adr_relation p)
{
    if (r.first_relation == p)
    {
        r.first_relation = p->next_relation;
    }
    else
    {
        adr_relation q = r.first_relation;
        while (q->next_relation != p)
        {
            q = q->next_relation;
        }
        q->next_relation = p->next_relation;
    }
    delete p;
}

// delete relasi
void deleteRelation(list_warteg w, list_makanan m, list_relation &r, string id_warteg, string id_makanan)
{
    adr_relation p = searchRelation(r, id_warteg, id_makanan);
    if (p != NULL)
    {
        deleteElmRelation(r, p);
    }
}

// delete warteg
void deleteWarteg(list_warteg &w, list_relation &r, string id_warteg)
{
    adr_warteg p = searchWarteg(w, id_warteg);
    if (p != NULL)
    {
        adr_relation q = r.first_relation;
        while (q != NULL)
        {
            if (q->next_warteg == p)
            {
                adr_relation temp = q;
                q = q->next_relation;
                deleteElmRelation(r, temp);
            }
            else
            {
                q = q->next_relation;
            }
        }
        if (w.first_warteg == p)
        {
            w.first_warteg = p->next_warteg;
        }
        else
        {
            adr_warteg prev = w.first_warteg;
            while (prev->next_warteg != p)
            {
                prev = prev->next_warteg;
            }
            prev->next_warteg = p->next_warteg;
        }
        delete p;
    }
}

// view relasi
void viewRelation(list_relation r)
{
    adr_relation p = r.first_relation;
    while (p != NULL)
    {

        cout << "Warteg: " << p->next_warteg->info_warteg.name_warteg
             << " - Makanan: " << p->next_makanan->info_makanan.name_makanan << endl;
        p = p->next_relation;
    }
}

// view semua
void view(list_warteg w, list_relation r)
{
    adr_warteg pWarteg = w.first_warteg;
    while (pWarteg != NULL)
    {
        cout << "Warteg: " << pWarteg->info_warteg.name_warteg << endl; // eror kebalek id dengan nama
        adr_relation pRel = r.first_relation;
        while (pRel != NULL)
        {
            if (pRel->next_warteg == pWarteg)
            {
                cout << "  Makanan: " << pRel->next_makanan->info_makanan.name_makanan << endl;
            }
            pRel = pRel->next_relation;
        }
        pWarteg = pWarteg->next_warteg;
    }
}

// view warteg
void viewWarteg(list_warteg LW)
{
    cout << "Daftar Warteg :";
    adr_warteg p = LW.first_warteg;
    while (p != NULL)
    {
        cout << p->info_warteg.id_warteg << "_";
        cout << p->info_warteg.name_warteg << ",";
        p = p->next_warteg;
    }
    cout << "" << endl;
}

// view makanan
void viewMakanan(list_makanan LM)
{
    cout << "Daftar Makanan :";
    adr_makanan q = LM.first_makanan;
    while (q != NULL)
    {
        cout << q->info_makanan.id_makanan << "_";
        cout << q->info_makanan.name_makanan << ",";
        q = q->next_makanan;
    }
    cout << "" << endl;
}

// menghapus makanan
void deleteMakanan(list_makanan &m, list_relation &r, string id_makanan)
{
    adr_makanan p = searchMakanan(m, id_makanan);
    if (p != NULL)
    {
        // mencari makanan
        adr_relation q = r.first_relation;
        while (q != NULL)
        {
            if (q->next_makanan == p)
            {
                q->next_warteg = NULL;
                q->next_makanan = NULL;
                deleteElmRelation(r, q);
            }
            q = q->next_relation;
        }

        // Delete makanannya
        if (p == m.first_makanan)
        {
            if (p->next_makanan == NULL)
            {
                m.first_makanan = NULL;
            }
            else
            {
                m.first_makanan = p->next_makanan;
                p->next_makanan = NULL;
            }
        }
        else
        {
            adr_makanan b = m.first_makanan;
            while (b->next_makanan != p)
            {
                b = b->next_makanan;
            }
            b->next_makanan = p->next_makanan;
            p->next_makanan = NULL;
        }
    }
}

void lihatPeminatmakanan(list_warteg LT, list_makanan LI, list_relation r) {
    adr_makanan makananMax = NULL, makananMin = NULL;
    int maxjumlah = 0, minjumlah = 0;

    adr_makanan p = LI.first_makanan;
    while (p != NULL) {
        int jumlah = 0;
        adr_relation q = r.first_relation;
        while (q != NULL) {
            if (q->next_makanan == p) {
                jumlah++;
            }
            q = q->next_relation;
        }

        if (jumlah > maxjumlah) {
            maxjumlah = jumlah;
            makananMax = p;
        }

        if (minjumlah == 0 || jumlah < minjumlah) {
            minjumlah = jumlah;
            makananMin = p;
        }

        p = p->next_makanan;
    }

    if (makananMax != NULL) {
        cout << "Makanan dengan peminat terbanyak adalah: " << makananMax->info_makanan.name_makanan << " dengan " << maxjumlah << " warteg." << endl;
if (makananMin != NULL) {
            cout << "Makanan dengan peminat tersedikit adalah: " << makananMin->info_makanan.name_makanan << " dengan " << minjumlah << " warteg." << endl;
        } else {
            cout << "Tidak ada makanan dengan peminat." << endl;
        }
    }
}
