#include <iostream>
#include "header.h"

using namespace std;

void display_vector_variant(vector<pType_v> result)
{
    for (int j = 0; j < result.size(); j++) {
        if (result[j].index() == 0)
            std::cout << "string \"" << std::get<0>(result[j]) << "\" ";
        if (result[j].index() == 1)
           std::cout << "char " << std::get<1>(result[j]) << " ";
        if (result[j].index() == 2)
           std::cout << "int " << std::get<2>(result[j]) << " ";
        if (result[j].index() == 3)
           std::cout << "unsigned " << std::get<3>(result[j]) << " ";
        if (result[j].index() == 4)
           std::cout << "float " << std::get<4>(result[j]) << " ";
        if (result[j].index() == 5)
           std::cout << "long " << std::get<5>(result[j]) << " ";
   }
   std::cout << std::endl;
}