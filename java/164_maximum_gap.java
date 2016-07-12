public class Solution {
    public int maximumGap(int[] nums) {
        
        int maxDiff=0;
        if(nums.length<2)
        {
        }
        else
        {
            //find max difference between elements
            // for array in sorted form
            TreeSet<Integer> sortedNums = new TreeSet<Integer>();
            for(int n : nums)
            {
                sortedNums.add(n);
            }
            
            
            int prevNum = -1;
            for(int n : sortedNums)
            {
                if(prevNum==-1)
                {
                    prevNum = n;
                }
                else
                {
                    int diff = n-prevNum;
                    if( diff > maxDiff)
                    {
                        maxDiff = diff;
                    }
                    prevNum = n;
                }
            }
            
        }
        
        return maxDiff;
    }
}