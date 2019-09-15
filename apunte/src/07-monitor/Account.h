#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
  Account();
  void withdraw(int amount);
  void deposit(int amount);
  int getBalance() const;
private:
  int balance;
};

#endif
