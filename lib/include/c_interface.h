#ifndef C_INTERFACE_H_
#define C_INTERFACE_H_

#ifndef __cplusplus
extern "C"
#endif //__cplusplus

enum pType_e
{
    pt_str,
    pt_int,
    pt_dbl
};

struct pType_s
{
    pType_e type;
    void *data;
};

extern "C" {
    char **pSplit_char(const char *str, const char *symb, int save_split);
    char **pSplit_word(const char *str, const char **words, int save_split);
    void test_variant();
}

#endif