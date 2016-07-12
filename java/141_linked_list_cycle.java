/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        //a cycle is a loop in the list
        
        //the reference test can be checked by using == in java
        
        //traverse the list
        ListNode current = head;
        
        HashSet<ListNode> nodes = new HashSet<ListNode>();
        
        Boolean foundCycle = false;
        
        while(current!=null)
        {
            if(!nodes.contains(current))
            {
                nodes.add(current);
            }
            else
            {
                foundCycle = true;
                break;
            }
            current = current.next;
        }
        
        return foundCycle;
        
    }
}