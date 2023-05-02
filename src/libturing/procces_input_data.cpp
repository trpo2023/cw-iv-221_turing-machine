#include <fstream>

#include "procces_input_data.hpp"
#include "changes_according_to_the_rules.hpp"

int process_input_file(ifstream *rule, fstream *input)
{
    string state = BEG_STATE;
    string str, value;
    int i = 0, next = 0;

    getline(*input, str);
    while (1) {
        value = str[i];
        if ((next = seek_unit_in_file(rule, &state, &value)) == -2) {
            cout << value << endl;
            cout << state << endl;
            return -1;
        }
        
        str[i] = value[0];
        i += next;
        if (i < 0) {
            i = 0;
            str.insert(str.begin(), ' ');
        } else if (i >= (int) str.size()) {
            str.push_back(' ');
        }

        if (state == END_STATE) {
            break;
        }
    }

    input->clear();
    input->seekg(0);
    *input << str;
    return 0;
}

int process_input_console(ifstream *rule, string res)
{
    string state = BEG_STATE;

    string str, value;
    int i = 0, next = 0;

    cout << "Enter the line: ";
    getline(cin, str);
    while (1) {
        value = str[i];
        if ((next = seek_unit_in_file(rule, &state, &value)) == -2) {
            cout << value << endl;
            cout << state << endl;
            return -1;
        }

        str[i] = value[0];
        i += next;
        if (i < 0) {
            i = 0;
            str.insert(str.begin(), ' ');
        } else if (i >= (int) str.size()) {
            str.push_back(' ');
        }

        if (state == END_STATE) {
            break;
        }
    }
    res = str;
    return 0;
}
