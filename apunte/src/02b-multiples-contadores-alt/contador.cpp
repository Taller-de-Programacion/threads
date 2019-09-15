#include <cstdio>
#include <vector>
#include <string>
#include "CounterThread.h"


/**
 * Demo2b: Se instancian N counters, pero estos son live objects
 */

int main (int argc, char** argv) {
	// Los counters van a vivir en el heap por si los contadores son realocados
	std::vector<CharCounter*> counters;
	
	/**
	 * Creo N contadores para cada archivo
	 */
	counters.reserve(argc);
	for (int i = 0; i < argc-1; ++i){
		counters.push_back(new CharCounter(argv[i+1], 'a'));
	}
	
	/**
	 * Los lanzo a todos juntos
	 */
	for (unsigned int i = 0; i < (counters.size()); ++i){
		counters[i]->start();
	}
	printf("Llamando a join\n");
	for (unsigned int i = 0; i < (counters.size()); ++i){
		counters[i]->join();
	}
	int finalResult = 0;
	for (unsigned int i = 0; i < (counters.size()); ++i){
		counters[i]->printResult();
		finalResult += counters[i]->getResult();
	}
	printf("El resultado final es %d. \n", finalResult);
}
