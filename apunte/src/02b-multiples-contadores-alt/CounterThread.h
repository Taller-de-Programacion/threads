#ifndef COUNTER_THREAD_H
#define COUNTER_THREAD_H

#include "Thread.h"

class CharCounter : public Thread {
public:
	CharCounter(const char* filename, char countChar);
	void run();
	void printResult() const;
	int getResult() const;
private:
	std::string filename;
	char countChar;
	int result;
};

#endif
