/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        HashSet<Integer> sortedValues = new HashSet<Integer>();
        
        //traverse the List
        ListNode current = head;
        ListNode previous = head;
        while(current!=null)
        {
            if(!sortedValues.contains(current.val))
            {
                //first occurrence
                sortedValues.add(current.val);
                
                previous = current;
                current = current.next;
            }
            else
            {
                //already exists
                //by unlinking, java GC will remove
                
                //update previous to point to next
                previous.next = current.next;
                current  = current.next;
            }
        }
        return head;
    }
}