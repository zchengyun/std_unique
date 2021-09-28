#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

int main()
{
    // 含有数个重复元素的 vector
    std::vector<int> v{ 1,2,1,1,3,3,3,4,5,4 };

    // 移除相继（毗邻）的重复元素
    auto last = std::unique(v.begin(), v.end());

    for (int i : v)
        std::cout << i << " ";
    std::cout << "\n";
    // v 现在保有 {1 2 1 3 4 5 4 x x x} ，其中 x 不确定
    v.erase(last, v.end());
    for (int i : v)
        std::cout << i << " ";
    std::cout << "\n";

    // sort 后 unique 以移除所有重复
    std::sort(v.begin(), v.end()); // {1 1 2 3 4 4 5}
    last = std::unique(v.begin(), v.end());
    // v 现在保有 {1 2 3 4 5 x x} ，其中 'x' 不确定
    v.erase(last, v.end());
    for (int i : v)
        std::cout << i << " ";
    std::cout << "\n";
}
