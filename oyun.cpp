#include <iostream>
#include <string>

using namespace std;
class Karakter {
private:
    string isim;
    int can;
    int saldiri_gucu;
    int seviye;
    int puan;
public:
    Karakter(string i, int guc) {
        isim = i;
        can = 100;
        saldiri_gucu = guc;
        seviye = 1;
        puan = 0;
    }
    void bilgileri_goster() {
        cout << "Isim: " << isim << " - Can: " << can << " - Saldiri: " << saldiri_gucu
             << " - Seviye: " << seviye << " - Puan: " << puan << endl;
    }
    bool canli_mi() {
        return can > 0; 
    }
    void seviye_atla() {
        seviye++; 
        saldiri_gucu += 10;
        cout << isim << " seviye atladi! Yeni seviye: " << seviye << endl;
    }
    string get_isim() { return isim; }
    int get_seviye() { return seviye; }
    int get_saldiri() { return saldiri_gucu; }
    int get_puan() { return puan; }
    int get_can() { return can; }
    void can_azalt(int miktar) {
        can -= miktar;
        if (can < 0) can = 0;
    }
    void puan_ekle(int miktar) {
        puan += miktar;
    }
};
int main() {
    Karakter ali("Ali", 25);
    Karakter canavar("Canavar", 15);
    for (int i = 0; i < 4; i++) {
        if (ali.canli_mi() && canavar.canli_mi()) {
            canavar.can_azalt(ali.get_saldiri());
            cout << ali.get_isim() << " " << canavar.get_isim() << "'i vurdu! "
                 << canavar.get_isim() << "'in cani: " << canavar.get_can() << endl;
            if (!canavar.canli_mi()) {
                int ek_puan = 0;
                if (canavar.get_seviye() >= 3) ek_puan = 100;
                else if (canavar.get_seviye() == 2) ek_puan = 50;
                else ek_puan = 25; 
                ali.puan_ekle(ek_puan);
                cout << canavar.get_isim() << " yenildi! " << ali.get_isim() << " "
                     << ek_puan << " puan kazandi! Toplam puan: " << ali.get_puan() << endl;
                ali.seviye_atla();
            }
        }
    }

    cout << "--- OYUN SONU ---" << endl;
    cout << "--- " << ali.get_isim() << " Bilgileri ---" << endl;
    ali.bilgileri_goster();
    return 0;
}