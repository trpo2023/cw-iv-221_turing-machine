#include "changes_according_to_the_rules.hpp"

using namespace std;

int rule_changes(ifstream *fp, string *state, string *value)
{
    int rez;
    
    rez = seek_unit_in_file(fp, state, value);
    
    if(rez != 0)
    {
        cout << "Rule not found!" << endl;
        return -1;
    }
    return 0;
}

// int main(int argc, char *argv[])
// {
//     string state, value;
//     state = "v";
//     value = "4";
//     if(rule_changes(argv[1], &state, &value) == -1)
//     {
//         cout << "no" << endl;
//         return -1;
//     }
//     else
//         cout << "yes" << endl;
//     cout << "New condition: " << state << endl;
//     cout << "New value: " << value << endl;
//     return 0;
// }