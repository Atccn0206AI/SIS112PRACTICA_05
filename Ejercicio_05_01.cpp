// Materia: Programación I, Paralelo 1
// Autor: MANUEL JIMENEZ MENDOZA
// Fecha creación: 23/09/2023
// Fecha modificación: 23/09/2023
// Número de ejericio: 01
/* Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipostruct llamada “empleado”.
La información con que se cuenta es: nombre, ci, departamento y salario.Realizar un programa en C++ que lea un array de estructura de los datos de N
empleados e imprima los siguiente:
• Empleado con mayor salario
• Empleado con menor salario
• Promedio salarial
• Promedio por departamento
• Departamento con mayor salario en promedio
• Departamento con menor salario en promedio*/

#include <iostream>
#include <string>
using namespace std;
struct Empleado{
    string nombre;
    string ci;
    string departamento;
    double salario;
};

int main() {
    int n; // Número de empleados
    cout << "Ingrese el número de empleados: "; cin >> n;

    // Declaración y asignación de memoria para el arreglo de empleados
    Empleado empleados[n];

    // Leer los datos de los empleados
    for (int i = 0; i < n; i++) {
        cout << "Ingrese los datos del empleado " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, empleados[i].nombre);
        cout << "CI: "; cin >> empleados[i].ci;
        cout << "Departamento: "; 
		cin.ignore();
        getline(cin, empleados[i].departamento);
        cout << "Salario: "; cin >> empleados[i].salario;
    }

    // Inicializar variables para el cálculo
    Empleado empleadomayorsalario = empleados[0];
    Empleado empleadomenorsalario = empleados[0];
    double sumasalarios = 0;
    double promediosalario;
    double sumasalariospordepartamento = 0;
    int contadorempleadospordepartamento = 0;
    string departamentoconmayorpromedio;
    string departamentoconmenorpromedio;
    double salariomaximopordepartamento = 0;
    double salariominimopordepartamento = 1e9; // Un valor grande inicial

    // Calcular empleado con mayor y menor salario, y suma de salarios
    for (int i = 0; i < n; i++) {
        if (empleados[i].salario > empleadomayorsalario.salario) {
            empleadomayorsalario = empleados[i];
        }
        if (empleados[i].salario < empleadomenorsalario.salario) {
            empleadomenorsalario = empleados[i];
        }
        sumasalarios += empleados[i].salario;
    }

    // Calcular promedio salarial
    promediosalario = sumasalarios / n;

    // Calcular promedio por departamento, departamento con mayor y menor salario promedio
    for (int i = 0; i < n; i++) {
        sumasalariospordepartamento += empleados[i].salario;
        contadorempleadospordepartamento++;
        if (i == n - 1 || empleados[i].departamento != empleados[i + 1].departamento) {
            double salariopromediopordepartamento = sumasalariospordepartamento / contadorempleadospordepartamento;
            if (salariopromediopordepartamento > salariomaximopordepartamento) {
                salariomaximopordepartamento = salariopromediopordepartamento;
                departamentoconmayorpromedio = empleados[i].departamento;
            }
            if (salariopromediopordepartamento < salariominimopordepartamento) {
                salariominimopordepartamento = salariopromediopordepartamento;
                departamentoconmenorpromedio = empleados[i].departamento;
            }
            sumasalariospordepartamento = 0;
            contadorempleadospordepartamento = 0;
        }
    }

    // Imprimir resultados
    cout << "Empleado con mayor salario:" << endl;
    cout << "Nombre: " << empleadomayorsalario.nombre << endl;
    cout << "CI: " << empleadomayorsalario.ci << endl;
    cout << "Departamento: " << empleadomayorsalario.departamento << endl;
    cout << "Salario: " << empleadomayorsalario.salario << endl;

    cout << "Empleado con menor salario:" << endl;
    cout << "Nombre: " << empleadomenorsalario.nombre << endl;
    cout << "CI: " << empleadomenorsalario.ci << endl;
    cout << "Departamento: " << empleadomenorsalario.departamento << endl;
    cout << "Salario: " << empleadomenorsalario.salario << endl;

    cout << "Promedio salarial: " << promediosalario << endl;

    cout << "Promedio por departamento:" << endl;
    cout << "Departamento con mayor salario promedio: " << departamentoconmayorpromedio << endl;
    cout << "Departamento con menor salario promedio: " << departamentoconmenorpromedio << endl;

    return 0;
}
