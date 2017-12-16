#ifndef LCS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define LCS_H
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

extern vector <float>coordinates;
extern float L;

float LCS_algo(vector<int> ,vector<int> ,vector<float>);
#endif
