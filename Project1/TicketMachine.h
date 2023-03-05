#pragma once
#ifndef _TICKETMACHINE_H
#define _TICKETMACHINE_H

class TicketMachine
{
public:
	TicketMachine();
	virtual ~TicketMachine();
	void showPrompt();
	void insertMoney(int money);
	void showBalance();
	void printTicket();
	void showTotal();
private:
	const int PRICE;
	int balance = 1000;
	int total;
};
#endif // !TICKETMACHINE
