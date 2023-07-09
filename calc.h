#pragma once

enum calc_errors : int {
    no_error,
    division_by_zero,
    invalid_argument,
    no_operation,
    operation_error
}; 

int calc();
