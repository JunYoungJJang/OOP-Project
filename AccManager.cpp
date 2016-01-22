#include <iostream>
#include <cstdlib>
#include <string.h>
#include "AccManager.h"

using std::cout;
using std::cin;
using std::endl;

AccManager::~AccManager()
{
	for(int i=0; i<cnt; i++) {
		delete user[i];
	}
}

void AccManager::makeAccount()
{
	char name[256], id[12], pw[256];

	cout << endl;
	cout << "아래에 계좌 생성에 필요한 정보를 입력해주세요." << endl;

	cout << "이    름: ";
	cin >> name;
	
	if(name == NULL || strlen(name) > 20) {
		cout << "이름은 한글 10자 이하 영어 20자 이하로 입력해주세요." << endl;
		cout << "계좌 생성에 실패했습니다!!!" << endl<<endl;

		return;
	}

	cout << "비밀번호: ";
	cin >> pw;

	if(pw == NULL || strlen(pw) > 20 || strlen(pw) < 5) {
		cout << "비밀번호는 영어, 숫자 혼합 5자 이상 20자 이하로 입력해주세요." << endl;
		cout << "계좌 생성에 실패했습니다!!!" << endl << endl;

		return;
	}
	
	for(int i=0; i<11; i++) {
		if(i == 5) {
			id[i] = '-';
			continue;
		}
		id[i] = (rand()%10) + '0';
	}
	id[11] = '\0';

	user[cnt++] = new Account(name, id, pw);

	cout << "계좌가 성공적으로 생성되었습니다." << endl<<endl;
	cout << "이    름: " << user[cnt-1]->GetName() << endl;
	cout << "계좌번호: " << user[cnt-1]->GetID() << endl;
	cout << "비밀번호: ";
	for(int i=0; i<strlen( user[cnt-1]->GetPW() ); i++) {
		cout << '*';
	}
	cout << endl;
	cout << "잔    액: " << user[cnt-1]->GetBal() << endl<<endl;
}

void AccManager::inOut(mode sel)
{
	char name[256], id[256], pw[256];
	unsigned int money;

	cout << endl;
	cout << "아래에 입금하실 계좌 정보를 입력해주세요." << endl;
	cout << "이름: ";
	cin >> name;	
	if(name == NULL || strlen(name) > 20) {
		cout << "이름은 한글 10자 이하 영어 20자 이하입니다." << endl<<endl;
		return;
	}

	cout << "계좌번호: ";
	cin >> id;
	if(strlen(id) != 11) {
		cout << "계좌 번호는 11자리 입니다." << endl<<endl;
		return;
	}

	cout << "비밀번호: ";
	cin >> pw;
	if(id == NULL || strlen(id) > 20 || strlen(id) < 5) {
                cout << "비밀번호는 영어, 숫자 혼합 5자 이상 20자 이하입니다." << endl<<endl;
                return;
    }

	if(sel == DEPOSIT) {
		cout << "입금하실 금액: ";
	} else if(sel == WITHDRAW) {
		cout << "출금하실 금액: ";
	} else {
		cout << "ERROR!!! CODE: 504" << endl<<endl;
		return;
	}
	cin >> money;
	cout << endl;

	Account temp(name, id, pw);
	for(int i=0; i<cnt; i++) {
		if(identify(user[i], temp)) {
			if(sel == DEPOSIT) {
				user[i]->AddMoney(money);
			} else {
				if(user[i]->GetBal() < money) {
					cout << "잔액을 확인해주세요!!" << endl<<endl;
					return;
				} else {
					user[i]->MinMoney(money);
				}
			}
		
			cout << "정상적으로 처리되었습니다." << endl;
			cout << "잔액: " << user[i]->GetBal() << endl<<endl;
			return;			
		}
	}

	cout << "없는 계좌 정보 입니다." << endl<<endl;
}

void AccManager::remit()
{
	char name[256], id[256], pw[256];
	unsigned int money, index;
	
	bool flag=false;

	cout << endl;
	cout << "본인 확인을 위해 아래 정보를 입력해주세요." << endl;
	cout << "이름: ";
	cin >> name;	
	if(name == NULL || strlen(name) > 20) {
		cout << "이름은 한글 10자 이하 영어 20자 이하입니다." << endl<<endl;
		return;
	}

	cout << "계좌번호: ";
	cin >> id;
	if(strlen(id) != 11) {
		cout << "계좌 번호는 11자리 입니다." << endl<<endl;
		return;
	}

	cout << "비밀번호: ";
	cin >> pw;
	if(id == NULL || strlen(id) > 20 || strlen(id) < 5) {
        cout << "비밀번호는 영어, 숫자 혼합 5자 이상 20자 이하입니다." << endl<<endl;
        return;
    }

	Account temp(name, id, pw);
	for(int i=0; i<cnt; i++) {
		if(identify(user[i], temp)) {
			flag = true;
			index = i;
			break;
		}
	}
	
	if(flag == false) {
		cout << "본인 확인에 실패 하였습니다." << endl<<endl;
		return;
	}

	cout <<endl;
	cout << "받는 사람의 정보를 입력해주세요." << endl;
	cout << "이    름: ";
	cin >> name;

	cout << "계좌번호: ";
	cin >> id;

	cout << "송금하실 금액: ";
	cin >> money;
	cout <<endl;

	for(int i=0; i<cnt; i++) {
		if(!strcmp(name, user[i]->GetName()) && !strcmp(id, user[i]->GetID()))
		{
			if(user[index]->GetBal() < money) {
				cout << "잔액을 확인해주세요!" << endl<<endl;
			} else {
				user[i]->AddMoney(money);
				user[index]->MinMoney(money);
				cout << "정상적으로 처리되었습니다." << endl<<endl;
			}
			return;
		}
	}

	cout << "없는 계좌 정보 입니다. " << endl<<endl;
}

void AccManager::showAllUsers()
{
	cout << endl;
	for(int i=0; i<cnt; i++) {
		cout << "이    름: " << user[i]->GetName() << endl;
    	cout << "계좌번호: " << user[i]->GetID() << endl;
    	cout << "비밀번호: ";
    	for(int j=0; j<strlen( user[i]->GetPW() ); j++) {
        	cout << '*';
        }
       	cout << endl;
        cout << "잔    액: " << user[i]->GetBal() << endl;
		cout << endl;
	}
}

bool AccManager::identify(const Account* src, const Account& dest)
{
	if(!strcmp(src->GetName(), dest.GetName()) && !strcmp(src->GetID(), dest.GetID()) && !strcmp(src->GetPW(), dest.GetPW())) {
		return true;
	} else {
		return false;
	}
}

void AccManager::menu()
{
	cout << "=== 준영 은행입니다~ ===" << endl;
	cout << "1. 계좌 생성 " << endl;
	cout << "2. 입금 " << endl;
	cout << "3. 출급 " << endl;
	cout << "4. 송금 " << endl;
	cout << "5. 사용자 정보 확인" << endl<<endl;
	
	cout << "메뉴 입력(종료:0): ";
}
