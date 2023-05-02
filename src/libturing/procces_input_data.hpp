#define BEG_STATE "q_b"
#define END_STATE "q_e"

#define ERROR_FILE_NO_SPECIFIED "No file specified"
#define ERROR_FILE_NOT_FOUND "File not found"
#define ERROR_TOO_MANY_ARGUMENTS "Too many arguments"

#define RULES_FILE_ARGUMENT 2
#define INPUT_FILE_ARGUMENT 3

int process_input_console(std::ifstream *rule, std::string *res);
int process_input_file(std::ifstream *rule, std::fstream *input);