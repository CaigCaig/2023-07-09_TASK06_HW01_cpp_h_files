#include <iostream>
#include <Windows.h>
#include <string>
#include "calc.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string s;
    double arg1, arg2;
    int op;

    do {
        cout << "Введите первое число: ";
        try {
            cin >> s;
            arg1 = stod(s);
        }
        catch (const std::invalid_argument&) {
            return calc_errors::invalid_argument;
        }

        cout << "Введите второе число: ";
        try {
            cin >> s;
            arg2 = stod(s);
        }
        catch (const std::invalid_argument&) {
            return calc_errors::invalid_argument;
        }

        std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
        try {
            std::cin >> s;
            op = std::stoi(s);
        }
        catch (const std::invalid_argument&) {
            return calc_errors::invalid_argument;
        }

        if ((op < 1) || (op > 5)) return calc_errors::operation_error;

        switch (op) {
        case 1:
            cout << arg1 << " плюс " << arg2 << " = " << add(arg1, arg2) << endl;
            break;
        case 2:
            cout << arg1 << " минус " << arg2 << " = " << sub(arg1, arg2) << endl;
            break;
        case 3:
            cout << arg1 << " умножить на " << arg2 << " = " << mul(arg1, arg2) << endl;
            break;
        case 4:
            cout << arg1 << " делить на " << arg2 << " = " << div(arg1, arg2) << endl;
            break;
        case 5:
            cout << arg1 << " в степени " << arg2 << " = " << exp(arg1, arg2) << endl;
            break;
        }
    } while (op);

    system("pause");
}