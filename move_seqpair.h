#ifndef move_seqpair_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define move_seqpair_H

#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<time.h>
#include<utility>
#include"parser.h"
#include"generate_seqpair.h"
#include"evaluate_seqpair_algo.h"


using namespace std;

pair<pair<vector<int>, vector<int> >, pair<vector<float>, vector<float> > > move_seqpair(pair<vector<int>,vector<int> >, int);
#endif
