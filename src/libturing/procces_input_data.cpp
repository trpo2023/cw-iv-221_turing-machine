#include <fstream>

#include "changes_according_to_the_rules.hpp"
#include "procces_input_data.hpp"

int process_string(ifstream* rule, string* data, string* res)
{
    string state = BEG_STATE;
    string str = *data, value;
    int i = 0, next = 0;
    
    while (1) {
        value = str[i];
        if ((next = seek_unit_in_file(rule, &state, &value)) == -2) {
            break;
        }

        str.erase(i, 1);
        str.insert(i, value);
        i += next;
        if (i < 0) {
            i = 0;
            str.insert(str.begin(), ' ');
        } else if (i >= (int)str.size()) {
            str.push_back(' ');
        }

        if (state == END_STATE) {
            break;
        }
    }

    *res = str;
    return 0;
}

int process_input_file(ifstream* rule, ifstream* input, string* res)
{
    string str;

    getline(*input, str);
    return process_string(rule, &str, res);
}

int process_input_console(ifstream* rule, string* res)
{
    string str;
    cout << "Enter the line: ";
    getline(cin, str);
    
    return process_string(rule, &str, res);
}
