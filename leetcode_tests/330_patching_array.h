#ifndef _330_PATCHING_ARRAY
#define _330_PATCHING_ARRAY

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        //return the count, of min number of patches applied to nums
        // to allow generate 1 to n
        
        //0 patch case
        //1,2,2 n=5
        
        //basically find the holes
        
        //[1,5,7]
        //3 numbers.. permutations is 3bits i.e. 2^3 - 1 = 7
        //000 not used
        //001 7
        //010 5
        //011 5 7
        //100 1
        //101 1 7
        //110 1 5
        //111 1 5 7
        
        //if want all numbers to n
        
        //5 numbers is 2^5 - 1 = 32 - 1 = 31
        // 4 numbers i 2^4 -1 = 16 - 1 = 15
        // so for 20... would always need 2 numbers from 3
        
        long origNumberOfNums = nums.size();
        long numberOfNums = origNumberOfNums;
        
        long permutations = pow(2,numberOfNums)-1;
        
        bool enough = false;
        
        while(!enough)
        {
            
            permutations = pow(2,numberOfNums)-1;
            cout << "num of perm : " << permutations << endl;
            if(n > permutations)
            {
                numberOfNums++;
            }
            else
            {
                enough = true;
            }
        }
        
        return numberOfNums - origNumberOfNums;
    }
    

};

#endif