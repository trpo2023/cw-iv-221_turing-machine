#include <fstream>
#include <iostream>
#include <string>

#include "file_validation_check.hpp"

using namespace std;

int skip_space(string str, int i)
{
    while (str[i] == ' ')
        i++;
    return i;
}

int skip_unit(string str, int* index)
{
    int i = *index;
    i = skip_space(str, i);
    while (str[i] != ' ' && str[i] != '\0')
        i++;
    *index = i;
    if (str[i] == '\0')
        return -1;
    return 0;
}

// int skip_value(string str, int* index)
// {
//     int i = *index;
//     i = skip_space(str, i);
//     while (check_number(str[i]) == 0)
//         i++;
//     *index = i;
//     if (str[i] != ' ' && str[i] != '-')
//         return -1;
//     return 0;
// }

int check_arrow(string str, int* index)
{
    int i = *index;
    i = skip_space(str, i);
    if (str[i] != '-') {
        *index = i;
        return -1;
    }
    i++;
    if (str[i] != '>') {
        *index = i;
        return -1;
    }
    i++;
    *index = i;
    return 0;
}

int check_shift(string str, int* index)
{
    int i = *index;
    char c;
    i = skip_space(str, i);
    c = str[i];
    if (c != 'R' && c != 'r' && c != 'N' && c != 'n' && c != 'L' && c != 'l')
        return -1;
    *index = ++i;
    return 0;
}

int check_end(string str, int* index)
{
    int i = *index;
    i = skip_space(str, i);
    if (str[i] != '\0' && str[i] != '\n' && str[i] != '\r')
        return -1;
    return 0;
}

int check_line(string str, int* column)
{
    if (skip_unit(str, column) != 0)
        return -1;
    if (skip_unit(str, column) != 0)
        return -2;
    if (check_arrow(str, column) != 0)
        return -3;
    if (skip_unit(str, column) != 0)
        return -1;
    if (skip_unit(str, column) != 0)
        return -2;
    if (check_shift(str, column) != 0)
        return -4;
    if (check_end(str, column) != 0)
        return -5;

    return 0;
}

void error_locate(string str, int column)
{
    cout << str << endl;
    while (column > 0) {
        cout << " ";
        column--;
    }
    cout << "^" << endl;
}

void error_output(string str, int column, int num, int mode)
{
    string error;
    if (mode == -1) {
        error = ERROR_INCOMPLETE_DATA;
    } else if (mode == -2) {
        error = ERROR_INVALID_VALUE;
    } else if (mode == -3) {
        error = ERROR_EXCPECTED_DELIM;
    } else if (mode == -4) {
        error = ERROR_EXCPECTED_SHIFT_MODE;
    } else if (mode == -5) {
        error = ERROR_UNEXCPECTED_TOKEN;
    }

    error_locate(str, column);
    cout << ERROR_IN_RULES << num + 1 << " column " << column << ": " << error
         << endl;
}

int check_file(ifstream* fp)
{
    string str;
    int rez, all = 0, column, i = 1;
    while (getline((*fp), str)) {
        column = 0;
        rez = check_line(str, &column);
        if (rez != 0) {
            error_output(str, column, i, rez);
            all = -1;
        }
        i++;
    }
    return all;
}