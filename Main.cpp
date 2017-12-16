/*
	Name: Mini Project 2 : Floorplanning using sequence pairs 
	Copyright: 
	Author: Nikita Korgaonkar
	Date: 03/12/17 15:25
	Description: This project aims at creating sequence pairs which are then used for floorplanning
*/


#include <iostream>
#include<cstdlib>
#include<stack>
#include<deque>
#include<math.h>
#include"generate_seqpair.h"
#include"parser.h"
#include "evaluate_seqpair_algo.h"
#include "simulated_annealing.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int n ;
	srand(time(NULL));
	n = parser();
	simulated_annealing(n);
	return 0;
}
