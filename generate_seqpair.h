#ifndef generate_seqpair_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define generate_seqpair_H
#include<iostream>
#include<string>
#include<vector>
#include<time.h>

using namespace std;

pair<vector<int>,vector<int> > gen_p_n_seq(int );
extern vector<int> p_vct, n_vct;
#endif
