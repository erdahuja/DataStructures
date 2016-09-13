public class MergeTwoLL {
	Node head; // head of list

	/* Linked list Node*/
	class Node
	{
		int data;
		Node next;
		Node(int d) {data = d; next = null; }
	}

	/* Inserts a new Node at front of the list. */
	public void push(int new_data)
	{
		/* 1 & 2: Allocate the Node &
				Put in the data*/
		Node new_node = new Node(new_data);

		/* 3. Make next of new Node as head */
		new_node.next = head;

		/* 4. Move the head to point to new Node */
		head = new_node;
	}
	
	public Node mergedList(Node head1, Node head2){
		
		
		if(head1 == null){
			return head2;
		}
		
		if(head2 == null){
			return head1;		
		}

		Node current = null;
		
		if(head1.data < head2.data){
				current = head1;
				current.next  = mergedList(head1.next, head2);
			}else{
				current = head2;
				current.next  = mergedList(head1, head2.next);
			}
		
		return current;
	}
	
	void printList(){
		
		Node temp = head;
		
		while(temp!=null){
			System.out.print(temp.data + " --> ");
			temp = temp.next;
		}
		System.out.print("null");
	}

	/* Drier program to test above functions */
	public static void main(String args[])
	{
		MergeTwoLL llist1 = new MergeTwoLL();
		llist1.push(20);
		llist1.push(10);
		llist1.push(5);
		
		llist1.printList();
		
		System.out.println();
		
		MergeTwoLL llist2 = new MergeTwoLL();
		llist2.push(15);
		llist2.push(3);
		llist2.push(2);
		llist2.printList();

		System.out.println();
		
		MergeTwoLL llist3 = new MergeTwoLL();

		System.out.println();
		
		System.out.println("MergedList : --> ");
		
		llist3.head = llist3.mergedList(llist1.head, llist2.head);
		llist3.printList();
		
	}
}