#include <string.h>
#include <iostream>
#include "Account.h"

using std::cout;
using std::endl;

Account::Account(const char* _name, const char* _id, const char* _pw)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);

	id = new char[strlen(_id) + 1];
	strcpy(id, _id);
	
	pw = new char[strlen(_pw) + 1];
	strcpy(pw, _pw);

	balance = 0;
}
Account::Account(const Account& a)
{
	name = new char[strlen(a.name) + 1];
	strcpy(name, a.name);

	id = new char[strlen(a.id) + 1];
	strcpy(id, a.id);

	pw = new char[strlen(a.pw) + 1];
	strcpy(pw, a.pw);

	balance = a.balance;
}   // 오류: 계좌 번호 겹침! 돈 복사?
Account::~Account()
{
	delete []name;
	delete []id;
	delete []pw;
}

const char* Account::GetName() const
{
	return name;
}
const char* Account::GetID() const
{
	return id;
}
const char* Account::GetPW() const
{
	return pw;
}
unsigned int Account::GetBal() const
{
	return balance;
}

void Account::AddMoney(int money)
{
	balance += money;
}

void Account::MinMoney(int money)
{
	balance -= money;
}
