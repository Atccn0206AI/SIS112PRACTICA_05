// Materia: Programación I, Paralelo 1
// Autor: Manuel Franco Jimenez Mendoza
// Fecha creación: 24/09/2023
// Fecha modificación: 24/09/2023
// Número de ejericio: 03
/* Realice un programa en C++ con funciones y estructuras para el estacionamiento del Multicine. Este estacionamiento cuenta con 4 pisos, cada piso tiene 
distintas capacidades de autos:
Piso 1 – 50 autos
Piso 2 – 40 autos
Piso 3 – 30 autos
Piso 4 – 45 autos
El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas, automóviles, minivans y motocicletas), marca del auto, modelo del auto y color
del auto. Escribir un programa en C++ utilizando funciones y estructuras para:
• Simular la entrada de vehículos, el programa debe pedir la cantidad de
vehículos ingresados y el programa debe simular los tipos de vehículo, la
marca, el modelo, el color y en que piso se han estacionado.
• La simulación puede repetirse varias veces hasta que el usuario ingrese el valor
de 0 (cero) en la cantidad de vehículos. La cantidad de vehículos debe se
incremental.
• Luego de cada ingreso de vehículos se desea saber cuantos hay estacionado en
cada piso.
• Cuantos son vagoneta, camionetas, automóviles, minivans y motocicletas.
• Hacer un reporte por colores de autos, modelo y marca.
• La simulación debe determinar cuando el parqueo se ha llenado.
• La simulación debe determinar cuántos espacios libres queda.*/
#include <iostream>
#include <string>
using namespace std;

// Estructura para un vehículo
struct Vehiculo {
    string tipo;
    string marca;
    string modelo;
    string color;
};

// Estructura para un piso de estacionamiento
struct Piso {
    int capacidad;
    int ocupados;
    int vagonetas;
    int camionetas;
    int automoviles;
    int minivans;
    int motocicletas;
};

// Función para ingresar un vehículo al estacionamiento
void ingresarVehiculo(Piso& piso, Vehiculo& vehiculo) {
    if (piso.ocupados < piso.capacidad) {
        piso.ocupados++;
        if (vehiculo.tipo == "Vagoneta") {
            piso.vagonetas++;
        } else if (vehiculo.tipo == "Camioneta") {
            piso.camionetas++;
        } else if (vehiculo.tipo == "Automovil") {
            piso.automoviles++;
        } else if (vehiculo.tipo == "Minivan") {
            piso.minivans++;
        } else if (vehiculo.tipo == "Motocicleta") {
            piso.motocicletas++;
        }
        cout << "El vehiculo ha sido estacionado" << endl;
    } else {
        cout << "El estacionamiento en este piso esta lleno" << endl;
    }
}

// Función para imprimir el estado actual del estacionamiento
void imprimirEstado(const Piso& piso) {
    cout << "Capacidad: " << piso.capacidad << endl;
    cout << "Ocupados: " << piso.ocupados << endl;
    cout << "Vagonetas: " << piso.vagonetas << endl;
    cout << "Camionetas: " << piso.camionetas << endl;
    cout << "Automoviles: " << piso.automoviles << endl;
    cout << "Minivans: " << piso.minivans << endl;
    cout << "Motocicletas: " << piso.motocicletas << endl;
}

int main() {
    Piso pisos[4] = {
        {50, 0, 0, 0, 0, 0, 0},
        {40, 0, 0, 0, 0, 0, 0},
        {30, 0, 0, 0, 0, 0, 0},
        {45, 0, 0, 0, 0, 0, 0}
    };

    int cantidadVehiculos = 0;

    while (true) {
        cout << "Ingrese la cantidad de vehiculos a estacionar (0 para salir): ";
        cin >> cantidadVehiculos;

        if (cantidadVehiculos == 0) {
            break;
        }

        for (int i = 0; i < cantidadVehiculos; i++) {
            Vehiculo vehiculo;
            cout << "Ingrese el tipo de vehículo (Vagoneta, Camioneta, Automovil, Minivan, Motocicleta): ";
            cin >> vehiculo.tipo;
            cout << "Ingrese la marca del vehículo: ";
            cin >> vehiculo.marca;
            cout << "Ingrese el modelo del vehículo: ";
            cin >> vehiculo.modelo;
            cout << "Ingrese el color del vehículo: ";
            cin >> vehiculo.color;

            for (int j = 0; j < 4; j++) {
                if (pisos[j].ocupados < pisos[j].capacidad) {
                    ingresarVehiculo(pisos[j], vehiculo);
                    break;
                }
            }
        }

        for (int j = 0; j < 4; j++) {
            cout << "Piso " << j + 1 << ":" << endl;
            imprimirEstado(pisos[j]);
        }
    }
    return 0;
}

