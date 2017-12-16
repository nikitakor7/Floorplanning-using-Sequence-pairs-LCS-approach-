/*
	Name:  Longest Common Subsequence (LCS) Algorithm
	Copyright: 
	Author: Nikita Korgaonkar
	Date: 03/12/17 16:01
	Description: 
*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>
#include"evaluate_seqpair_algo.h"

using namespace std;

//vector<int>block_order;
vector <float>coordinates;
float L;

float LCS_algo(vector<int>S1, vector<int>S2, vector<float>weights)
{
	int block_order[count1] = {0}, lengths[count1] ={0};
	float positions [count1] = {0};
//	cout << "count1"<<count1<<endl;
	for(int i=0; i<count1; i++)
	{
		
		int val = int(S2[i]);
		//cout << "val" <<val;
		block_order[val] = i;
	}
//	cout<<"block order";
//	for(int i =0; i< count1; i++)
	//	cout<<block_order[i] << "\t";
	//	cout << endl;
	
	
	for(int i =0; i<count1; i++)
	{
		int block = S1[i];
	//	cout <<" block" <<endl;
		int index = block_order[block];
	//	cout <<" index" <<index <<"\t"<<endl;
		positions[block]= lengths[index];
	//	cout <<" position" <<positions[block] <<"\t"<<endl;
		float t_span = positions[block]+ weights[block];
	//	cout <<" t_span" <<t_span <<"\t"<<endl;
		for(int j =index; j<count1; j++)
		{
			if(t_span>lengths[j])
				lengths[j] = t_span;
				
			else
				break;
		}
		
	//	cout<<"lengths";
//	for(int i =0; i< count1; i++)
	//	cout<<lengths[i] << "\t";
	//	cout << endl;
	}
	for(int i =0; i<count1; i++)
		coordinates.push_back(positions[i]);
		
//	coordinates(coordinates);
	 L = lengths[count1-1];
	// cout<<endl<<"L "<<L<<endl;
	return L;
}

/*float coordinates_find(vector<float>coordinates)
{
	return coordinates;
}*/
