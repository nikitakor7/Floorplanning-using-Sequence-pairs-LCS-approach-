#ifndef evaluate_seqpair_algo_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define evaluate_seqpair_algo_H
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include "generate_seqpair.h"

using namespace std;

extern int count1;
pair < pair < vector < float >,vector < float > >,float > area(vector < int >, vector < int >, pair < vector < float >, vector < float > >, int );
void coordinate_seqpair( pair < vector < float > ,vector < float > >, float );

#endif
