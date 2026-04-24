1. Soru: İnsan, Öğrenci ve Çalışan Sınıfları
#include <iostream>
#include <string>

using namespace std;

class Insan {
public:
    string ad;
    int yas;
    int id;

    Insan(string a, int y, int i) {
        ad = a;
        yas = y;
        id = i;
    }

    void yazdir() {
        cout << "Ad: " << ad << ", Yas: " << yas << ", ID: " << id << endl;
    }
};

class Ogrenci : public Insan {
public:
    string ders;

    Ogrenci(string a, int y, int i, string d) : Insan(a, y, i) {
        ders = d;
    }

    void dersKayit(string d) {
        ders = d;
    }

    void yazdir() {
        cout << "Ad: " << ad << ", Yas: " << yas << ", ID: " << id << endl;
        cout << "Ders: " << ders << endl;
    }
};

class Calisan : public Insan {
public:
    double maas;

    Calisan(string a, int y, int i, double m) : Insan(a, y, i) {
        maas = m;
    }

    void zamHesapla(double oran) {
        maas = maas + (maas * oran);
    }

    void yazdir() {
        cout << "Ad: " << ad << ", Yas: " << yas << ", ID: " << id << endl;
        cout << "Maas: " << maas << endl;
    }
};

int main() {
    Ogrenci ogr("Ahmet", 20, 101, "Matematik");
    Calisan cal("Mehmet", 35, 202, 3500);

    ogr.yazdir();
    cal.zamHesapla(0.1);
    cal.yazdir();

    return 0;
}






2. Soru: Apartman, Okul ve Hastane Sınıfları
#include <iostream>
using namespace std;

class Bina {
private:
    int katSayisi;
    int metrekare;
    bool bahceVarMi;
    bool otoparkVarMi;

public:
    void setKatSayisi(int k) { katSayisi = k; }
    int getKatSayisi() { return katSayisi; }

    void setMetrekare(int m) { metrekare = m; }
    int getMetrekare() { return metrekare; }

    void setBahceVarMi(bool b) { bahceVarMi = b; }
    bool getBahceVarMi() { return bahceVarMi; }

    void setOtoparkVarMi(bool o) { otoparkVarMi = o; }
    bool getOtoparkVarMi() { return otoparkVarMi; }

    void bilgiYazdir() {
        cout << "Kat: " << katSayisi
             << ", Metrekare: " << metrekare
             << ", Bahce: " << (bahceVarMi ? "Var" : "Yok")
             << ", Otopark: " << (otoparkVarMi ? "Var" : "Yok")
             << endl;
    }
};

class Apartman : public Bina {
private:
    int daireSayisi;

public:
    void setDaireSayisi(int d) { daireSayisi = d; }
    int getDaireSayisi() { return daireSayisi; }

    void bilgiYazdir() {
        Bina::bilgiYazdir();
        cout << "Daire Sayisi: " << daireSayisi << endl;
    }
};

class Okul : public Bina {
private:
    int sinifSayisi;

public:
    void setSinifSayisi(int s) { sinifSayisi = s; }
    int getSinifSayisi() { return sinifSayisi; }

    void bilgiYazdir() {
        Bina::bilgiYazdir();
        cout << "Sinif Sayisi: " << sinifSayisi << endl;
    }
};

class Hastane : public Bina {
private:
    int yatakSayisi;

public:
    void setYatakSayisi(int y) { yatakSayisi = y; }
    int getYatakSayisi() { return yatakSayisi; }

    void bilgiYazdir() {
        Bina::bilgiYazdir();
        cout << "Yatak Sayisi: " << yatakSayisi << endl;
    }
};

int main() {
    Apartman a;
    Okul o;
    Hastane h;

    a.setKatSayisi(10);
    a.setMetrekare(500);
    a.setBahceVarMi(true);
    a.setOtoparkVarMi(true);
    a.setDaireSayisi(20);

    o.setKatSayisi(5);
    o.setMetrekare(800);
    o.setBahceVarMi(true);
    o.setOtoparkVarMi(false);
    o.setSinifSayisi(30);

    h.setKatSayisi(8);
    h.setMetrekare(1200);
    h.setBahceVarMi(false);
    h.setOtoparkVarMi(true);
    h.setYatakSayisi(100);

    cout << "Apartman:" << endl;
    a.bilgiYazdir();

    cout << "\nOkul:" << endl;
    o.bilgiYazdir();

    cout << "\nHastane:" << endl;
    h.bilgiYazdir();

    return 0;
}
