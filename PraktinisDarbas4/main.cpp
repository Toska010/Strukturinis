#include <iostream>
#include <fstream>
#include <iomanip>

const int MasyvuDydis = 124;
int Ratas;
int Plotis = 65;
int Pasirinkimas;
float Pvm;
float GalutineSuma;

using namespace std;

struct StrukturaMeniu {
    float Kainos;
    string Pavadinimai;
    int KiekisUzsakymui;
    float Suma;
}Meniu[MasyvuDydis];
void Failai_I_Masyvus() {
    Ratas = 0;
    ifstream KainuFailas;
    ifstream PatiekaluFailas;
    KainuFailas.open("Kainos.txt");
    PatiekaluFailas.open("Patiekalai.txt");
    while (!KainuFailas.eof() && !PatiekaluFailas.eof()) {
        KainuFailas >> Meniu[Ratas].Kainos;
        getline(PatiekaluFailas, Meniu[Ratas].Pavadinimai);
        Ratas++;
    }
    KainuFailas.close();
    PatiekaluFailas.close();
}
void Patiekalai_Bruksniai_Kainos(int Pradzia, int KartojimasIki) {
    char BuferisIlgiui[MasyvuDydis];
    for (int i = Pradzia; i < KartojimasIki; i++) {
        int SumosIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%.2f", Meniu[i].Kainos);
        cout << Meniu[i].Pavadinimai << " ";
        int Linija = Meniu[i].Pavadinimai.length() + SumosIlgis;;
        for (int i = 0; i < Plotis - (Linija + 2); i++) {
            cout << "-";
        }
        cout << " " << fixed << setprecision(2) << Meniu[i].Kainos << endl;
    }
}
void PvmEilute() {


}
void MeniuAtvaizdavimas() {
    Failai_I_Masyvus();
    for (int i = 0; i < Plotis; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < (Plotis - 5) / 2; i++) {
        cout << " ";
    }
    cout <<  "MENIU" << endl;
    for (int i = 0; i < Plotis; i++) {
        cout << "-";
    }
    cout << endl << endl;
    Patiekalai_Bruksniai_Kainos(0, Ratas);
    cout << endl;
}
void Uzsakymas() {
    Pvm = 0;
    GalutineSuma = 0;
    cout << "Iveskite kiekius uzsakymui" << endl;
    for (int i = 0; i < Ratas; i++) {
        Patiekalai_Bruksniai_Kainos(i, i+1);
        cin >> Meniu[i].KiekisUzsakymui;
        if (Meniu[i].KiekisUzsakymui < 0) {
            Meniu[i].KiekisUzsakymui = 0;
        }
        Meniu[i].Suma = float(Meniu[i].KiekisUzsakymui) * Meniu[i].Kainos;
        Pvm = Pvm + Meniu[i].Suma * 0.21;
        GalutineSuma = GalutineSuma + Meniu[i].Suma * 1.21;
        }
}
void Kvitas() {
    ofstream Cekis;
    Cekis.open("Kvitas.txt");
    Cekis << "";
    Cekis.close();
    Cekis.open("Kvitas.txt",ios::app);
    char BuferisIlgiui[MasyvuDydis];
    for (int i = 0; i < Ratas; i++) {
        if (Meniu[i].Suma > 0) {
            int SumosIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%.2f", Meniu[i].Suma);
            int KiekioIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%d", Meniu[i].KiekisUzsakymui);
            int Tarpas = Meniu[i].Pavadinimai.length() + SumosIlgis + KiekioIlgis;
            cout << "Kiekis: " << Meniu[i].KiekisUzsakymui << " | " << Meniu[i].Pavadinimai << " ";
            Cekis << "Kiekis: " << Meniu[i].KiekisUzsakymui << " | " << Meniu[i].Pavadinimai << " ";
            for (int j = 0; j < Plotis - (13 + Tarpas); j++) {
                cout << "-";
                if (j+1 < Plotis - (13 + Tarpas)) {
                    Cekis << "_";
                }
            }
            cout << " " << fixed << setprecision(2) << Meniu[i].Suma << endl;
            Cekis << " " << fixed << setprecision(2) << Meniu[i].Suma << "€" << endl;
        }
    }
    int SumosIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%.2f", Pvm);
    cout << "Pvm 21%:  | ";
    Cekis << "Pvm 21%:  | ";
    for (int i = 0; i < Plotis - (12 + SumosIlgis); i++) {
        cout << " ";
        if (i + 1 < Plotis - (12 + SumosIlgis)) {
            Cekis << " ";
        }
    }
    cout << fixed << setprecision(2) << Pvm << endl;
    Cekis << fixed << setprecision(2) << Pvm << "€" << endl;

    SumosIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%.2f", GalutineSuma);
    cout << "Viso:     | ";
    Cekis << "Viso:     | ";
    for (int i = 0; i < Plotis - (12 + SumosIlgis); i++) {
        cout << " ";
        if (i+1 < Plotis - (12 + SumosIlgis)) {
            Cekis << " ";
        }
    }
    cout << fixed << setprecision(2) << GalutineSuma << endl;
    Cekis << fixed << setprecision(2) << GalutineSuma << "€" << endl;
    Cekis.close();
}


int main() {
    Failai_I_Masyvus();
    while (true) {
        cout << "Pasirinkite funkcija:\n1: MENIU\t2: PATEIKTI UZSAKYMA\t3: KVITAS\t4: ISEITI" << endl;
        cin >> Pasirinkimas;
        switch (Pasirinkimas) {
            case 1: {
                MeniuAtvaizdavimas();
                break;
            }
            case 2: {
                Uzsakymas();
                break;
            }
            case 3: {
                Kvitas();
                break;
            }
            case 4: {
                break;
            }
        }
        if (Pasirinkimas == 4) {
            break;
        }
    }
    return 0;
}
