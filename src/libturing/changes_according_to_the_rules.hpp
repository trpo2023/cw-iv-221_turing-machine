#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int seek_unit_in_file(ifstream* fp, string* state, string* value);

int skip_space(string str, int i);

int check_number(char c);

int check_file(ifstream* fp);