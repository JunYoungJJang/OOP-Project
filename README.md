bank1.cpp is independant file.   // 2015-12-31


Account.h, Account.cpp, main2.cpp is one.   // 2016-01-01

Account.h, Account.cpp, AccManager.h, AccManager.cpp, bank3.0.cpp is one.
gcc -o bank3.0 Account.cpp AccManager.cpp bank3.0.cpp
// 2016-01-22

수정할 점 : 계좌 정보 중복, 음수 입력, 가독성
