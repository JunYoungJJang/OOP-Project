#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <iostream>

class Account
{
private:
	char *name, *id, *pw;
protected:
	unsigned int balance;
public:
	Account(const char* _name=NULL, const char* _id=NULL, const char* _pw=NULL);
	Account(const Account& a);
	virtual ~Account();
	
	const char* GetName() const;
	const char* GetID() const;
	const char* GetPW() const;
	unsigned int GetBal() const;
	
	virtual void operator+=(unsigned int money);
	void operator-=(unsigned int money);

	virtual void ShowAll() const;
	
	Account& operator=(const Account& a);
};

class CreditAcc : public Account
{
private:
	unsigned int interest;
public:
	CreditAcc(const char* _name=NULL, const char* _id=NULL, const char* _pw=NULL);
	CreditAcc(const CreditAcc& c);
	virtual ~CreditAcc();
	
	unsigned int GetInterest() const;
	virtual void operator+=(unsigned int money);	

	virtual void ShowAll() const;

	CreditAcc& operator=(const CreditAcc& c);
};

class DonationAcc : public Account
{
private:
	unsigned int donation;
public:
	DonationAcc(const char* _name=NULL, const char* _id=NULL, const char* _pw=NULL);
	DonationAcc(const DonationAcc& d);
	virtual ~DonationAcc();

	unsigned int GetDonation() const;
	virtual void operator+=(unsigned int money);

	virtual void ShowAll() const;

	DonationAcc& operator=(const DonationAcc& d);
};

#endif

