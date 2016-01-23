#include <iostream>

class Account
{
private:
	char *name, *id, *pw;
	unsigned int balance;
public:
	Account(const char* _name=NULL, const char* _id=NULL, const char* _pw=NULL);
	Account(const Account& a);
	virtual ~Account();
	
	const char* GetName() const;
	const char* GetID() const;
	const char* GetPW() const;
	unsigned int GetBal() const;
	
	virtual void AddMoney(unsigned int money);
	void MinMoney(unsigned int money);

	virtual void ShowAll() const;
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
	virtual void AddMoney(unsigned int money);	

	virtual void ShowAll() const;
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
	virtual void AddMoney(unsigned int money);

	virtual void ShowAll() const;
};

