/*
# 문제 2 비밀스러운 숫자
- 상업이는 비밀스러운 숫자를 만들어 보자고 한다. 비밀스러운 숫자란 영단어 글자 하나 하나를 아스키 테이블에 해당하는 
10진수로 변환하고, 변환한 10진수를 8진수로 변환한 후 변화된 숫자를 모두 이어붙인 값을 런 렝스 부호화하는 것을 의미한다.
이를테면 AAAABABABBB를 런 렝스 부호화하게 되면 A4B1A1B1A1B3이 된다.
단어를 비밀스러운 숫자로 만들어주는 프로그램을 작성하시오.

-- 입력
    1. 첫 번째 줄에 길이가 N인 영어단어 1개가 입력된다.
-- 출력
    1. 비밀스러운 숫자를 출력한다


-- 예시
    - 입력 예시             
        hand         
    - 출력 예시
        11510111411251611142
*/
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	char word[50];
	std::cin >> word;
	std::vector<int> asci;
	std::vector<int> eight;
	int ten;
	int i = 0;
	while (word[i] != '\0') {
		ten = int(word[i]);
		while (ten > 0) {
			eight.push_back(ten % 8);
			ten /= 8;
		}
		std::reverse(eight.begin(), eight.end());
		for (size_t j = 0; j < eight.size(); j++) {
			asci.push_back(eight[j]);
		}
		eight.clear();
		i++;
	}
	for (size_t i = 0; i < asci.size(); i++) {
		std::cout << asci[i] << " ";
	}
	std::cout << std::endl;
	int check = 0;

	for (size_t i = 0; i < asci.size(); i++) {
		int cnt = 1;
		check = asci[i];
		for (size_t j = i + 1; j < asci.size(); j++) {
			if (check != asci[j]) {
				break;
			}
			cnt++;

		}
		std::cout << asci[i] << cnt;
		i += cnt - 1;
	}

}