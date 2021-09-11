#include <iostream>
#include<vector>

using namespace std;

void swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void BubbleSort(vector<int>& nums){
    for(int i = nums.size(); i > 0; i--){ //number of passes should be n-1 as swapping operation will take place n - 1 times
        for(int j = 0; j < i; j++){ // largest element will be transfer to last position and so on
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]); // swap adjecent elements if first element is greater than next
            }
        }
    }
}

int main()
{
    vector<int>nums{7,4,6,2,1,3};
    BubbleSort(nums);
    for(auto num : nums){
        cout<<num<<endl;
    }

    return 0;
}
