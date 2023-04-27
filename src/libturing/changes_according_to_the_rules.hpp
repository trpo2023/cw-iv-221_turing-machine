#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int check_file(ifstream *fp);

int seek_unit_in_file(ifstream *fp, string *condition, string *value);

int skip_space(string str, int i);

int check_number(char c);