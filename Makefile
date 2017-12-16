all:
	g++ Main.cpp generate_seqpair.cpp parser.cpp evaluate_seqpair_algo.cpp move_seqpair.cpp simulated_annealing.cpp -std=c++11 -o parser

clean:
	rm *.o parser


