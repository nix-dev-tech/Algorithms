#include <iostream>
#include<vector>
#include<climits>

using namespace std;

void swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void SelectionSort(vector<int>& nums){
    int smallest = INT_MAX;
    for(int passes = 0; passes < nums.size(); passes++){
        int smallest = INT_MAX;
        int smallestIndex;
        for(int j = passes; j < nums.size(); j++){
            if(nums[j] < smallest) { //identify smallest element and note its index
                smallest = nums[j]; 
                smallestIndex = j;
            }
        }
        swap(nums[passes], nums[smallestIndex]); // smallest index will be its right position, swap the elements
    }
}

int main()
{
    vector<int>nums{7,4,6,2,1,3};
    
    SelectionSort(nums);
    for(auto num : nums){
        cout<<num<<" ";
    }
    return 0;
}
