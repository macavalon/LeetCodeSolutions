public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        //the median is the middle value in a sorted array
        
        //so for two array, needs to sort values from both
        // and find the middle value
        
        //will stored number, and the count of each
        TreeMap<Integer,Integer> sorted = new TreeMap<Integer,Integer>();
        
        for(int val : nums1)
        {
            int count = 0;
            if(sorted.containsKey(val))
            {
                count = sorted.get(val);
            }
            count++;
            
            sorted.put(val,count);
        }
        
        for(int val : nums2)
        {
            int count = 0;
            if(sorted.containsKey(val))
            {
                count = sorted.get(val);
            }
            count++;
            
            sorted.put(val,count);
        }
        
        
        //the arrays are already pre-sorted
        //to get O(log (m+n))
        // would need to know where they overlap
        //with a binary search (on each)
        
        int lengthNums1 = nums1.length;
        int lengthNums2 = nums2.length;
        
        int total = lengthNums1 + lengthNums2;
        
        int indexA = 0;
        int indexB = 0;
        
        if(total%2 ==0)
        {
            indexA = total/2;
            indexB = indexA+1;
        }
        else
        {
          indexA = indexB = (total+1)/2; // e.g. 3, 3+1 = 4/2 = 2
        }
        
        int i=0;
        int lower = 0;
        Boolean foundLower = false;
        
        int upper = 0;
        Boolean foundUpper = false;
        
        for(int key : sorted.keySet())
        {
           int count = sorted.get(key);
           
           i += count;
           
           if (i >= indexA && !foundLower)
           {
               lower = key;
               foundLower = true;
           }
           
           if (i >= indexB && !foundUpper)
           {
               upper = key;
               foundUpper = true;
           }
           
           if(foundLower && foundUpper)
           {
               break;
           }
        }
        
        double median = ((double)lower+(double)upper)/2;
        
        return median;
        
        //now to find indexA/B from the two sorted arrays
        
        // start from halfway in each
        /*int index1 = lengthNums1/2;
        int index2 = lengthNums2/2;
        
        int val1 = nums1[index1];
        int val2 = nums2[index2];
        
        if(val1 < val2)
        {
            //then val1
        }
        else if (val1 == val2)
        {
            
        }
        else if (val1 > val2)
        {
            
        }*/
        
        
        
    }
}