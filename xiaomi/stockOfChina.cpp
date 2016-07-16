//节约空间
class Solution {
public:
    /**
     * 计算你能获得的最大收益
     *
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
     int maxProfit_Once(vector<int>& prices,int be,int end) {
         int len=end-be+1;
         if(len<2) return 0;
         int maxSum = 0, thisSum = 0;
         for(int j=be+1;j<end;j++){
             thisSum = thisSum +(prices[j]-prices[j-1]);
             if(thisSum>maxSum) maxSum = thisSum;
             else if(thisSum<0) thisSum = 0;
         }
         return maxSum;
     }

    int calculateMax(vector<int> prices) {
        if(prices.size()<2) return 0;
        int maxN = 0;
        for(int i=0;i<prices.size();i++)
            maxN = max(maxN,maxProfit_Once(prices,0,i)+maxProfit_Once(prices,i,prices.size()));
        return maxN;
    }
};


//需要很多的空间
class Solution {
public:
    /**
     * 计算你能获得的最大收益
     *
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
     	int maxProfit_Once(vector<int>& prices,int be,int end) {
     	int len=end-be+1;
     	if(len==0||len==1)
     		return 0;
     	int temp;
     	vector<int>fn(len);
     	fn[0]=0;
     	for(int i=be+1;i<end;++i){
     		temp=prices[i]-prices[i-1];
     		if(fn[i-be-1]<0){
     			fn[i-be]=temp;
     		}
     		else{
     			if(fn[i-be-1]+temp<0)
     				fn[i-be]=0;
     			else
     				fn[i-be]=fn[i-be-1]+temp;
     		}
     	}

     	int maxN=0;
     	for(int i=0;i<len;++i){
     		if(maxN<fn[i])
     			maxN=fn[i];
     	}
     	return maxN;
     	}

    int calculateMax(vector<int> prices) {
        if(prices.size()<2) return 0;
        int maxN=0;
        for(int i=0;i<prices.size();i++){
            maxN=max(maxN,maxProfit_Once(prices,0,i)+maxProfit_Once(prices,i,prices.size()));
        }
        return maxN;
    }
};


//空间O(n)，时间O(n);
class Solution {
public:
    /**
     * 计算你能获得的最大收益
     *
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax(vector<int> prices) {
        if(prices.size()<2) return 0;
        vector<int>left,right;
        int thisSum=0,maxSum=0;
        for(int i=1;i<prices.size();i++){
            thisSum = thisSum + (prices[i]-prices[i-1]);
            if(thisSum>maxSum){
                maxSum=thisSum;
            }
            else if(thisSum<0){
                thisSum=0;
            }
            left.push_back(maxSum);
        }

        thisSum=0,maxSum=0;
        for(int i=prices.size()-2;i>=0;i--){
            thisSum = thisSum + (prices[i+1]-prices[i]);
            if(thisSum>maxSum){
                maxSum=thisSum;
            }
            else if(thisSum<0){
                thisSum=0;
            }
            right.push_back(maxSum);
        }

        int maxRe = max(left[left.size()-1],right[right.size()-1]);
        for(int i=0;i<left.size()-1;i++){
            maxRe = max(maxRe,left[i]+right[left.size()-1-i-1]);
        }
        return maxRe;
    }
};
