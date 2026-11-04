#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::setfill;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void) {
	std::time_t t = std::time(NULL);
	std::tm* tm = std::localtime(&t);
	cout << "["
		<< (tm->tm_year + 1900)
		<< setfill('0') << setw(2) << (tm->tm_mon + 1)
		<< setfill('0') << setw(2) << tm->tm_mday
		<< "_"
		<< setfill('0') << setw(2) << tm->tm_hour
		<< setfill('0') << setw(2) << tm->tm_min
		<< setfill('0') << setw(2) << tm->tm_sec
		<< "] ";
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< endl;
}

int	Account::checkAmount(void) const {
	return _amount;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (withdrawal > _amount) {
		cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:refused" << endl;
		return false;
	}
	cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
		cout << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< endl;
	return true;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	cout << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< endl;
}

Account::Account(int initial_deposit) {
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;

	cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created" << endl;
}

Account::~Account(void) {
	_displayTimestamp();
	cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << endl;
	_nbAccounts--;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< endl;
}

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}
