#include <fstream>
#include <iostream>

#include <libturing/changes_according_to_the_rules.hpp>
#include <libturing/procces_input_data.hpp>

enum input_state { input_from_file, input_from_console };

using namespace std;

int main(int argc, char** argv)
{
    enum input_state state;
    if (argc < RULES_FILE_ARGUMENT) {
        cout << ERROR_FILE_NO_SPECIFIED << endl;
        return -1;
    } else if (argc == RULES_FILE_ARGUMENT) {
        state = input_from_console;
    } else if (argc == INPUT_FILE_ARGUMENT) {
        state = input_from_file;
    } else {
        cout << ERROR_TOO_MANY_ARGUMENTS << endl;
        return -1;
    }

    ifstream rules_file;
    rules_file.open(argv[RULES_FILE_ARGUMENT - 1]);
    if (!rules_file.is_open()) {
        cout << ERROR_FILE_NOT_FOUND << endl;
        return -1;
    }

    if (check_file(&rules_file)) {
        return -1;
    }

    if (state == input_from_file) {
        fstream input_file;
        input_file.open(
                argv[INPUT_FILE_ARGUMENT - 1], ios_base::in | ios_base::out);
        if (!input_file.is_open()) {
            cout << ERROR_FILE_NOT_FOUND << endl;
            input_file.close();
            return -1;
        }
        process_input_file(&rules_file, &input_file);
        input_file.close();
    } else {
        process_input_console(&rules_file);
    }

    rules_file.close();
    return 0;
}
