/*
	Name: Generate moves for simulated annealing
	Copyright: 
	Author: Nikita Korgaonkar
	Date: 04/12/17 00:09
	Description: Randomly generate moves to run simulated annealing
*/


#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<utility>
#include"parser.h"
#include"generate_seqpair.h"
#include"evaluate_seqpair_algo.h"


pair < pair < vector < int >, vector < int > >, pair < vector < float >, vector < float> > > move_seqpair(pair < vector < int > ,vector < int > >seq, int n)
{
	int select_move = rand()%3+1;
	pair< pair < vector < int >, vector< int > >, pair<vector< float >, vector< float > > > result;
	int positn1 = rand()%n;  // get two different positions of nodes
	int positn2 = rand()%n;
   int i;
	while(i <30)
	{
		if (positn1 == positn2)
			positn2 = rand()%(n);
		else
			break;
		
		i++;
	}		
	pair < vector < float >,vector< float > > dimension;
	if (hardorsoft == 1)
		dimension = make_pair(wt_val,ht_val);
	
	else
		dimension = dim_soft.first.first;
	
	vector< int >P,N;
	
	switch(select_move)
	{
		case 1:
			{
				//interchange aspect ratio parameters
				int value = rand()%n;
				if(hardorsoft == 1)
					swap(dimension.first[value], dimension.second[value]);			
				
				else
				{
					int consider_seq = rand()%3 +1;
					//cout << consider_seq;
					switch(consider_seq)
					{
						case 1 : 
						{
							
							dimension = dim_soft.first.first;
							break;
						}
						case 2 :
						{
							dimension = dim_soft.first.second;
							break;
						}
						case 3 :
						{
							dimension = dim_soft.second;
							break;
						}
					}
				swap(dimension.first[value], dimension.second[value]);		
				}		
				break;
			}
		
		case 2:
			{
				//interchange modules in both sequences
				swap(seq.first[positn1],seq.first[positn2]);
				swap(seq.second[positn1], seq.second[positn2]);	
			
			break;
			}	
			
		case 3 :
			{
				//interchange modules in one of the sequence
				int select = rand()%2+1; // randomly select a string to interchange
				
				if(select == 1)
					swap( seq.first[positn1], seq.first[positn2]);
				
				else
					swap( seq.second[positn1], seq.second[positn2]);
		
				break;	
			}		
	}
	result.first = seq;
	result.second = dimension;
	return result;
}
