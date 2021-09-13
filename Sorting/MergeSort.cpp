#include <iostream>
#include<vector>
#include<climits>

using namespace std;

//Merge two sorted arrays into single array
vector<int>Merge(vector<int>nums1, vector<int>nums2){
    vector<int>result;
    int num1_ptr = 0, num2_ptr = 0;
    while(num1_ptr < nums1.size() && num2_ptr < nums2.size()){ //if both arrays has element
        if(nums1[num1_ptr] < nums2[num2_ptr]){ //compare both the elements, and push whichever is smaller into result array
            result.push_back(nums1[num1_ptr]);
            num1_ptr++;
        }
        else{
            result.push_back(nums2[num2_ptr]);
            num2_ptr++;
        }
    }
    
    while(num1_ptr<nums1.size()){ // only array1 has elements left, no need to compare. Push element in result array as is
        result.push_back(nums1[num1_ptr]);
        num1_ptr++;
    }
    
    while(num2_ptr<nums2.size()){ //only array2 has elements left, no need to compare. Push element in result array as is
        result.push_back(nums2[num2_ptr]);
        num2_ptr++;
    }
    return result;
}

//Divide given arrays all the way and merge in the end in sorted order
vector<int> MergeSort(vector<int>nums, int left, int right){
    if(left == right){
        return {nums[left]};
    }
    
    int mid = left+(right-left)/2; // divide given array into two halves
    auto left_array = MergeSort(nums, left, mid); //left array is further sent to divide or merge
    auto right_array = MergeSort(nums, mid+1, right); //right array is further sent to divide or merge
    return Merge(left_array, right_array);
}

vector<int> MergeSort(vector<int> nums){
    //divide
    return MergeSort(nums, 0, nums.size()-1);
    //merge or conquer
}

int main()
{
    vector<int>nums{7,4,6,2,1,3,9,11,24,15,5,10,8,14};
    
    vector<int> result = MergeSort(nums);
    for(auto num : result){
        cout<<num<<" ";
    }
    return 0;
}
