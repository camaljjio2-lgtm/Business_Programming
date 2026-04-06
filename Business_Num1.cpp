/* 
# 문제 1 진수 변환

- 10진수 n이 입력되었을 때, k진수로 변환해 출력하는 프로그램을 작성하시오.

-- 입력
    1. 첫 번째 줄에 10진수 n이 입력된다.
    2. 두 번째 줄에 변환을 희망하는 진수 k가 입력된다.(2 <= k <= 9)
-- 출력
    1. 10진수를 k진수로 변환한 결과를 출력한다.

*/
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
  
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;
	int num = 0;
	
	cin >> k >> num ;
	vector<int> knum;
	if (k > 9 || k < 2) {
		return 0;
	}
	
	while (num > 0) {
		knum.push_back(num%k);
		num/=k;
		
	}
	
	reverse(knum.begin(), knum.end());
	
	
	for (size_t i = 0; i < knum.size(); i++) {
		cout << knum[i];
	}
    
    return 0;
    
}