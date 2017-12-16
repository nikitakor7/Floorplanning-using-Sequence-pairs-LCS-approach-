/*
	Name: Simulated Annealing
	Copyright: 
	Author: Nikita Korgaonkar
	Date: 04/12/17 01:37
	Description: This file performs simulated annealing 
*/


#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstdlib>
#include<time.h>
#include<fstream>
#include"move_seqpair.h"
#include"generate_seqpair.h"
#include"evaluate_seqpair_algo.h"

using namespace std;

bool acceptMove(float del_cost, float T)
{
	bool k;
	int accepted_move = 0;
	double boltz, random_number;
	ofstream  textfile;
	textfile.open("movesntemp.csv", ios::app);
	const double boltzmann_constant = 1.3806503e-23;
	if(del_cost < 0)
	{
		k = 1;
		accepted_move++;
	}	
	
	else
	{
		boltz = exp(-1* del_cost/(boltzmann_constant*T));
		random_number = ((rand())%1000)/1000.0;
		if(random_number<boltz)
		{
			k=1;
			accepted_move++;
		}	
		else
		{
			k =0;
		}	
				
	}
	textfile<<accepted_move<<","<<T<<"\n";
	textfile.close();
return k;	
}
/*****************************************************************************************************************************/


int coolDown(int T)
{
	T = 0.95*T;
}

/****************************************************************************************************************************/
pair<vector<int>,vector<int> > simulated_annealing(int n)
{
	pair<vector<int>,vector<int> >random_initial_solution, curSolution, nextSol;
	pair<pair<vector<int>, vector<int> >, pair<vector<float>, vector<float> > > res;
	random_initial_solution = gen_p_n_seq(n);
	curSolution = random_initial_solution ;
	clock_t timeStart,timeEnd;
	int count;
	/*******generating files for printing necessary data**********/
	ofstream textfile1, textfile2;
	
//	textfile2.open("tempniteration.txt", ios::app);
	
	
	/***start the clock****/
	timeStart = clock();
	bool decide;
	float T =400;
	float Tfreez = 1;
	int NUM_MOVES_PER_TEMP_STEP = 35;//log(T) ;
	float delta_cost = 0;
		while(T>Tfreez)
	{
		for(int i =0; i<NUM_MOVES_PER_TEMP_STEP; i++)
	{
			res = move_seqpair(curSolution,n);
			nextSol = res.first;
			
			pair<pair < vector < float >,vector< float > >,float> area1 = area(nextSol.first,nextSol.second, res.second, n);
			pair< pair< vector< float>,vector < float> >,float> area2 = area(curSolution.first, curSolution.second, res.second,n);
			
			float area_new = area1.second;
			float area_old = area2.second;
			delta_cost = area_new - area_old;
			decide = acceptMove(delta_cost,T );
			if(decide == true)
			{
				curSolution = nextSol;
			}
			
			
		
		}
			T = 0.75*T;
		textfile1.open("costntemp.txt", ios::app);
			count++;
			textfile1<<T<<","<<count<<"\n";
			textfile1.close();
	}
	timeEnd = clock();
	
	cout << "Run Time : " << (float)((timeEnd-timeStart))/(CLOCKS_PER_SEC) << endl;
	pair < pair < vector<float >, vector<float> >,float> final_value = area(curSolution.first, curSolution.second, res.second,n);
	//float final_area = area(curSolution.first, curSolution.second, res.second,n);
	cout << "final area is :" << final_value.second<<endl;
	coordinate_seqpair(final_value.first, final_value.second);
//	black_area(final_value);
	
return((curSolution))	;		
	
			
}
	

