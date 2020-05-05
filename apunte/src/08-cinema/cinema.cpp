#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <mutex>

class ProtectedTicketMap {
public:
    bool contains(int seat) {
        std::lock_guard<std::mutex> lock(m);
        return this->reserveMap.find(seat) != this->reserveMap.end();
    }

    void set(int seat, const std::string& name) {
        std::chrono::milliseconds dura(10 * name.size());
        std::this_thread::sleep_for(dura);
        
        std::lock_guard<std::mutex> lock(m);
        std::cout << "reservando para " << name << std::endl;
        this->reserveMap[seat] = name;
    }

    void print() {
        std::lock_guard<std::mutex> lock(m);
        for (const auto& kv : this->reserveMap) {
            std::cout << kv.first << " -> " << kv.second << std::endl;
        }
    }
private:
    std::mutex m;
    std::map<int, std::string> reserveMap;
};

/**
 * Hace uso del mapa para reservar entradas
 **/
class CinemaTicketManager {
public:
    /*
    * reserva un asiento
    */
    bool reserve(int seat, const std::string& name) {
        if (!ticketMap.contains(seat)) {
            ticketMap.set(seat, name);
            return true;
        }
        return false;
    }
    void print() {
        ticketMap.print();
    }
private:
    ProtectedTicketMap ticketMap;
};


/**
 * Cliente que reserva entradas
 **/
class Client {
public:
    Client(const std::string& clientName, CinemaTicketManager& cinemaManager) :
        name(clientName), cinemaManager(cinemaManager) {};
    void operator()() {
        cinemaManager.reserve(1, this->name);
    }
private:
    const std::string& name;
    CinemaTicketManager& cinemaManager;
};




int main(int argc, char** argv) {
    // secuencial
    {
        CinemaTicketManager cinemaManager;
        Client ana("Ana", cinemaManager);
        Client pedro("Pedro", cinemaManager);
        ana();
        pedro();
        cinemaManager.print();
    }
    // Concurrente
    {
        CinemaTicketManager cinemaManager;
        Client ana("Ana", cinemaManager);
        Client pedro("Pedro", cinemaManager);
        std::thread anaThread(ana);
        std::thread pedroThread(pedro);
        anaThread.join();
        pedroThread.join();
        cinemaManager.print();   
    }
}