#ifndef C_INTERFACE_H_
#define C_INTERFACE_H_

#ifndef __cplusplus
extern "C"
#endif //__cplusplus

extern "C" {
    enum pCType_e
    {
        pt_str,
        pt_char,
        pt_int,
        pt_uint,
        pt_fl,
        pt_lg
    };

    struct pCType_s
    {
        pCType_e type;
        void *data;
    };
    char **pSplit_char(const char *str, const char *symb, int save_split);
    char **pSplit_word(const char *str, const char **words, int save_split);
    pCType_s **pFind_pattern(const char *str, const char *symb, int save_split);
}

#endif