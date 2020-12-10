//
// Created by pcxie on 2020/12/3.
//

#ifndef MST_HELPLERFUNCTIONS_H
#define MST_HELPLERFUNCTIONS_H

#include "cmath"
const double EPSILON = 1e-5;

inline bool isEqual(double lhs, double rhs){
    return std::fabs(lhs-rhs) <= EPSILON;
}

inline bool isLarger(double lhs, double rhs){
    return lhs>rhs && std::fabs(lhs-rhs) > EPSILON;
}

unsigned int factorial(unsigned int n){
    if (n==1){
        return 1;
    }
    return n*factorial(n-1);
}


#endif //MST_HELPLERFUNCTIONS_H
