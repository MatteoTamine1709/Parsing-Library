#include "header.h"
#include <iostream>

using namespace std;

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

int compare_ret_correct_variant(vector<vector<pType_v>> ret, vector<vector<pType_v>> correct)
{
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            if ((ret[i][j].index() == 0 && correct[i][j].index() == 0 &&
                (get<0>(ret[i][j])).compare(get<0>(correct[i][j])) != 0) ||
                (ret[i][j].index() != correct[i][j].index()))
                    return (i);
            if ((ret[i][j].index() == 1 && correct[i][j].index() == 1 &&
                (get<1>(ret[i][j])) != (get<1>(correct[i][j]))) ||
                (ret[i][j].index() != correct[i][j].index()))
                    return (i);
            if ((ret[i][j].index() == 2 && correct[i][j].index() == 2 &&
                (get<2>(ret[i][j])) != (get<2>(correct[i][j]))) ||
                (ret[i][j].index() != correct[i][j].index()))
                    return (i);
            if ((ret[i][j].index() == 3 && correct[i][j].index() == 3 &&
                (get<3>(ret[i][j])) != (get<3>(correct[i][j]))) ||
                (ret[i][j].index() != correct[i][j].index()))
                    return (i);
            if ((ret[i][j].index() == 4 && correct[i][j].index() == 4 &&
                (get<4>(ret[i][j])) != (get<4>(correct[i][j]))) ||
                (ret[i][j].index() != correct[i][j].index()))
                    return (i);
            if ((ret[i][j].index() == 5 && correct[i][j].index() == 5 &&
                (get<5>(ret[i][j])) != (get<5>(correct[i][j]))) ||
                (ret[i][j].index() != correct[i][j].index()))
                    return (i);
        }
    }
    return (-1);
}