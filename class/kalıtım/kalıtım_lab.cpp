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
#include <string>

using namespace std;

class Bina {
public:
    int katSayisi;
    bool otoparkVarMi;

    Bina(int k, bool o) {
        katSayisi = k;
        otoparkVarMi = o;
    }

    void bilgiYazdir() {
        cout << "Kat Sayisi: " << katSayisi << ", Otopark Var Mi: " 
             << (otoparkVarMi ? "Evet" : "Hayir") << endl;
    }
};

class Apartman : public Bina {
public:
    int daireSayisi;

    Apartman(int k, bool o, int d) : Bina(k, o) {
        daireSayisi = d;
    }

    void bilgiYazdir() {
        Bina::bilgiYazdir();
        cout << "Daire Sayisi: " << daireSayisi << endl;
    }
};

class Okul : public Bina {
public:
    int sinifSayisi;

    Okul(int k, bool o, int s) : Bina(k, o) {
        sinifSayisi = s;
    }

    void bilgiYazdir() {
        Bina::bilgiYazdir();
        cout << "Sinif Sayisi: " << sinifSayisi << endl;
    }
};

class Hastane : public Bina {
public:
    int yatakSayisi;

    Hastane(int k, bool o, int y) : Bina(k, o) {
        yatakSayisi = y;
    }

    void bilgiYazdir() {
        Bina::bilgiYazdir();
        cout << "Yatak Sayisi: " << yatakSayisi << endl;
    }
};

int main() {
    Apartman a(10, true, 50);
    Okul o(5, false, 15);
    Hastane h(8, true, 100);

    a.bilgiYazdir();
    o.bilgiYazdir();
    h.bilgiYazdir();

    return 0;
}

    return 0;
}
