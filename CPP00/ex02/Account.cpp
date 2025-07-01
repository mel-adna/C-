#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t now = std::time(NULL);
    std::tm *lt = std::localtime(&now);

    std::cout << "[" << (lt->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (lt->tm_mon + 1)
              << std::setw(2) << lt->tm_mday << "_"
              << std::setw(2) << lt->tm_hour
              << std::setw(2) << lt->tm_min
              << std::setw(2) << lt->tm_sec << "]";
}

Account::~Account() {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount;
    
    this->_amount += deposit;
    this->_nbDeposits++;

    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    std::cout << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount;

    if (withdrawal > this->_amount) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;

    return true;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}