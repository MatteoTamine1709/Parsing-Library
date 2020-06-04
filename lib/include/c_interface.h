#ifndef C_INTERFACE_H_
#define C_INTERFACE_H_

#ifndef __cplusplus
extern "C"
#endif //__cplusplus

extern "C" {
    char **pSplit_char(const char *str, const char *symb, int save_split);
    char **pSplit_word(const char *str, const char **words, int save_split);
}

#endif