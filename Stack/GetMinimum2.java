package Stack;

import java.util.Scanner;

public class GetMinimum2 {
	static int top = -1;
	static int[] stack = new int[6];
	static int[] minstack = new int[6];
	static Scanner scanner = new Scanner(System.in);
	static int min = 0;

	static void push(int x) {

		minstack[++top] = x;
		System.out.println("added to minstack :" + x);
	}

	static void pop(int b) {

		System.out.println("popped :" + stack[b--]);

	}

	public static void main(String[] args) {
		for (int i = 0; i < stack.length; i++) {
			stack[i] = scanner.nextInt();

			if (i == 0) {
				min = stack[i];
				push(min);

			}

			else {
				if (min == stack[i]) {
					pop(i);
				} else if (stack[i] <= minstack[top]) {
					min = stack[i];
					push(min);
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			System.out.println("min stack is :" + minstack[i]);
			System.out.println("\t\t\t" + "stack is :" + stack[i]);

		}
		System.out.println("min is :" + minstack[top]);

	}

}
