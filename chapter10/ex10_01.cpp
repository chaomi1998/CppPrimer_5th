#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> nums{1,1,1,1,3,3,3,2,2};
    int val;
    while (std::cin >> val) {
        int result = count(nums.cbegin(), nums.cend(), val);
        cout << result << endl;
    }
    return 0;
}
