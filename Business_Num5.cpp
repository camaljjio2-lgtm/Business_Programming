/*
# 문제 5 삼다도 제주도
- 상업이는 제주도를 알리기 위해 제주도를 대표하는 3가지 단어가 포함되어 있는 N x N 크기의 
알파벳으로 구성된 표를 만들고 그 안에 단어를 찾는 퀴즈를 만든다고 한다.
표에서 단어를 찾을 때는 3가지 방법으로만 단어를 찾는다고 한다. 대각선에 단어가 존재 할 때는 왼쪽 위에서 오른쪽 아래로 읽고,
가로로 단어가 존재할 때는 왼쪽에서 오른쪽으로 읽으며, 세로로 단어가 존재할 때는 위에서 아래로 읽는다.
상업이가 만든 표에 'wind' , 'stone', 'woman'이 모두 몇 개 존재하는지 알려주는 프로그램을 작성하시오.

-- 입력
    1. 첫 번째 줄에는 표의 크기에 해당하는 N이 입력된다
    2. 두 번째 줄부터는 N x N을 구성하고 있는 알파벳이 띄어쓰기 없이 입력된다.

-- 출력 
    1. 표에서 찾을 수 있는 wind, stone, woman의 총개수를 출력한다

-- 예시
    - 입력 예시
        5
        winds
        iiast
        nvnso
        deedn
        stone
    - 출력 예시
        5
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
  
int main() {

	int N = 0;
	std::cin >> N;
	
	vector<vector<char> > p(N, vector<char>(N));
	
	string letter ;
	
	//표 입력  
	for (int i = 0; i < N; i++) {
		std::cin >> letter;
		for (int j = 0; j < N; j++) {
			p[i][j] = letter[j];
		}
	}
	
	//가로 p[i][j+1] 
	//세로 p[i-1][j]
	//대각선 p[i-1] [j+1]

	string word[3] = {"wind", "stone", "woman"};
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int l = 0; l < 3; l++) {
				string c = word[l];
				int len = c.size();  
				if (j + len <= N) {
					bool ok = true;
					for (int k = 0; k < len; k++) {
						if(c[k] != p[i][j+k]) {
							ok = false;
							break;
						} 
						
					} 
					if (ok) count++;
				}
				
				
				if (i + len <= N) {
					bool ok = true;
					for (int k =0; k < len; k++) {
						if (c[k] != p[i+k][j]) {
							ok =false;
							break;
						}
						
					}
					if (ok) count++;
				}
		

				if (i + len <= N && j + len <= N) {
					bool ok = true;
					for (int k = 0 ; k < len; k++) {
						if(c[k] != p[i+k][j+k]) {
							ok = false;
							break;
						}
					}
					if(ok) count++;
				}
			}
		}
	}
	
	cout << count;
	
}