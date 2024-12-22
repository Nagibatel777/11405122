#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        // Вычисляем площадь
        int width = right - left;
        int area = min(height[left], height[right]) * width;
        maxWater = max(maxWater, area);

        // Двигаем меньший из указателей
        if (height[left] < height[right]) {
            ++left;
        }
        else {
            --right;
        }
    }

    return maxWater;
}

int main() {
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << "Максимальная площадь воды: " << maxArea(height) << endl;
    return 0;
}