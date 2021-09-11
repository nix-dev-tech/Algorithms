#include <iostream>
#include<vector>
#include<climits>

using namespace std;

void swap(int& num1, int& num2){
    cout<<num1<<" "<<num2<<endl;
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void ShellSort(vector<int>& nums){
    vector<int>gap {8,4,2,1}; //manual gap of 4
    
    for(int gapCounter = 0; gapCounter < gap.size(); gapCounter++){//to iterate gaps, as in counter
        int counter = gap[gapCounter]; //this will be counter to compare element with respective gap between them
        //cout<<"gap"<<gapCounter<<endl;
        for(int pass = 0; pass < nums.size(); pass = pass + counter){ //number of passes respective to each gap
            //cout<<"pass"<<pass<<endl;
            for(int compareCounter = pass + counter; compareCounter > 0 && compareCounter < nums.size(); compareCounter = compareCounter-counter){ //compare all adjecent elements(with respective gap
                //cout<<"compareCounter"<<compareCounter<<endl;
                //cout<<nums[compareCounter]<<" "<<nums[compareCounter-counter]<<endl;
              //insertion sort
                if(nums[compareCounter] < nums[compareCounter-counter]){
                    swap(nums[compareCounter], nums[compareCounter-counter]);
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
    
    ShellSort(nums);
    for(auto num : nums){
        cout<<num<<" ";
    }
    return 0;
}
