#include "TicketMachine.h"
#include <iostream>
using namespace std;

int flag = 1;

TicketMachine::TicketMachine(): PRICE(0)
{

}

TicketMachine::~TicketMachine()
{
}

void TicketMachine::showPrompt()
{
	cout<< "something" <<endl;
}

void TicketMachine::insertMoney(int money)
{
	balance += money;
}

void TicketMachine::showBalance()
{
	cout << balance;
	cout << flag;
}
