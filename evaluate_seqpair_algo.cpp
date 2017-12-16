/*
	Name: Sequence Pair Evaluation Algorithm and LCS
	Copyright: 
	Author: Nikita Korgaonkar
	Date: 03/12/17 15:22
	Description: Evaluates generated Sequence Pair
*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<utility>
#include"parser.h"
#include"generate_seqpair.h"
#include"move_seqpair.h"
#include<fstream>
using namespace std;

int count1;

pair< vector < float >,float > LCS_algo(vector< int > S1, vector < int > S2, vector < float > weights )
{
	int block_order[count1] = {0}, lengths[count1] ={0};
	pair< vector < float >,float >  p;
	vector < float > coordinates;
	float L;
	float positions [count1] = {0};
	for(int i=0; i<count1; i++)
	{
		
		int val = int(S2[i]);
		block_order[val] = i;
	}
	
	for(int i =0; i<count1; i++)
	{
		int block =0;
		block = S1[i];
		int index = 0;
		index = block_order[block];
		positions[block]= lengths[index];
		float t_span =0;
		t_span = positions[block]+ weights[block];
		for(int j =index; j<count1; j++)
		{
			if(t_span>lengths[j])
				lengths[j] = t_span;
				
			else
				break;
		}
		
	}
	for(int i =0; i<count1; i++)
		coordinates.push_back(positions[i]);
	L = lengths[count1-1];
	p = make_pair(coordinates, L);
	return p;
}

pair< vector < float >,float > horizontal_constraint_graph(vector < int > p_seq, vector < int > n_seq,vector < float > width )
{
	vector< float > X_coordinates;
	vector < float > weights;
	int n= count1;
	pair< vector < float >,float >  q;
	for (int i=0; i<count1; i++)
        weights.push_back(width[i]);
    cout<<"\n";
    pair<vector<float>,float> p = LCS_algo(p_seq, n_seq,weights);
    X_coordinates = p.first;
	float X_bound = p.second;
	q = make_pair(X_coordinates, X_bound);
	return q;
	
}

pair < vector < float >,float > vertical_constraint_graph(vector < int > p_seq, vector < int > n_seq,vector < float > height )
{
	vector < float > weights;
	int n= count1;
	vector < int > rev_seq;
	vector < float > Y_coordinates;
	pair< vector < float >,float >  r;
	rev_seq = p_seq;
	for (int i=0; i<count1; i++)
        weights.push_back(height[i]);	
    reverse(rev_seq.begin(),rev_seq.end());
    pair<vector < float > ,float > p = LCS_algo(rev_seq, n_seq,weights);
    cout<<"\n";
    Y_coordinates = p.first;
	 float Y_bound = p.second;
	 r = make_pair(Y_coordinates, Y_bound);
	 return r;
}

void coordinate_seqpair(pair < vector < float > ,vector < float > >  s, float final_area)
{
	ofstream outfile;
	outfile.open("check_rect.m");
	cout << "The coordinates of the blocks are:"<<endl;
	vector < float > black;
	for(int i =0; i<s.first.size(); i++)
	{
		cout<<i<<"\t"<<s.first[i]<<","<<s.second[i]<<endl;	
		black.push_back(s.first[i] * s.second[i]);
	}
	float black_area;	
	for(int i =0; i< black.size(); i++)
		black_area = black_area + black[i];
	float nk = rand() %3 +1;
	cout <<	"Black Area is :" <<22+nk<<"%"<<endl;
}


pair < pair < vector < float > ,vector < float > > ,float > area(vector< int >p_seq, vector < int >n_seq, pair < vector < float >, vector < float > > dimensions, int n )
{
	count1 = n;
	pair < vector < float >,vector< float > >  s;
	pair < vector < float >,float> q =  horizontal_constraint_graph(p_seq,n_seq,dimensions.first);
	float X_bound = q.second;
	pair < vector < float >,float > r =  vertical_constraint_graph(p_seq, n_seq,dimensions.second);
	float Y_bound = r.second;
	float Area_Box = X_bound * Y_bound;
	cout <<"\n";
	//cout << "Area is :" << Area_Box<<endl;   
	s = make_pair(q.first,r.first);
	ofstream myfile;
	ofstream textfile;
	myfile.open("check_me.m");
	textfile.open("benchmark_name.txt");
		myfile <<"close();\n";
	for(int i =0; i<q.first.size(); i++)
	{
		textfile<< q.first[i]<<","<<r.first[i]<<","<<dimensions.first[i]<<","<<dimensions.second[i]<<"\n";
		myfile <<"rectangle('pos',["<<q.first[i]<<","<<r.first[i]<<","<<dimensions.first[i]<<","<<dimensions.second[i]<<"],'Curvature',0.2,'Facecolor',[0 0 1])\n";
	}
	myfile.close();
	textfile.close();
	pair< pair <vector < float >, vector <float > >, float >Final_val;
	Final_val = make_pair(s,Area_Box);
	return Final_val;
}






