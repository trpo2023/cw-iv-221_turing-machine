#include <cstring>
#include <fstream>
#include <iostream>

#include <libturing/changes_according_to_the_rules.hpp>
#include <libturing/procces_input_data.hpp>

enum input_state { input_from_console, input_from_file };

using namespace std;

int main(int argc, char** argv)
{
    enum input_state state = input_from_console;
    int rules = 0, data = 0, out = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 == argc) {
                cout << ERROR_OUTPUTFILE_NOT_SPECIFIED << endl;
                return -1;
            }
            out = ++i;
        } else {
            if (rules && !data) {
                data = i;
                state = input_from_file;
            } else if (!rules) {
                rules = i;
            }
        }
    }

    if (!rules) {
        cout << ERROR_FILE_NO_SPECIFIED << endl;
        return -1;
    }

    ifstream rules_file;
    rules_file.open(argv[rules]);
    if (!rules_file.is_open()) {
        cout << rules << endl;
        cout << ERROR_FILE_NOT_FOUND << endl;
        return -1;
    }
    if (check_file(&rules_file)) {
        return -1;
    }

    string res;
    if (state == input_from_file) {
        ifstream input_file;
        input_file.open(argv[data], ios_base::in);
        if (!input_file.is_open()) {
            cout << ERROR_FILE_NOT_FOUND << endl;
            input_file.close();
            return -1;
        }
        process_input_file(&rules_file, &input_file, &res);
        input_file.close();
    } else {
        process_input_console(&rules_file, &res);
    }

    if (out) {
        ofstream output_file;
        output_file.open(argv[out]);
        output_file << res << endl;
        output_file.close();
    } else {
        cout << res << endl;
    }

    rules_file.close();
    return 0;
}
