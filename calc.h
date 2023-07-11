#pragma once

enum calc_errors : int {
    no_error,
    division_by_zero,
    invalid_argument,
    no_operation,
    operation_error
}; 

double add(double x1, double x2);
double sub(double x1, double x2);
double mul(double x1, double x2);
double div(double x1, double x2);
double exp(double x1, double x2);