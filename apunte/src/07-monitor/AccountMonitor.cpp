#include "AccountMonitor.h"
#include "Account.h"

AccountMonitor::AccountMonitor() {}

void AccountMonitor::addAccount(const std::string& name) {
    std::lock_guard<std::mutex> l(m);
    this->accounts[name];
}

void AccountMonitor::transfer(const std::string& from, const std::string& to) {
    std::lock_guard<std::mutex> l(m);
    Account& fromAcc = this->accounts.at(from);
    Account& toAcc = this->accounts.at(to);
    fromAcc.withdraw(1);
    toAcc.deposit(1);
}

void AccountMonitor::printResult() {
    std::lock_guard<std::mutex> l(m);
    for (auto it = this->accounts.begin(); it != this->accounts.end(); it++) {
        printf("acc:%s - balance:%d\n", it->first.c_str(), it->second.getBalance());
    }
}

void AccountMonitor::printResultUnsafe() const {
    for (auto it = this->accounts.begin(); it != this->accounts.end(); it++) {
        printf("acc:%s - balance:%d\n", it->first.c_str(), it->second.getBalance());
    }
}