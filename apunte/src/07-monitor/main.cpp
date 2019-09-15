#include <thread>
#include "Account.h"
#include "AccountMonitor.h"

class Deadlocker {
public:
    Deadlocker(AccountMonitor& monitor, const std::string& from, const std::string& to);
    void operator()();
    void printResult() const;
private:
    AccountMonitor& monitor;
    std::string from;
    std::string to;
};

int main (int argc, char** argv) {
    AccountMonitor monitor;
    const std::string from("Acc1");
    const std::string to("Acc2");
    monitor.addAccount(from);
    monitor.addAccount(to);
    Deadlocker locker1(monitor, from, to);
    Deadlocker locker2(monitor, to, from);
    printf("Corriendo en serie\n");
    locker1();
    locker1.printResult();
    locker2();
    locker2.printResult();
    // Ahora en paralelo
    printf("Corriendo en paralelo\n");
    std::thread t1(std::ref(locker1));
    std::thread t2(std::ref(locker2));
    t1.join();
    t2.join();
    locker1.printResult();
    locker2.printResult();
}



Deadlocker::Deadlocker(AccountMonitor& monitor, const std::string& from, const std::string& to) : 
    monitor(monitor), from(from), to(to) {}

void Deadlocker::printResult() const {
    monitor.printResult();
}

void Deadlocker::operator()() {
    for (int i = 0; i < 1000000; ++i) {
        monitor.transfer(this->from, this->to);
    }
}