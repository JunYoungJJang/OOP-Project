/*
	Banking System v2.1 by JunYoung
	수정 사항: 메모리 사용량 줄임.
*/

#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

const int MAX_PATRON = 30;

int main(void)
{
	Account* patrons[MAX_PATRON] = { NULL, };
	int num = 0;

	while(1) {
		int sel;
		char name[15];

		Account::ShowMenu();
		cin >> sel;
	
		system("clear");
		if(sel < 1 || sel > 5) {
			cout << "잘못된 입력입니다!" << endl;
			continue;
		} else if(sel == 5) {   // 종료
			break;
		}
	
		int index;	
		unsigned int money;

		switch(sel)
		{
		case 1:   // 계좌 생성
			cout << "아래에 본인의 정보를 입력해주세요." << endl;
			cout << "이    름: ";
			cin >> name;

			system("clear");
			
			patrons[num++] = new Account(name);
			break;	
		
		case 2:   // 입금
			index = Account::identify(patrons);
			if(index == -1) {
				cout << "\n해당 계정 정보가 존재하지 않습니다." << endl;
				sleep(3);
				system("clear");
			} else {
				cout << "\n입금하실 금액을 입력해주세요." << endl;
				cout << "금    액: ";
				cin >> money;
	
				patrons[index]->Deposit(money);
			}
		
			break;

		case 3:   // 출금
			index = Account::identify(patrons);
			if(index == -1) {
				cout << "\n해당 계정 정보가 존재하지 않습니다." << endl;
				sleep(3);
				system("clear");
			} else {
				cout << "\n출금하실 금액을 입력해주세요." << endl;
				cout << "금    액: ";
				cin >> money;
				
				patrons[index]->Withdraw(money);
			}
		
			break;

		case 4:   // 잔액 조회
			cout << "준영 은행의 고객 정보입니다." << endl;
			Account::ShowInfo(patrons);
			break;	
		}
	}

	system("clear");
	cout << "이용해 주셔서 감사합니다." << endl;

	return 0;
}

