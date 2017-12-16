#ifndef simulate_annealing_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define simulate_annealing_H

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include"move_seqpair.h"
#include"generate_seqpair.h"

using namespace std;
pair<vector<int>,vector<int> > simulated_annealing(int);

#endif
