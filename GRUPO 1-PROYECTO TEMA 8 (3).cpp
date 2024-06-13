/* PROYECTO FINAL DE PROGRA */
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

void opciones();
void opcion_A();
void opcion_B();
void opcion_C();
void opcion_D();
void opcion_E();

struct Indice {
    size_t index;
    size_t length;
};

char* cifrarMensaje(const string& mensajeOriginal, const string& claveCorrespondencia) {
    char mapaCorrespondencias[26];
    for (int i = 0; i < 26; ++i) {
        mapaCorrespondencias[i] = claveCorrespondencia[i];
    }

    Indice indice;
    indice.index = 0;
    indice.length = mensajeOriginal.length();

    char* mensajeCifrado = new char[indice.length + 1];

    for (indice.index = 0; indice.index < indice.length; ++indice.index) {
        char caracter = mensajeOriginal[indice.index];
        if (caracter >= 'a' && caracter <= 'z') {
            mensajeCifrado[indice.index] = mapaCorrespondencias[caracter - 'a'];
        } else {
            mensajeCifrado[indice.index] = caracter;
        }
    }
    mensajeCifrado[indice.length] = '\0';

    return mensajeCifrado;
}

int main() {
    opciones();
    return 0;
}

void opciones() {
    char opcion;
    do {
        cout << "\nMenu de Opciones: \n\n";
        cout << "a. Lee lineas de texto, obtiene las palabras y las muestra en orden alfabetico (maximo 28 palabras por linea).\n";
        cout << "b. Encripta un mensaje sustituyendo cada caracter por el que esta tres posiciones adelante en el alfabeto.\n";
        cout << "c. Encripta un mensaje sustituyendo cada caracter segun una cadena de correspondencias predefinida (punteros).\n";
        cout << "d. Encripta un texto sustituyendo letras minusculas por otras segun un array cifrado.\n";
        cout << "e. Encripta un mensaje sustituyendo cada letra por otra en todo el mensaje.\n";
        cout << "f. Salir.\n\n";
        cout << "Elija que opcion desea (solo con letras minusculas): ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 'a': 
                opcion_A();
                break;
            case 'b': 
                opcion_B();
                break;
            case 'c': 
                opcion_C();
                break;
            case 'd': 
                opcion_D();
                break;
            case 'e': 
                opcion_E();
                break;
            case 'f': 
                cout << "Presione ENTER para cerrar la aplicacion.\n";
                break;
            default: 
                cout << "\n\nIngrese una opcion valida: \n";
                break;
        }
    } while (opcion != 'f');
}

void opcion_A() {
    int e = 0;
    string mayuscula = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string minuscula = "abcdefghijklmnopqrstuvwxyz";
    string texto;
    string cadena[26];
    cout << "\nIngrese un texto para dividir: ";
    getline(cin, texto);
    for (int i = 0; i < texto.length(); i++) {
        for (int k = 0; k < 26; k++) {
            if (texto[i] == mayuscula[k]) {
                texto[i] = minuscula[k];
            }
        }
    }
    istringstream palabra(texto);
    while (palabra >> cadena[e]) {
        e++;
    }
    sort(cadena, cadena + e);
    for (int i = 0; i < e; i++) {
        cout << i + 1 << "..." << cadena[i] << endl;
    }
}

void opcion_B() {
    string mensaje;
    cout << "\nIntroduce el mensaje a cifrar: ";
    getline(cin, mensaje);
    string cifrado = "";
    for (size_t i = 0; i < mensaje.size(); ++i) {
        char c = mensaje[i];
        if (c >= 'A' && c <= 'Z') {
            cifrado += char((c - 'A' + 3) % 26 + 'A');
        } else if (c >= 'a' && c <= 'z') {
            cifrado += char((c - 'a' + 3) % 26 + 'a');
        } else {
            cifrado += c;
        }
    }
    cout << "Mensaje cifrado: " << cifrado << endl;
}

void opcion_C() {
    string mensajeOriginal;
    cout << "Ingrese el mensaje codificado: ";
    getline(cin, mensajeOriginal);

    string claveCorrespondencia;
    cout << "Ingrese la clave de correspondencia: ";
    getline(cin, claveCorrespondencia);

    char* mensajeCifrado = cifrarMensaje(mensajeOriginal, claveCorrespondencia);

    cout << "Mensaje cifrado: '" << mensajeCifrado << "'" << endl;
    cout << "Ubicacion del puntero: " << static_cast<void*>(mensajeCifrado) << endl;

    delete[] mensajeCifrado;
}

void opcion_D() {
    string palabra, alfabeto = "abcdefghijklmnopqrstuvwxyz";
    char codigo[26];
    for (int i = 0; i < 26; i++) {
        cout << "\nIngrese el caracter #" << i + 1 << " que serviran para encriptar: ";
        cin >> codigo[i];
        for (int k = 0; k < i; k++) {
            if (codigo[i] == codigo[k]) {
                while (codigo[i] == codigo[k]) {
                    cout << "\nIngrese un caracter no repetido: ";
                    cin >> codigo[i];
                }
            } else {
                continue;
            }
        }
    }
    cin.ignore();
    cout << "Ingrese el texto que desea encriptar: ";
    getline(cin, palabra);
    for (int i = 0; i < 99; i++) {
        for (int k = 0; k < 26; k++) {
            if (palabra[i] == alfabeto[k]) {
                palabra[i] = codigo[k];
                break;
            } else {
                continue;
            }
        }
    }
    cout << "\nEl codigo decodificado es: " << palabra;
}

void opcion_E() {
    char ALFABETO[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                         'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string CODIGO;
    string CADENA;
    string DECO[99];
    int longitud = 0;
    int NUM = 1;
    for (int h = 0; h < NUM; h++) {
        cout << "\nIngresa el mensaje codificado: ";
        getline(cin, CODIGO);
        cout << "\nIngrese la cadena: ";
        getline(cin, CADENA);

        longitud = CODIGO.length();
        for (int i = 0; i < longitud; i++) {
            for (int k = 0; k < 27; k++) {
                if (CODIGO[i] == CADENA[k]) {
                    CODIGO[i] = ALFABETO[k];
                    break;
                } else {
                    continue;
                }
            }
        }
        DECO[h] = CODIGO;
        for (int u = 0; u <= 99; u++) {
            CODIGO[u] = ' ';
        }
        longitud = 0;
    }
    for (int h = 0; h < NUM; h++) {
        cout << h + 1 << "-" << DECO[h] << endl;
    }
}

