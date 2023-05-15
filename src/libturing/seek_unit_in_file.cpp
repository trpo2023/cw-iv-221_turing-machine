#include "changes_according_to_the_rules.hpp"

using namespace std;

int seek_next_unit_in_file(string str, string unit, int* index)
{
    string unit_fp;
    int i = *index;
    int sim = 0;
    i = skip_space(str, i);
    while (str[i] != ' ' && str[i] != '\0') {
        i++;
        sim++;
    }
    unit_fp.insert(0, str, i - sim, sim);
    *index = i;
    if (unit_fp == unit)
        return 0;
    return -1;
}

int skip_for_new_unit(string str)
{
    int i = 0;
    while (str[i] != '>')
        i++;
    i++;
    return i;
}

string get_unit_in_file(string str, int* index)
{
    int i = *index;
    int sim = 0;
    string unit;
    i = skip_space(str, i);
    while (str[i] != ' ' && str[i] != '\0') {
        i++;
        sim++;
    }
    unit.insert(0, str, i - sim, sim);
    *index = i;
    return unit;
}

int get_shift(string str, int* index)
{
    int i = *index;
    char c;
    i = skip_space(str, i);
    c = str[i];
    if (c == 'L' || c == 'l')
        return -1;
    if (c == 'N' || c == 'n')
        return 0;
    return 1;
}

int seek_unit_in_file(ifstream* fp, string* state, string* value)
{
    string str;
    int check = 0, i = 0;
    (*fp).clear();
    (*fp).seekg(0, ios::beg);
    while (getline((*fp), str)) {
        i = 0;
        if (seek_next_unit_in_file(str, *state, &i) == 0) {
            if (seek_next_unit_in_file(str, *value, &i) == 0) {
                check = 1;
                break;
            }
        }
    }
    if (check == 0)
        return -2;

    i = skip_for_new_unit(str);
    *state = get_unit_in_file(str, &i);
    *value = get_unit_in_file(str, &i);

    return get_shift(str, &i);
}