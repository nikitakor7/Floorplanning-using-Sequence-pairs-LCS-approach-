#ifndef parser_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define parser_H

#include <iostream>
#include<string>
#include <fstream> //Objects belong to this class are associated with files opened for input and output purposes
#include <sstream> //Header providing string stream classes
#include <algorithm>
#include <ctime>
#include <cstdlib> // Header providing standard lib
#include <cmath> // Header providing math functions
#include <vector>

using namespace std;
extern int columns, row;
  
extern vector<float> wt_val, ht_val;
extern pair < pair < pair <vector<float> , vector<float> >, pair <vector<float> , vector<float> > > , pair <vector<float> , vector<float> > > dim_soft;
extern bool hardorsoft;
float parser();

#endif

