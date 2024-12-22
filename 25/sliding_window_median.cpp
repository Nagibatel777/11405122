#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<double> medians;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Добавляем текущий элемент в окно
            window.insert(nums[i]);
            
            // Удаляем элемент, который выходит из окна
            if (window.size() > k) {
                window.erase(window.find(nums[i - k]));
            }
            
            // Если окно заполнено, вычисляем медиану
            if (window.size() == k) {
                auto mid = next(window.begin(), k / 2);
                if (k % 2 == 0) {
                    auto mid_prev = prev(mid);
                    medians.push_back(((double)(*mid) + *mid_prev) / 2.0);
                } else {
                    medians.push_back(*mid);
                }
            }
        }
        
        return medians;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<double> result = sol.medianSlidingWindow(nums, k);
    for (double median : result) {
        cout << median << " ";
    }
    cout << endl;
    
    return 0;
}