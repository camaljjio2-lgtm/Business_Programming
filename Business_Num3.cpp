/*
# 문제 3 SNS 비밀번호
- 상업이는 SNS에 가입하고자 한다 SNS에 가입하기 위해서는 아이디와 SNS에서 요구하는 비밀번호 요구사항을 맞추어야한다.
비밀번호는 반드시 영어 대문자와 소문자, 특수문자(!@#$%^&*()_+), 숫자가 모두 섞인 비밀번호여야 한다.
만들고자 하는 비밀번호가 영어 대문자만 없으면 'need uppercase', 영어 소문자만 없으면 'need lowercase',
특수문자만 없으면 'need special symbols', 숫자만 없으면 'need number', 2개 이상 없으면 'check your password',
조건을 모두 충족된 비밀번호가 입력되면 'accept'가 출력된다고 한다. 비밀번호 체크 프로그램을 작성하시오.

-- 입력
    1. 첫 번째 줄에 길이가 N인 비밀번호가 입력된다.

-- 출력 
    1. 비밀번호 체크 결과를 출력한다.

*/


#include <iostream>
#include <string>

using namespace std;

string lower(string word, int *cnts) {
	int cnt = 0;
	for (char c : word) {
		if (int(c) >= 97 && int(c) <= 122) {
			cnt++;
		}
	}

	if (cnt < 1) {
		*cnts+=1;
		return "need lowercase";

	}
	return "";
	
}
string upper(string word, int *cnts) {
	int cnt = 0;
	for (char c : word) {
		if (int(c) > 64 && int(c) < 91) {
			cnt++;
		}

	}
	if (cnt < 1) {
		*cnts += 1;
		return "need uppercase";
	}
	return "";
}
string special(string word, int* cnts) {
	int cnt = 0;
	for (char c : word) {
		if (c == char(33) || c==char(64) || c==char(36) || c==char(37) || c==char(94)  || c==char(42) || c==char(40) || c==char(41) || c==char(95) || c==char(43)) {
			cnt++;
		}
	}
	if (cnt <  1) {
		*cnts += 1;
		return "need special sysbols";
	}
	return "";
}

string number(string word, int* cnts) {
	int cnt = 0;
	for (char c : word) {
		if (c > char(47) && c < char(58)) {
			cnt++;
		}
	}
	if (cnt < 1) {
		*cnts += 1;
		return "need number";
	}
	return "";
}

int main() {
	int cnt = 0;

	string word;
	cin >> word;
	string up = upper(word, &cnt);
	string lo = lower(word, &cnt);
	string sp = special(word, &cnt);
	string num = number(word, &cnt);
	if (cnt > 1) {
		cout << "check your password";
	}
	else if (cnt < 1) {
		cout << "accept";
	}
	else {
		
		cout << up;
		cout << lo;
		cout << sp;
		cout << num;
	}
	


}
//대문자 A = 65 90 Z
//97~122 a~z
// 0 =48 49 50 51 52 53 54 55 56 57 