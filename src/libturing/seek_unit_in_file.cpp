#include "changes_according_to_the_rules.hpp"

using namespace std;

int skip_space(string str, int i)
{
    while(str[i] == ' ')
        i++;
    return i;
}

int check_number(char c)
{
    if(c < 48 || c > 57)
        return -1;
    return 0;
}

int seek_state_in_file(string str, string state, int *index)
{
    int i = *index;
    int sim = 0;
    i = skip_space(str, i);
    string state_fp;
    while(str[i] != ' ')
    {
        i++;
        sim++;
    }
    state_fp.insert(0, str, i - sim, sim);
    *index = i;
    if(state_fp == state)
        return 0;
    return -1;
}

int seek_value_in_file(string str, string value, int *index)
{
    string value_fp;
    int i = *index;
    int sim = 0;
    i = skip_space(str, i);
    while(check_number(str[i]) == 0)
    {
        i++;
        sim++;
    }
    value_fp.insert(0, str, i - sim, sim);
    *index = i;
    if(value_fp == value)
        return 0;
    return -1;
}

int skip_for_new_unit(string str)
{
    int i = 0;
    while(str[i] != '>')
        i++;
    i++;
    return i;
}

string get_state_in_file(string str, int *index)
{
    int i = *index;
    int sim = 0;
    string state;
    i = skip_space(str, i);
    while(str[i] != ' ')
    {
        i++;
        sim++;
    }
    state.insert(0, str, i - sim, sim);
    *index = i;
    return state;
}

string get_value_in_file(string str, int *index)
{
    int i = *index;
    int sim = 0;
    string value;
    i = skip_space(str, i);
    while(check_number(str[i]) == 0)
    {
        i++;
        sim++;
    }
    value.insert(0, str, i - sim, sim);
    *index = i;
    return value;
}

int seek_unit_in_file(ifstream *fp, string *state, string *value)
{
    string str;
    int check = 0, i = 0;
    (*fp).seekg(0, ios::beg);
    while(getline((*fp), str))
    {
        i = 0;
        if(seek_state_in_file(str, *state, &i) == 0)
        {
            if(seek_value_in_file(str, *value, &i) == 0)
            {
                check = 1;
                break;
            }
        }
    }
    if(check == 0)
        return -1;

    i = skip_for_new_unit(str);
    *state = get_state_in_file(str, &i);
    *value = get_value_in_file(str, &i);

    return 0;
}