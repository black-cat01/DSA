class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxVal=0,minVal=0;
        stack<int>st1,st2;
        int n=nums.size();
        for(int i=0;i<=n;i++){

            //Calculation of maxVal:Whenever the next greater of top is found, its the right boundary
            while(st1.empty()==false && (i==n  || nums[st1.top()]<nums[i] )){
                long long t=st1.top();
                st1.pop();
                long long r=i-1,l=(st1.empty()==false)?st1.top()+1:0;
                //cout<<t<<endl;
                maxVal+=((r-t+1)*(t-l+1)*nums[t]);
            }
            st1.push(i);


            //Calculation of minVal:
            while(st2.empty()==false && (i==n || nums[st2.top()]>nums[i] )){
                long long t=st2.top();
                st2.pop();
                long long r=i-1,l=(st2.empty()==false)?st2.top()+1:0;
                minVal+=(r-t+1)*(t-l+1)*nums[t];
            }
            st2.push(i);

        }
        //cout<<maxVal<<endl;
        return maxVal-minVal;
    }
};
