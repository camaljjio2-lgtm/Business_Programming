/*
# 문제 4 공약수의 합
- 입력된 두 수 A와 B의 공약수를 모두 합산한 결과를 출력하는 프로그램을 작성하시오.

-- 입력
    1. 첫 번째 줄에 자연수 A와 B가 입력된다.

-- 출력 
    1. 두 수 A와 B의 공약수를 모두 합산한 결과를 출력한다.

*/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b; 
		a = b;
		b = t;
	}
	return a;
}
int main() {
	int a, b;
	cin >> a >> b;
	int c = gcd(a, b);
	int sum = 0;
	for (int i = 1; i <= c; i++) {
		c%i == 0 ? sum += i : 0;
	}
	cout << sum;
}