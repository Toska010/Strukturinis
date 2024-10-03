#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Vartotojo pasirinkimai funkcijom
int PirmasKeitiklis;
int AntrasKeitiklis;
//Loop paramerai
int LoopMax = 6;
int Loop;
//Loop parametru keitimas vartotojo ivesties patikrinimu
int Choise;
//Daznai naudojami tekstai programoje
string Bendri = "1 - Valiutos kurso palyginimas\n";
string Pirkti = "2 - Valiutos pirkimas\n";
string Parduoti = "3 - Valiutos pardavimas\n";
//Valiutu pavadinimai ir trumpiniai
string Id;
string GBP = "1 - Didziosios Britanijos svaras GBP\n";
string USD = "2 - Jungtiniu Amerikos Valstiju doleris USD\n";
string INR = "3 - Indijos rupijos INR\n";
string EUR = "4 - Euras EUR\n";
//Besikeiciantis tekstas funkcijose nuo pasirinktos funkcijos pobudzio
string Frazes;
//Skaiciavimam skirti skaitciu parametrai
double Suma;
double Kiekis;
//Antras valiutos kurso pasirinkimas palyginimo programai
int AntraValiuta;
//Valiutu kursu trumpiniai
string Trumpiniai[4] = {"GBP", "USD", "INR", "EUR"};
//Valiutu kursu ir koficijentu atitinkamoms funkcijoms parametrai
double Valiutos[3][4] = {
    {
        //Bendri
        0.8593,//Didžiosios Britanijos svaras GBP
        1.0713,//Jungtinių Amerikos Valstijų doleris USD
        88.8260,//Indijos rupijos INR
        1//Eur
    },
    {
        //Pirkti
        0.8450,//Didžiosios Britanijos svaras GBP
        1.0547,//Jungtinių Amerikos Valstijų doleris USD
        85.2614,//Indijos rupijos INR
        1//Eur
    },
    {
        //Parduoti
        0.9060,//Didžiosios Britanijos svaras GBP
        1.1309,//Jungtinių Amerikos Valstijų doleris USD
        92.8334,//Indijos rupijos INR
        1//Eur
    }
};
//Bendro koficijento funkcija
void BendroSkaiciavimas() {
    cout << "Ivesk turima suma palyginimui:\n";
    cin >> Kiekis;
    Suma = Kiekis / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1] * Valiutos[PirmasKeitiklis-1][AntraValiuta-1];
    cout << "Koficientas: " << 1 << " " << Trumpiniai[AntrasKeitiklis-1] << " = "<< Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1] * Valiutos[PirmasKeitiklis-1][AntraValiuta-1]
    << " " << Trumpiniai[AntraValiuta-1] << "\tSuma: " << Suma << " " << Trumpiniai[AntraValiuta-1] << endl << endl;
}
//Pirkimo funkcija
void PirkimoSkaiciavimas() {
    cout << "Ivesk kokia suma " << Trumpiniai[AntrasKeitiklis-1] << " noretum isigyti:" << endl;
    cin >> Kiekis;
    Suma = Kiekis / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1];
    cout << "Koficientas: " << 1 << " " << Trumpiniai[AntrasKeitiklis-1] << " = "<< 1 / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1] << " " << Trumpiniai[3] << endl;
    cout << Kiekis << " " << Trumpiniai[AntrasKeitiklis-1] << " kainuos: " << Suma << " " << Trumpiniai[3] << endl << endl;
}
//Pardavimo funkcija
void PardavimoSkaiciavimas() {
    cout << "Ivesk kokia suma " << Trumpiniai[AntrasKeitiklis-1] << " noretum parduoti:" << endl;
    cin >> Kiekis;
    Suma = Kiekis / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1];
    cout << "Koficientas: " << 1 << " " << Trumpiniai[AntrasKeitiklis-1] << " = "<< 1 / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1] << " " << Trumpiniai[3] << endl;
    cout << "Uz " << Kiekis << " " << Trumpiniai[AntrasKeitiklis-1] << " gausi: " << Suma << " " << Trumpiniai[3] << endl << endl;
}


int main() {
//Nustatomas skaiciu tikslumas simtuju tikslumu
    cout << fixed << showpoint<< setprecision(2) << endl;
//Funkcijom skrtas "Loop" kad galima butu naudoti programa kelis kartus iki iseinant
        for(Loop = 0; Loop <= LoopMax; Loop++) {
//Pirminis patikrinimas ar turetu veikti programa
            if(Loop<LoopMax-1) {
                cout << "Pasirinkite funkcija:\n" << Bendri << Pirkti << Parduoti;
                cin >> PirmasKeitiklis;
//Pagal vartotojo pasirinkima priskiriamas tekstas tolesniam naudojimui
//Vartotojo pasirinkimas issaugomas tolesniam funkcijos issaukimui
                switch (PirmasKeitiklis) {
                    case 1: {
                        Frazes = "kuria norite palyginti:\n";
                        break;
                    }
                    case 2: {
                        Frazes = "kuria ketinate pirkti:\n";
                        break;
                    }
                    case 3: {
                        Frazes = "kuria ketinate parduoti:\n";
                        break;
                    }
                    default: {
                        cout << "Netinkamas pasirinkimas!" << endl;
                        Loop = LoopMax-1;
                        break;
                    }
                }

//Draudiminis patikrinimas :)

                if(Loop == LoopMax-1) {
                    cout << "Testi programos veikima?\nTaip: 1\tNe: 2\n";
                    cin >> Choise;
                    if(Choise == 1) {
                        Loop=0;
                        continue;
                    }
                    if (Choise != 1) {
                        Loop = LoopMax+1;
                        cout << endl << "Viso gero" << endl;
                        break;
                    }
                }

//Nuo cia gerai

                cout << endl << "Pasirinkite valiuta "<< Frazes << GBP << USD << INR;
                cin >> AntrasKeitiklis;
//Isvedam atitinkama veiksmui skirta teksta, duodam pasirinkti kursa ir priskiriam trumpini
                if(AntrasKeitiklis >=1 & AntrasKeitiklis <=3) {
                    switch (AntrasKeitiklis) {
                        case 1:{Id = "GBP"; break;}     //Galejau naudoti "Trumpiniai[] matrica, bet gerai ir taip
                        case 2:{Id = "USD"; break;}
                        case 3:{Id = "INR"; break;}
                        default: {break;}
                    }
//Parenkama pasirinkta
                    switch (PirmasKeitiklis) {
                        case 1: {
                            cout << endl << "Pasirinkite valiuta kuria lyginsite su: " << Id << endl;
                            for (int i = 0; i <= 3; i++) {
                                if (i != AntrasKeitiklis-1) {
                                    cout << Trumpiniai[i] << ": " << i+1 << endl;
                                }
                            }
                            cin >> AntraValiuta;

                            BendroSkaiciavimas();
                            break;
                        }
                        case 2: {
                            PirkimoSkaiciavimas();
                            break;
                        }
                        case 3: {
                            PardavimoSkaiciavimas();
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }
            }
            else {
                cout << "Testi programos veikima?\nTaip: 1\tNe: 2\n";
                cin >> Choise;
                if(Choise == 1) {
                    Loop=0;
                }
                else if(Choise == 2) {
                    Loop = LoopMax+1;
                    cout << endl << "Viso gero" << endl;
                }
            }

        }
        return 0;
    }
