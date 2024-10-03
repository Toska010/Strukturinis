#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int PirmasKeitiklis;
int AntrasKeitiklis;

int LoopMax = 6;
int Loop;
int Choise;

string Bendri = "1 - Valiutos kurso palyginimas\n";
string Pirkti = "2 - Valiutos pirkimas\n";
string Parduoti = "3 - Valiutos pardavimas\n";

string Id;
string GBP = "1 - Didziosios Britanijos svaras GBP\n";
string USD = "2 - Jungtiniu Amerikos Valstiju doleris USD\n";
string INR = "3 - Indijos rupijos INR\n";
string EUR = "4 - Euras EUR\n";

string Frazes;

double Suma;
double Kiekis;

int AntraValiuta;

string Trumpiniai[4] = {"GBP", "USD", "INR", "EUR"};

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

void BendroSkaiciavimas() {
    cout << "Ivesk turima suma palyginimui:\n";
    cin >> Kiekis;
    Suma = Kiekis / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1] * Valiutos[PirmasKeitiklis-1][AntraValiuta-1];
    cout << "Koficientas: " << 1 << " " << Trumpiniai[AntrasKeitiklis-1] << " = "<< Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1] * Valiutos[PirmasKeitiklis-1][AntraValiuta-1]
    << " " << Trumpiniai[AntraValiuta-1] << "\tSuma: " << Suma << " " << Trumpiniai[AntraValiuta-1] << endl << endl;
}

void PirkimoSkaiciavimas() {
    cout << "Ivesk kokia suma " << Trumpiniai[AntrasKeitiklis-1] << " noretum isigyti:" << endl;
    cin >> Kiekis;

    Suma = Kiekis / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1];
    cout << "Koficientas: " << 1 << " " << Trumpiniai[AntrasKeitiklis-1] << " = "<< 1 / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1] << " " << Trumpiniai[3] << endl;
    cout << Kiekis << " " << Trumpiniai[AntrasKeitiklis-1] << " kainuos: " << Suma << " " << Trumpiniai[3] << endl << endl;
}

void PardavimoSkaiciavimas() {
    cout << "Ivesk kokia suma " << Trumpiniai[AntrasKeitiklis-1] << " noretum parduoti:" << endl;
    cin >> Kiekis;
    Suma = Kiekis / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1];
    cout << "Koficientas: " << 1 << " " << Trumpiniai[AntrasKeitiklis-1] << " = "<< 1 / Valiutos[PirmasKeitiklis-1][AntrasKeitiklis-1] << " " << Trumpiniai[3] << endl;
    cout << "Uz " << Kiekis << " " << Trumpiniai[AntrasKeitiklis-1] << " gausi: " << Suma << " " << Trumpiniai[3] << endl << endl;
}


int main() {
    cout << fixed << showpoint<< setprecision(2) << endl;
        for(Loop = 0; Loop <= LoopMax; Loop++) {
            if(Loop<LoopMax-1) {
                cout << "Pasirinkite funkcija:\n" << Bendri << Pirkti << Parduoti;
                cin >> PirmasKeitiklis;
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
                if(AntrasKeitiklis >=1 & AntrasKeitiklis <=3) {
                    switch (AntrasKeitiklis) {
                        case 1:{Id = "GBP"; break;}
                        case 2:{Id = "USD"; break;}
                        case 3:{Id = "INR"; break;}
                        default: {break;}
                    }
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
