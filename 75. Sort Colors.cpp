#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int n=nums.size();
		int count_0 =0,count_1=0,count_2=0;
		for(int i:nums){
			if(i==0) ++count_0;
			else if(i==1) ++count_1;
			else ++count_2;
		}
		for(int i=0;i<count_0;i++){
			nums[i]=0;
		}
		for(int i=count_0;i<count_0+count_1;i++){
			nums[i]=1;
		}
		for(int i=count_0+count_1;i<n;i++){
			nums[i]=2;
		}
    }
};
int main(){
	Solution sol;
	vector<int> nums={2,0,2,1,1,0};
	sol.sortColors(nums);
}

