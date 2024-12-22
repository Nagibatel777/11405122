#include <iostream>
#include <vector>
#include <algorithm> // для std::min и std::max

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_water = 0;

    while (left < right) {
        int width = right - left;
        max_water = max(max_water, min(height[left], height[right]) * width);

     
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}

int main() {
    
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Максимальная площадь: " << maxArea(height) << endl;

    return 0;
}