#include <map>
#include <mutex>
#include <string>
#include "Account.h"

/**
 * # Monitor de cuentas
 * 
 * Un monitor provee una interfaz segura para poder operar con los datos de forma concurrente
 * Los métodos que acceden a información que puede ser modificada de forma concurrente utilizan un
 * mutex para que un solo hilo acceda a esa información
 *
 * Notar que todas las operaciones estan protegidas por el mismo mutex para evitar que distintas operaciones que operan
 * sobre los mismos datos puedan tener condición de carrera
 */
class AccountMonitor {
public:
    AccountMonitor();
    void addAccount(const std::string& name);
    void transfer(const std::string& from, const std::string& to);
    void printResult();
    // WARNING!!!
    // Si bien esta función es "const" y solo realiza operaciones de lectura, no es thread-safe
    // Al no estar protegida por un mutex sólo puede usarse en contextos sin concurrencia.
    // Esto se debe a que otro hilo puede estar realizando modificaciones sobre el modelo (como transfer o addAccount)
    // Lo que puede provocar errores de procesamiento en esta función, INCLUSO siendo de sólo lectura.
    void printResultUnsafe() const;
private:
    std::mutex m;
    std::map<std::string, Account> accounts;
};
