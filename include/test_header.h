#ifndef TEST_HEADER
#define TEST_HEADER

int compare_ret_correct(std::vector<std::string> ret, std::vector<std::string> correct);
int compare_ret_correct_variant(std::vector<std::vector<pType_v>> ret, std::vector<std::vector<pType_v>> correct);
void display_vector_variant(std::vector<pType_v> result);
char *string_to_char(std::string str, char output[]);

#endif