#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

Account::Account() {
	name = new char[6];
	strcpy(name, "admin");
	
	id = new char[12];
	strcpy(id, "00000-00000");
	
	money = 10000000;
}

Account::Account(const char* _name)
{
	if(_name == NULL) {
		cout << "이름을 입력해주세요!" << endl;
		return;
	} else if(strlen(_name) > 12) {
		cout << "이름이 너무 길어요..." << endl;
		return;
	}
	money = 0;

	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	
	id = new char[12];			
	for(int i=0; i<11; i++) {
		if(i == 5) {
			id[i] = '-';
			continue;
		}
		id[i] = rand()%10 + '0';
	}
	id[11] = '\0';

	cout << "계좌가 생성되었습니다." << endl;
	cout << "이     름: " << name << endl;
	cout << "계좌번호: " << id << endl;
	cout << "잔     액: " << money << endl;

	sleep(5);
	system("clear");		
}

Account::Account(const Account& temp)
{
	money = temp.money;
	name = new char[strlen(temp.name) + 1];
	id = new char[strlen(temp.id) + 1];
	
	strcpy(name, temp.name);
	strcpy(id, temp.id);
	
	id[0] = id[10] = '0';   // 임시: 똑같은 계좌 생성 방지
}

Account::~Account()
{
	delete []name;
	delete []id;	
}

void Account::Deposit(unsigned int _money)
{
	money += _money;

	cout << "\n거래가 성공적으로 이루어졌습니다." << endl;
	cout << "잔    액: " << money << endl;

	sleep(3);
	system("clear");	
}

void Account::Withdraw(unsigned int _money)
{
	if(_money > money) {
		cout << "\n잔액을 확인해주세요." << endl;
		cout << "잔    액: " << money<< endl;

		sleep(3);
		system("clear");
	} else {
		money -= _money;
		
		cout << "\n거래가 성공적으로 이루어졌습니다." << endl;
		cout << "잔    액: " << money << endl;
	
		sleep(3);
		system("clear");
	}
}

// 수정: reference 식 참조
static int Account::identify(Account* arr[])
{
	int i;
	char _name[20], _id[12];

	cout << "본인 확인을 위해 아래 정보를 입력해주세요." << endl;
	cout << "이    름: ";	
	cin >> _name;

	cout << "계좌번호: ";
	cin >> _id;
	
	for(i=0; arr[i]; i++) {
		if(!strcmp(arr[i]->name, _name) && !strcmp(arr[i]->id, _id)) {
			return i;
		}
	}

	return -1;	
}

static void Account::ShowInfo(Account* arr[])
{
	for(int i=0; arr[i]; i++) {
		char id[12];
	
		strcpy(id, arr[i]->id);
		for(int j=6; j<11; j++) {
			id[j] = '*';
		}
	
		cout << "이    름: " << arr[i]->name << endl;
		cout << "계좌번호: " << id << endl;
		cout << "잔    액: " << arr[i]->money << endl;
		cout << endl;
	}
}

static Account::ShowMenu()
{
	cout << "=== 준영 은행입니다~~~ ===" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 전체 고객 잔액 조회" << endl;
	cout << "5. 종료 " << endl;

	cout << "\n입력: ";
}

