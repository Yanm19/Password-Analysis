/*******************************************************************************
Yaniel Molina
George Melendez
28/4/2025
Password analyst
*******************************************************************************/

/*Yaniel*/
//George//
// Librerías

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <ctime>

using namespace std;

/*Utiliza un patron random para crear una contrsena aleatoria*/
string passRecomende() {
    string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string minusculas = "abcdefghijklmnopqrstuvwxyz";
    string numeros = "0123456789";
    string simbolos = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    string caracteres = mayusculas + minusculas + numeros + simbolos;
    string password;
    srand(time(0));
    for (int i = 0; i < 12; i++) {
        password += caracteres[rand() % caracteres.length()];
    }
    return password;
}

// verifica si la contrasena es segura
bool esContrasenaSegura(string contrasena, bool& cumpleMayuscula, bool& cumpleMinuscula, bool& cumpleNumero, bool& cumpleSimbolo, int caracteristicas[]) {
    bool segura = true;

    cumpleMayuscula = false;
    cumpleMinuscula = false;
    cumpleNumero = false;
    cumpleSimbolo = false;

    //Sacado de chat gpt para verificar que contrasena no tenga espacio
  // OpenAI. (2023). ChatGPT (versión del 6 de noviembre de 2023 ) GPT-4 Turbo].https://chat.openai.com/chat

    if (contrasena.find(" ") != string::npos) {
        cout << "Error: La contrasena no debe contener espacios.\n";
        segura = false;
    }
    //loop para verificar que contenga las caracteristicas
    for (int i = 0; i < contrasena.length(); i++) {
        if (isupper(contrasena[i])) {
            cumpleMayuscula = true;
            caracteristicas[0]++;
        }
        else if (islower(contrasena[i])) {
            cumpleMinuscula = true;
            caracteristicas[1]++;
        }
        else if (isdigit(contrasena[i])) {
            cumpleNumero = true;
            caracteristicas[2]++;
        }
        else {
            cumpleSimbolo = true;
            caracteristicas[3]++;
        }
    }

    if (!(contrasena.length() >= 12 && cumpleMayuscula && cumpleMinuscula && cumpleNumero && cumpleSimbolo)) {
        segura = false;
    }

    return segura;
}

/*Guarda la contrasena en un notepad*/
void guardarContrasenaEnArchivo(string contrasena, bool segura) {
    ofstream archivo("passwords.txt", ios::app); /*El modo agregar guarda la contrsena en un mismo archivo*/
    if (archivo.is_open()) {
        archivo << "Contrasena ingresada: " << contrasena << endl;
        archivo << "Seguridad: " << (segura ? "Segura" : "Insegura") << endl;
        archivo << "------------------------------------------" << endl;
        archivo.close();
    }
    else {
        cout << "Error al abrir el archivo." << endl;
    }
}

int main() {
    int opcion;
    string contrasena;
    bool cumpleMayuscula, cumpleMinuscula, cumpleNumero, cumpleSimbolo;
    int caracteristicas[4] = { 0, 0, 0, 0 };
    bool segura = false;

    do {
        /*Este es el menu de opcion*/
        cout << "\n----- MENU DE OPCIONES -----\n";
        cout << "1. Analizar contrasena\n";
        cout << "2. Generar contrasena segura\n";
        cout << "3. Ver historial de contrasenas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        /*Este es el proceso de opciones que el usuario tiene*/
        switch (opcion) {
        case 1:
            cout << "\nIngrese la contrasena a analizar: ";
            getline(cin, contrasena);

            if (contrasena.find(" ") != string::npos) {
                cout << "Error: La contrasena no debe contener espacios.\n";
                break;
            }

            for (int i = 0; i < 4; i++) {
                caracteristicas[i] = 0;
            }

            segura = esContrasenaSegura(contrasena, cumpleMayuscula, cumpleMinuscula, cumpleNumero, cumpleSimbolo, caracteristicas);

            cout << "\nResultado del analisis de la contrasena:\n";

            if (contrasena.length() >= 12) {
                cout << "Longitud minima (12 caracteres): Cumple" << endl;
            }
            else {
                cout << "Longitud minima (12 caracteres): No cumple" << endl;
            }

            if (cumpleMayuscula) {
                cout << "Contiene mayusculas: Cumple" << endl;
            }
            else {
                cout << "Contiene mayusculas: No cumple" << endl;
            }

            if (cumpleMinuscula) {
                cout << "Contiene minusculas: Cumple" << endl;
            }
            else {
                cout << "Contiene minusculas: No cumple" << endl;
            }

            if (cumpleNumero) {
                cout << "Contiene numeros: Cumple" << endl;
            }
            else {
                cout << "Contiene numeros: No cumple" << endl;
            }

            if (cumpleSimbolo) {
                cout << "Contiene simbolos: Cumple" << endl;
            }
            else {
                cout << "Contiene simbolos: No cumple" << endl;
            }
            /*Esto mide los caracteres usados en a contrasena*/
            cout << "\nDetalles adicionales de la contrasena:\n";
            cout << "Cantidad de mayusculas: " << caracteristicas[0] << endl;
            cout << "Cantidad de minusculas: " << caracteristicas[1] << endl;
            cout << "Cantidad de numeros: " << caracteristicas[2] << endl;
            cout << "Cantidad de simbolos: " << caracteristicas[3] << endl;

            if (segura) {
                cout << "La contrasena es SEGURA.\n";
            }
            else {
                cout << "La contrasena es INSEGURA.\n";
            }

            guardarContrasenaEnArchivo(contrasena, segura);
            break;

        case 2:
            contrasena = passRecomende();
            cout << "Contrasena generada: " << contrasena << endl;
            guardarContrasenaEnArchivo(contrasena, true);
            break;

        case 3:
            cout << "Abriendo historial de contrasenas...\n";
            system("notepad passwords.txt");
            break;

        case 4:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);

    return 0;
}
