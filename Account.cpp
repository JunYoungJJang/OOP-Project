#include <string.h>
#include <iostream>
#include "Account.h"

using std::cout;
using std::endl;

/***** Account class *****/
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

void Account::AddMoney(unsigned int money)
{
	balance += money;
}

void Account::MinMoney(unsigned int money)
{
	balance -= money;
}

void Account::ShowAll() const
{
	cout << "이    름: " << GetName() << endl;
	cout << "계좌번호: " << GetID() << endl;
	cout << "비밀번호: ";
	for(int i=0; i<strlen(GetPW()); i++) {
		cout << '*';
	}
	cout << endl;
	cout << "잔    액: " << GetBal() <<endl;
}

/***** CreditAcc class *****/
CreditAcc::CreditAcc(const char* _name, const char* _id, const char* _pw)
: Account(_name, _id, _pw)
{
	interest = 0;
}

CreditAcc::CreditAcc(const CreditAcc& c)
: Account(c)
{
	interest = c.GetInterest();
}

CreditAcc::~CreditAcc()
{
	// 디폴트 소멸자
	// - 동적 할당 없음
}

unsigned int CreditAcc::GetInterest() const {
	return interest;
}

void CreditAcc::AddMoney(unsigned int money) {
	int interest = money*0.01;

	this->Account::AddMoney(money + interest);
	this->interest += interest;
}

void CreditAcc::ShowAll() const {
	this->Account::ShowAll();   
	cout << "이    자: " << GetInterest() << endl;
}

/***** DonationAcc class *****/
DonationAcc::DonationAcc(const char* _name, const char* _id, const char* _pw)
: Account(_name, _id, _pw)
{
	donation = 0;
}

DonationAcc::DonationAcc(const DonationAcc& d)
: Account(d)
{
	donation = d.GetDonation();
}

DonationAcc::~DonationAcc()
{
	// 디폴트 소멸자
	// - 동적 할당 없음
}

unsigned int DonationAcc::GetDonation() const
{
	return donation;
}

void DonationAcc::AddMoney(unsigned int money)
{
	int donation = money * 0.01;
	
	this->Account::AddMoney(money - donation);
	this->donation += donation;
}

void DonationAcc::ShowAll() const
{
	this->Account::ShowAll();
	cout << "기 부 금: " << GetDonation() << endl;
}
