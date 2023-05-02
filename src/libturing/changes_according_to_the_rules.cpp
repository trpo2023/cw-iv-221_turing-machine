#include "changes_according_to_the_rules.hpp"

using namespace std;

// int rule_changes(ifstream *fp, string *state, string *value)
// {
//     int rez;
    
//     rez = seek_unit_in_file(fp, state, value);
    
//     if(rez == -2)
//     {
//         cout << "Rule not found!" << endl;
//         return -2;
//     }
//     return rez;
// }

// int main(int argc, char *argv[])
// {
//     extern int check_file(ifstream *fp);
//     ifstream fp;
//     string state, value;
//     fp.open(argv[1]);
//     if(check_file(&fp) != 0)
//     {
//         fp.close();
//         return -1;
//     }
//     state = "v";
//     value = "5";
//     if(seek_unit_in_file(&fp, &state, &value) == -2)
//     {
//         cout << "no" << endl;
//         return -1;
//     }
//     else
//         cout << "yes" << endl;
//     cout << "New condition: " << state << endl;
//     cout << "New value: " << value << endl;
//     fp.close();
//     return 0;
// }