#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "NumberConverter.h"
#include "Factorial.h"
#include "Fibonacci.h"

using namespace std;

const int BINARY_OPTION = 1;
const int FIBONACCI_OPTION = 2;
const int FACTORIAL_OPTION = 3;
const int EXIT_OPTION = 0;

Fibonacci fibonacci = Fibonacci();
Factorial factorial = Factorial();

vector<string> split(string line) {
    vector<string> result = vector<string>();

    for (int i = 0; i < line.size(); i++) {
        char c;
        string s = "";

        while (i < line.size() &&
            (c = line.at(i)) != ',') {
            s = s + c;
            i++;
        }

        result.push_back(s);
    }

    return result;
}

vector<int> readNumbersFromFile(std::string fileName) {
    vector<int> numbers = vector<int>();

    ifstream file;

    file.open(fileName, ios::in);

    if (file.is_open()) {
        while (!file.eof()) {
            std::string line;
            getline(file, line);

            vector<string> lines = split(line);

            for (int i = 0; i < lines.size(); i++) {
                int number = stoi(lines[i]);

                numbers.push_back(number);
            }
        }
    }

    return numbers;
}


void writeResults(vector<string> results) {
    fstream output;
    output.open("output.csv", ios::out);

	int size = results.size();
    for (int i = 0; i < size; i++) {
        output << results[i] << "\n";
    }
}

int menu() {
    cout << "\n1. Convertir números decimales a binarios\n";
    cout << "2. Mostrar serie de fibonacci\n";
    cout << "3. Mostrar el factorial de un número\n";
    cout << "0. Salir\n";
    cout << "Ingrese la opción que desea: ";

    int option;
    cin >> option;
    return option;
}

int binaryNumbersMenu() {
    int option;
    do
    {
        cout << "\n1. Convertir un número\n";
        cout << "2. Convertir varios números\n";
        cout << "Ingrese una opción: ";

        cin >> option;
    } while (option < 1 && option > 2);

    if (option == 1) {
        int x;
        cout << "Ingrese un número: ";
        cin >> x;
        cout << x << " = " << NumberPrinter::toBase2String(x) << "\n";
    }
    else {
        string fileName;
        cout << "Ingrese la ubicación del archivo: ";
        cin >> fileName;
        vector<int> numbers = readNumbersFromFile(fileName);
        vector<string> results = NumberPrinter::toBase2Strings(numbers);
        writeResults(results);
        system("output.csv");
    }

    return option;
}

void fibonacciMenu() {
    int n;
    cout << "\nIngrese un número: ";
    cin >> n;

    for (int i = 0; i <= n; i++) {
        cout << "Fibonacci(" << i << ") = " << fibonacci.calcular(i) << "\n";
    }
}

void factorialMenu() {
    int n;
    cout << "\nIngrese un número: ";
    cin >> n;

    cout << "Factorial(" << n << ") = " << factorial.calcular(n) << "\n";
}

int handleOption(int option) {
    switch (option)
    {
    case BINARY_OPTION:
        option = binaryNumbersMenu();
        break;
    case FIBONACCI_OPTION:
        fibonacciMenu();
        break;
    case FACTORIAL_OPTION:
        factorialMenu();
        break;
    case EXIT_OPTION:
        cout << "¡Adiós!";
        break;
    default:
        cout << "Opción no válida\n";
        return int::MaxValue;
    }

    return option;
}

int main()
{
    int option;
    do {
        option = menu();
        option = handleOption(option);
    } while (option > 0);
    
    return 0;
}
