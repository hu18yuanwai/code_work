class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     *
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
        int a = m^n;
        int count=0;
        while(a){
            if(a%2==1) count++;
            a=a>>1;
        }
        return count;
    }
};
