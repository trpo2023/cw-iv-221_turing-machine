#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int skip_space(string str, int i)
{
    while(str[i] == ' ')
        i++;
    return i;
}

int skip_state(string str, int *index)
{
    int i = *index;
    i = skip_space(str, i);
    while(str[i] != ' ' && str[i] != '\0')
        i++;
    *index = i;
    if(str[i] == '\0')
        return -1;
    return 0;
}

int check_number(char c)
{
    if(c < 48 || c > 57)
        return -1;
    return 0;
}

int check_value(string str, int *index)
{
    int i = *index;
    i = skip_space(str, i);
    while(check_number(str[i]) == 0)
        i++;
    *index = i;
    if(str[i] != ' ' && str[i] != '-')
        return -1;
    return 0;
}

int check_arrow(string str, int *index)
{
    int i = *index;
    i = skip_space(str, i);
    if(str[i] != '-')
    {
        *index = i;
        return -1;
    }
    i++;
    if(str[i] != '>')
    {
        *index = i;
        return -1;
    }
    i++;
    *index = i;
    return 0;
}

int check_shift(string str, int *index)
{
    int i = *index;
    char c;
    i = skip_space(str, i);
    c = str[i];
    if(c != 'R' && c != 'r' && c != 'N' && c != 'n' && c != 'L' && c != 'l')
        return -1;
    *index = ++i;
    return 0;
}

int check_end(string str, int *index)
{
    int i = *index;
    i = skip_space(str, i);
    if(str[i] != '\0' && str[i] != '\n' && str[i] != '\r')
        return -1;
    return 0;
}

int check_line(string str, int *column)
{
    if(skip_state(str, column) != 0)
        return -1;
    if(check_value(str, column) != 0)
        return -2;
    if(check_arrow(str, column) != 0)
        return -3;
    if(skip_state(str, column) != 0)
        return -1;
    if(check_value(str, column) != 0)
        return -2;
    if(check_shift(str, column) != 0)
        return -4;
    if(check_end(str, column) != 0)
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
    if(mode == -1)
    {
        error_locate(str, column);
        cout << "Error in the shift rules file at string " << num << " , column " << column << ": incomplete data" << endl;
    }
    if(mode == -2)
    {
        error_locate(str, column);
        cout << "Error in the shift rules file at string " << num << " , column " << column << ": invalid value. Expected <int>" << endl;
    }
    if(mode == -3)
    {
        error_locate(str, column);
        cout << "Error in the shift rules file at string " << num << " , column " << column << ": expected \"->\"" << endl;
    }
    if(mode == -4)
    {
        error_locate(str, column);
        cout << "Error in the shift rules file at string " << num << " , column " << column << ": expected shift mode (R, L or N)" << endl;
    }
    if(mode == -5)
    {
        error_locate(str, column);
        cout << "Error in the shift rules file at string " << num << " , column " << column << ": unexpected token" << endl;
    }
}

int check_file(ifstream *fp)
{
    string str;
    int rez, all = 0, column, i = 1;
    while(getline((*fp), str))
    {
        column = 0;
        rez = check_line(str, &column);
        if(rez != 0)
        {
            error_output(str, column, i, rez);
            all = -1;
        }
        i++;
    }
    return all;
}