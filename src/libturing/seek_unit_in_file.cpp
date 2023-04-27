#include "changes_according_to_the_rules.hpp"

using namespace std;

int seek_condition_in_file(string str, string condition, int *index)
{
    int i = *index;
    int sim = 0;
    i = skip_space(str, i);
    string condition_fp;
    while(str[i] != ' ')
    {
        i++;
        sim++;
    }
    condition_fp.insert(0, str, i - sim, sim);
    *index = i;
    if(condition_fp == condition)
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

string get_condition_in_file(string str, int *index)
{
    int i = *index;
    int sim = 0;
    string condition;
    i = skip_space(str, i);
    while(str[i] != ' ')
    {
        i++;
        sim++;
    }
    condition.insert(0, str, i - sim, sim);
    *index = i;
    return condition;
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

int seek_unit_in_file(ifstream *fp, string *condition, string *value)
{
    string str;
    int check = 0, i = 0;
    while(getline((*fp), str))
    {
        i = 0;
        if(seek_condition_in_file(str, *condition, &i) == 0)
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
    *condition = get_condition_in_file(str, &i);
    *value = get_value_in_file(str, &i);

    return 0;
}