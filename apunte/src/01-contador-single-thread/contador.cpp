#include <cstdio>
#include <vector>

int countChar(char* filename, char myChar);

/**
 * # Contador de letras
 * Cuenta las apariciones de la letra 'a' en una serie de
 * archivos pasados por parámetro
 */
int main (int argc, char** argv) {
	std::vector<int> counters(argc);
	for (int i = 1; i < argc; ++i){
		counters[i] = countChar(argv[i], 'a');
	}
	for (int i = 1; i < argc; ++i){
		printf("%s tiene %d letras 'a'\n", argv[i], counters[i]);
	}
}

/**
 * Abre el archivo ubicado en `filepath` y busca aparciciones
 * de la letra `myChar`
 * Devuelve la cantidad de apariciones
 */
int countChar(char* filepath, char myChar) {
	FILE* fd = fopen(filepath, "r");
	int counter = 0;
	char readChar;
	while (fread(&readChar, 1, 1, fd)) {
		if (readChar == myChar) {
			counter++;
		}
	}
	fclose(fd);
	return counter;
}
