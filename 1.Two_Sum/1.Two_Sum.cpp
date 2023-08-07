#include <iostream>

std::vector<int> solution(std::vector<int> nums, int target) {
    bool finish = 0;
    std::vector<int> result;
    for (int i = 0; i < nums.size() - 1; i++) {
        int sum = nums[i];
        std::cout << i;
        for (int j = i + 1; j < nums.size(); j++) {
            if ((sum + nums[j]) == target) {
                result = {i, j};
                finish = 1;
            }
            if ((sum + nums[nums.size()-j]) == target) {
                result = {i, (int)nums.size()-j};
                finish = 1;
            }
        }
        if (finish) { break; }
    }
    return result;
}

int main() {
    std::vector<int> nums = {2,5,5,11};
    auto result = solution(nums, 10);
    for (auto iter : result) {
        std::cout << iter << std::endl;
    }
}