#define BEG_STATE "q_b"
#define END_STATE "q_e"

#define ERROR_FILE_NO_SPECIFIED "No file specified"
#define ERROR_FILE_NOT_FOUND "File not found"
#define ERROR_OUTPUTFILE_NOT_SPECIFIED "Excpectd file name after '-o'"

int process_input_console(std::ifstream* rule, std::string* res);
int process_input_file(
        std::ifstream* rule, std::ifstream* input, std::string* res);