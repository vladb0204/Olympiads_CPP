#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<vector<int>> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i][j] == 0) {
                cout << "\n";
                break;
            } else {
                cout << nums[i][j] << " ";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num; cin >> num;
    if (num == 0) {
        cout << " ";
    } else if (num == 1) {
        cout << 1;
    } else {
        vector<vector<int>> nums(num, vector<int>(num));

        nums[0][0] = 1;
        nums[1][0] = nums[1][1] = 1;

        for (int i = 2; i < num; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    nums[i][0] = 1;
                } else if (i == j) {
                    nums[i][j] = 1;
                } else {
                    nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
                }
            }
        }

        printArray(nums);
    }
}