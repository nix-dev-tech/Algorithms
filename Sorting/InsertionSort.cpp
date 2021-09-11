#include <iostream>
#include<vector>

using namespace std;

void swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void InsertionSort(vector<int>& nums, bool desc = false){
    for(int i = 1; i < nums.size(); i++){
        for(int j = i; j > 0; j--){
            if(desc){
              //if desc flag is true, sort in descending order.
                if(nums[j] > nums[j-1]){ //check if previous element is less than current and swap if yes else break
                    swap(nums[j], nums[j-1]);
                }
                else{
                    break;
                }
            }
            else{
                if(nums[j] < nums[j-1]){ //check if previous element is greater than current and swap if yes else break
                    swap(nums[j], nums[j-1]);
                }
                else{
                    break;
                }
            }
        }
    }
}

int main()
{
    vector<int>nums{7,4,6,2,1,3,9,11,24,15,5,10,8,14};
    //ascending order
    InsertionSort(nums);
    for(auto num : nums){
        cout<<num<<" ";
    }
    
    cout<<endl;
    
    //descending order
    InsertionSort(nums, true);
    for(auto num : nums){
        cout<<num<<" ";
    }

    return 0;
}
