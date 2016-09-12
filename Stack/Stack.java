package Stack;
import java.util.Arrays;
import java.util.Scanner;

public class Stack {

	private int top = -1;
	private int[] array = new int[5];
	static Scanner scanner = new Scanner(System.in);

	void push() {
		if (top == array.length - 1) {
			System.out.println("Overflow!..");
			return;
		}
		System.out.println("Enter number :");
		int num = scanner.nextInt();
		top = top + 1;
		array[top] = num;
		return;

	}

	void pop() {
		if (top == -1) {
			System.out.println("UNDERFLOW..");
			return;
		}

		top = top - 1;
	}

	boolean isEmpty() {
		if (top == -1) {
			return true;
		} else
			return false;
	}

	void display() {
		for (int i = 0; i <= top; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
	}

	void peek() {
		System.out.println("top :" + top);

	}

	private void extendStack() {

		int[] copy = Arrays.copyOf(array, array.length + 2);
	}

	public static void main(String[] args) {
		Stack s = new Stack();
		int choice;

		do {
			System.out.println("Enter choice :");
			System.out.println("1.PUSH");
			System.out.println("2.PULL");
			System.out.println("3.PEEK");
			System.out.println("4.DISPLAY");
			System.out.println("5.EXIT");
			System.out.println("6.Extend STACK");
			choice = scanner.nextInt();
			switch (choice) {
			case 1:
				s.push();
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.peek();
				break;
			case 4:
				s.display();
				break;
			case 5:
				System.exit(0);
				break;
			case 6:
				s.extendStack();
				break;

			}

		} while (choice <= 6);
		// TODO Auto-generated method stub

	}

}
