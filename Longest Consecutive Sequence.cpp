class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_set<int>mp;
		for (int i=0;i<nums.size();i++){
			mp.insert(nums[i]);
		}
		int res=0;
		for (int i=0;i<nums.size();i++){
			int count=1;
			for (int j=nums[i]+1;mp.find(j)!=mp.end();j++){
				count++;mp.erase(j);
			}
			for (int j=nums[i]-1;mp.find(j)!=mp.end();j--){
				count++;mp.erase(j);
			}res=max(res,count);
			if(mp.size()<1)
			    break;
		}
		return res;
	}
};
//好题目，还是有小毛病
// 小错误不断啊
// 还好，第二天总算好了很多
// 不会啦。其实每天早上都是提心吊胆的
