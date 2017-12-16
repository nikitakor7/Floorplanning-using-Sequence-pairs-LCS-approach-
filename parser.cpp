/*
	Name: Parser
	Copyright: 
	Author: Nikita Korgaonkar
	Date: 03/12/17 15:22
	Description: Parses the data available from files
*/

#include <iostream>
#include<string>
#include <fstream> //Objects belong to this class are associated with files opened for input and output purposes
#include <sstream> //Header providing string stream classes
#include <algorithm>
#include<utility>
#include<map>
#include <ctime>
#include <cstdlib> // Header providing standard lib
#include <cmath> // Header providing math functions
#include <vector>

//int columns, row;
using namespace std;
  
vector<float> wt_val, ht_val,area_1, min_ratio, max_ratio,ideal_val;
pair < pair < pair <vector<float> , vector<float> >, pair <vector<float> , vector<float> > > , pair <vector<float> , vector<float> > > dim_soft;
bool hardorsoft;

pair < pair < pair <vector<float> , vector<float> >, pair <vector<float> , vector<float> > > , pair <vector<float> , vector<float> > >  soft_block_parameter_calc(int n )
{
	pair <vector<float>, vector<float> >min, max, ideal;
	ideal.first = ideal_val;
	ideal.second = ideal_val; 
	
 	for( int i = 0; i<n ; i++ )
	{
	
		cout << ideal_val[i] << endl;
	
		min.first.push_back(ideal_val[i] / min_ratio[i]);
		min.second.push_back(ideal_val[i] * min_ratio[i]);
		max.first.push_back(ideal_val[i]/ max_ratio[i]);
		max.second.push_back(ideal_val[i] * max_ratio[i]);
	
	}
	
	dim_soft = make_pair(make_pair(min, max), ideal);
	
	/*for( int i = 0; i< n; i++)
	{
		
		cout<< dim_soft.first.first.first[i] << " " << dim_soft.second.first[i]<< " " << dim_soft.first.second.first[i] << " " << dim_soft.first.first.second[i] << " " << dim_soft.second.first[i]<< " " << dim_soft.first.second.first[i] << "\n" ;
	}*/
	return dim_soft;	
}

float parser()
{
	
	int val = 0;
	cout << "which file would you like to chose?"<< "\n"<<"1. hard 10 \n2. soft 10 \n3.hard 30 \n4.soft 30 \n5.hard 50 \n6.soft 50\n7.hard 100\n8.soft 100\n9.hard 200\n10.soft 200\n11.hard 300\n12.soft 300\n";
	cin >> val;
	ifstream file;
	int columns , row;
	
	

	switch(val)
	{
		case 1 : 
		cout <<" You have selected file 1"<<endl; 
		columns = 10;
		row = 10;
		file.open("try.txt"); // reading the dummy file created
		break;
		
		case 2 :
		cout <<" You have selected file 2"<<endl; 
		columns = 4;
		row = 10;
		file.open("soft10.txt"); // reading the dummy file created
		break;
		
		case 3 :
		cout <<" You have selected file 3"<<endl; 
		columns = 10;
		row = 30;
		file.open("hard30.txt"); // reading the dummy file created
		break;	
		
		case 4 :
		cout <<" You have selected file 4"<<endl; 
		columns = 4;
		row = 30;
		file.open("soft30.txt"); // reading the dummy file created
		break;
		
		case 5 :
		cout <<" You have selected file 5"<<endl; 
		columns = 10;
		row = 50;
		file.open("hard50.txt"); // reading the dummy file created
		break;	
		
		case 6 :
		cout <<" You have selected file 6"<<endl; 
		columns = 4;
		row = 50;
		file.open("soft50.txt"); // reading the dummy file created
		break;	
			
		case 7 :
		cout <<" You have selected file 7"<<endl; 
		columns = 10;
		row = 100;
		file.open("hard100.txt"); // reading the dummy file created
		break;	
		
		case 8 :
		cout <<" You have selected file 8"<<endl; 
		columns = 4;
		row = 100;
		file.open("soft100.txt"); // reading the dummy file created
		break;	
		
		
		case 9 :
		cout <<" You have selected file 9"<<endl; 
		columns = 10;
		row = 200;
		file.open("hard200.txt"); // reading the dummy file created
		break;	
		
		case 10 :
		cout <<" You have selected file 9"<<endl; 
		columns = 4;
		row = 200;
		file.open("hard200.txt"); // reading the dummy file created
		break;
		
		case 11 :
		cout <<" You have selected file 9"<<endl; 
		columns = 10;
		row = 300;
		file.open("hard300.txt"); // reading the dummy file created
		break;	
		
		case 12 :
		cout <<" You have selected file 9"<<endl; 
		columns = 4;
		row = 300;
		file.open("soft300.txt"); // reading the dummy file created
		break;		
		
			
	}
	string line;
	//Find the number of lines and allocate the rowSize
	float b[row][columns]; //size allocated assuming the number of lines and columns are known, otherwise you can allocate using 'new' operator 
	string s2 = "hardrectilinear";
	int k = 0; //This also gives the number of lines after loop is done
	

	while (std::getline(file, line))
	{
		//istringstream iss(line);
		//check if the file if hardrectilinear or softrectilinear
		if (line.find(s2) != std::string::npos) 
			hardorsoft = 1;
		
		else 
			hardorsoft = 0;
		
		for (int i = 0; i < (int)line.size(); ++i)
		{
			if (((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))) //extracting numerics and removing alphanumeric values in the text file
			{
				line[i] = ' \0 ';
			}
			// removing  all extras
			line.erase(std::remove(line.begin(), line.end(), ','), line.end());
			line.erase(std::remove(line.begin(), line.end(), '('), line.end());
			line.erase(std::remove(line.begin(), line.end(), ')'), line.end());
			
		}
		istringstream iss(line);
			for (int j = 0; j < columns; j++)
			{
				iss >> b[k][j];
				cout << b[k][j] <<" ";
			}

			cout << endl;
			k++;
	}
//cout <<"\n hardorsoft"<<hardorsoft<<endl;

		if(hardorsoft ==1)
		{
			for(int i = 0; i< row; i++)
			{
				wt_val.push_back(b[i][6]);
				ht_val.push_back(b[i][7]);
			}
			
			

		}
		else
		{
			for(int i = 0; i< row; i++)
			{

				min_ratio.push_back(b[i][2]);
				max_ratio.push_back(b[i][3]);
				ideal_val.push_back(sqrt(b[i][1]));
			}
			soft_block_parameter_calc(row);
		}

	return row;
}
