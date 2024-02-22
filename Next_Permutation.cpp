//Approach: 
/*
Let's observe the cases: 

Suppose we take 4321 as a number. This 4321 number is the last lexicographical permutation of these digits: 1, 2, 3, 4. 
But how do we observe that? Observe here that this number's digits are in descending order, or you can say that, from last, 
these digits are in ascending order. 

Let's take another example: 24321. Here we can see that from last, till digit 4, they are in ascending order, which means 
till digit 4, this permutation is the last lexicographical permutation. This means that digit 2 will now change to its next digit, 
which is just greater than 2, to make the next permutation of this number.

31224 is the next lexicographical permutation of 24321. Notice here that, after digit 3, all digits are placed in ascending order.

So here, we conclude our observation that, to make an array's next lexicographical permutation, first we have to find the break-point.
A break-point is the point where that digit is not in ascending order from last.

If we get our break-point digit, then we search for the digit that is just greater than that break-point digit. We will search it 
from the index of that breakpoint to the last. When we find that digit, we will swap that digit with our break-point digit.

Lastly, we will sort the array from break-point index+1 until last.

If we didn't get a breakpoint, that means that permutation is the last lexicographical permutation, so we will sort the entire 
array to make it the first lexicographical permutation.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i=nums.size()-1;
        while(i>=1)
        {
            if(nums[i]>nums[i-1])
                break;
            i--;
        } 
        if(i-1>=0)
        {
            int minIndex=i, mn=nums[i];
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]>nums[i-1] && nums[j]<mn)
                {
                    mn = nums[j];
                    minIndex=j;
                }
            }
            //swap(nums[i-1],nums[minIndex])
            int temp = nums[i-1];
            nums[i-1]=nums[minIndex];
            nums[minIndex]=temp;

            sort(nums.begin()+i,nums.end());
        }
        else
        {
            sort(nums.begin(),nums.end());
        }
    }
};
