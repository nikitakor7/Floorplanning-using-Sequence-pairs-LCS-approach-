/*
	Name: Sequence pair generator
	Copyright: 
	Author: Nikita Korgaonkar
	Date: 05/12/17 00:42
	Description: Generates a sequence a positive and negative sequence pair
*/


#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
#include <chrono>       // std::chrono::system_clock

using namespace std;

vector < int >  p_vct, n_vct;

pair < vector < int > ,vector < int > > gen_p_n_seq(int n)
{
	pair < vector < int >,vector < int > > seq_pairs;
	for(int i =0; i<n; i++)
	{
		p_vct.push_back(i);
		n_vct.push_back(i);
	}
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  	shuffle(p_vct.begin(), p_vct.end(), default_random_engine(seed));
  	//shuffle(n_vct.begin(), n_vct.end(), default_random_engine(seed));
  	//..8rotate(n_vct.begin(), n_vct.begin()+5 ,n_vct.end());
  	for(int i =0; i<p_vct.size(); i++)
  		cout<< p_vct[i] << "  ";
  	
  	cout << "\n";
  	
	 for(int i =0; i<n_vct.size(); i++)
  		cout<< n_vct[i] << "  "; 	
  	
  	seq_pairs = make_pair(p_vct, n_vct);
  	return seq_pairs;
  	
}
