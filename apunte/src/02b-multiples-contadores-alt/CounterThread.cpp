#include "CounterThread.h"
/**
 * Función a correr en paralelo
 * Sobrecargo el operador "()", convirtiendo a mi objeto en un *functor*
 */
void CharCounter::run() {
	printf("Busco '%c' sobre %s\n", this->countChar, this->filename.c_str());
	FILE* fd = fopen(this->filename.c_str(), "r");
	char readChar;
	while (fread(&readChar, 1, 1, fd)){
		if (readChar == this->countChar) {
			this->result++;
		}
	}
	fclose(fd);
}

CharCounter::CharCounter(const char* filename, char countChar) :
	filename(filename), countChar(countChar), result(0){}

void CharCounter::printResult() const {
	printf("%s tiene %d letras '%c'\n", this->filename.c_str(), this->result, this->countChar);
}

int CharCounter::getResult() const {
	return this->result;
}
