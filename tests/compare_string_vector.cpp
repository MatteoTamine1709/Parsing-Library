#include "header.h"

int compare_ret_correct(vector<string> ret, vector<string> correct)
{
    int error = -1;
    for (int i = 0; i < ret.size(); i++)
        if (ret[i].compare(correct[i]) != 0) {
            error = i;
            break;
        }
    return (error);
}