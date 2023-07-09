#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>
#include "calc.h"

int calc() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string s;
    float arg1, arg2, result;
    int op;

    std::cout << "������� ������ �����: ";
    try {
        std::cin >> s;
        arg1 = static_cast<float>(std::stof(s));
    }
    catch (const std::invalid_argument&) {
        return calc_errors::invalid_argument;
    }

    std::cout << "������� ������ �����: ";
    try {
        std::cin >> s;
        arg2 = static_cast<float>(std::stof(s));
    }
    catch (const std::invalid_argument&) {
        return calc_errors::invalid_argument;
    }

    std::cout << "�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
    try {
        std::cin >> s;
        op = static_cast<int>(std::stoi(s));
    }
    catch (const std::invalid_argument&) {
        return calc_errors::invalid_argument;
    }

    if ((op < 1) || (op > 5)) return calc_errors::operation_error;

    switch (op) {
    case 1:
        result = arg1 + arg2;
        std::cout << arg1 << " ���� " << arg2 << " = " << result << std::endl;
        break;
    case 2:
        result = arg1 - arg2;
        std::cout << arg1 << " ����� " << arg2 << " = " << result << std::endl;
        break;
    case 3:
        result = arg1 * arg2;
        std::cout << arg1 << " �������� �� " << arg2 << " = " << result << std::endl;
        break;
    case 4:
        if (arg2 == 0) return calc_errors::division_by_zero;
        result = arg1 / arg2;
        std::cout << arg1 << " ������ �� " << arg2 << " = " << result << std::endl;
        break;
    case 5:
        result = pow(arg1, arg2);
        std::cout << arg1 << " � ������� " << arg2 << " = " << result << std::endl;
        break;
    }
    return calc_errors::no_error;
}