// Materia: Programación I, Paralelo 1
// Autor: Manuel Franco Jimenez Mendoza
// Fecha creación: 23/09/2023
// Fecha modificación: 23/09/2023
// Número de ejericio: 02
/* De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y
nos devuelva el país que mayor número de medallas ha ganado.*/
#include <iostream>
#include <cstring>
using namespace std;

struct datos {
    char nombre[40];
    char pais[25];
};

struct atleta {
    char deporte[30];
    struct datos pers;
    int nmedallas;
};

int main() {
    int N;
    cout << "Ingrese el numero de atletas: "; cin >> N;

    struct atleta ats[30];

    for (int i = 0; i < N; i++) {
        cout << "Ingrese los datos del atleta " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.ignore();
        cin.getline(ats[i].pers.nombre, sizeof(ats[i].pers.nombre));
        cout << "Pais: ";
        cin.getline(ats[i].pers.pais, sizeof(ats[i].pers.pais));
        cout << "Deporte: ";
        cin.getline(ats[i].deporte, sizeof(ats[i].deporte));
        cout << "Numero de medallas: ";
        cin >> ats[i].nmedallas;
    }

    char paisMayorMedallas[25];
    int maxMedallas = -1;

    for (int i = 0; i < N; i++) {
        if (ats[i].nmedallas > maxMedallas) {
            maxMedallas = ats[i].nmedallas;
            strcpy(paisMayorMedallas, ats[i].pers.pais);
        }
    }

    cout << "El pais con mayor numero de medallas es: " << paisMayorMedallas << " con " << maxMedallas << " medallas" << endl;

    return 0;
}

