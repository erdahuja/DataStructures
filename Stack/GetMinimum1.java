package Stack;

import java.util.Scanner;

public class GetMinimum1 {
	static int top = -1;
	static int[] stack = new int[5];
	static int[] minstack = new int[5];
	static Scanner scanner = new Scanner(System.in);
	static int min = 0;

	static void push(int x) {

		minstack[++top] = x;
	}

	public static void main(String[] args) {
		for (int i = 0; i < stack.length; i++) {
			stack[i] = scanner.nextInt();

			if (i == 0) {
				min = stack[i];
				push(min);
				System.out.println("added to minstack :" + stack[i]);
			}

			else {
				if (stack[i] < minstack[top]) {
					min = stack[i];
					push(min);
				} else
					push(min);
			}
		}
		for (int i = 0; i < 5; i++) {
			System.out.println("min stack is :" + minstack[i]);
			System.out.println("\t" + "stack is :" + stack[i]);

		}
		System.out.println("min is :" + minstack[top]);

	}

}
