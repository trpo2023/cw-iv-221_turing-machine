#include "changes_according_to_the_rules.hpp"

using namespace std;

int rule_changes(string file_name, string *condition, string *value)
{
    ifstream fp;
    int rez;
    fp.open(file_name);
    if(!fp)
    {
        cout << "File error - can't open to read data!" << endl;
        fp.close();
        return -1;
    }
    
    rez = check_file(&fp);
    fp.close();
    fp.open(file_name);
    if(rez == 0)
        rez = seek_unit_in_file(&fp, condition, value);
    else
        return -1;
    
    if(rez != 0)
    {
        cout << "Rule not found!" << endl;
        return -1;
    }
    return 0;
}

// int main(int argc, char *argv[])
// {
//     string condition, value;
//     condition = "v";
//     value = "4";
//     if(rule_changes(argv[1], &condition, &value) == -1)
//     {
//         cout << "no" << endl;
//         return -1;
//     }
//     else
//         cout << "yes" << endl;
//     cout << "New condition: " << condition << endl;
//     cout << "New value: " << value << endl;
//     return 0;
// }