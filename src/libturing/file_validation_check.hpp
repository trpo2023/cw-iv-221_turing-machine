
#define ERROR_IN_RULES "Error in the shift rules file at string "

#define ERROR_INCOMPLETE_DATA "incomplete data"
#define ERROR_INVALID_VALUE "invalid value."
#define ERROR_EXCPECTED_DELIM "expected \"->\""
#define ERROR_EXCPECTED_SHIFT_MODE "expected shift mode (R, L or N)"
#define ERROR_UNEXCPECTED_TOKEN "unexpected token"

int check_arrow(std::string str, int* index);
int check_shift(std::string str, int* index);
int check_value(std::string str, int* index);