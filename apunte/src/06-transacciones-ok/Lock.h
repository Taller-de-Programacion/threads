#ifndef LOCK_H
#define LOCK_H
#include <mutex>

/**
 * La clase Lock hace uso de RAII, tomando posesión de un mutex en el constructor
 * haciendo `lock()` en el mismo, y luego haciendo `unlock()` en el destructor.
 * De esta manera, si ocurre un error, el mutex siempre es destrabado al salir del
 * scope
 */
class Lock {
public:
	explicit Lock(std::mutex& m);
	~Lock();
private:
	std::mutex& m;
};

#endif // LOCK_H
