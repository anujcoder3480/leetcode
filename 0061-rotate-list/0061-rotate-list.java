/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null || head.next==null || k==0){
            return head;
        }
        int n=1;
        ListNode temp=head;
        while(temp.next!=null){
            n++;
            temp=temp.next;
        }
        k=k%n;
        if(k==0) return head;
        ListNode fast=head;
        ListNode slow=head;
        for(int i=0; i<k; i++){
            fast=fast.next;
        }
        while(fast.next!=null){
            fast=fast.next;
            slow=slow.next;
        }
        ListNode h=slow.next;
        fast.next=head;
        slow.next=null;
        head=h;
        return head;
    }
}