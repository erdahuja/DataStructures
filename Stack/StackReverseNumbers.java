package Stack;

import java.util.Arrays;
import java.util.Scanner;

public class StackReverseNumbers {

	private int top = -1;
	private static int[] array = new int[5];
	static Scanner scanner = new Scanner(System.in);

	void push(int v) {
		if (top == array.length - 1) {
			System.out.println("Overflow!..");
			return;
		}
		
		
		array[++top] = v;

	}

	int pop() {
		if (top == -1) {
			System.out.println("UNDERFLOW..");

		}
		int k = array[top--];
	
		return k;

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
		StackReverseNumbers s=new StackReverseNumbers();
		System.out.println("Enter elements to reverse :");
		for (int i = 0; i < array.length; i++) {
			int k=scanner.nextInt();
			s.push(k);
		}

		System.out.println("Reverse :");

		for (int i = 0; i < array.length; i++) {
			System.out.print(s.pop() + " ");
		}

	}

}
