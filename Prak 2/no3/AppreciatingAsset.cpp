#include "AppreciatingAsset.hpp"

double AppreciatingAsset::getValue(int years){
    double res = x->getValue(years);
    for (int i = 0; i < years; i++){
        res *= (1 + (this->rate));
    }
    return res;
}