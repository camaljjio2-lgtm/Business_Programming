#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >>m;
    string num;
    int w = 0;
    vector<vector<int>> grid(n, vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        cin >> num;
        for (int j = 0; j < m; j++) {
            grid[i][j] = int(num[j] - '0');
            if (grid[i][j] == 1) w = 1;
        }

    }


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == 1)  {
                grid[i][j] = min({grid[i][j-1], grid[i-1][j], grid[i-1][j-1] }) + 1;
                if (w < grid[i][j]) {
                    w = grid[i][j];
                }
            }

        }
    }

    cout << w * w;

    return 0;
}