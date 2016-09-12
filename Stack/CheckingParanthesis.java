package Stack;

import java.util.Scanner;

public class CheckingParanthesis {
	static char[] array = new char[10];
	static int top = -1;
	static Scanner scanner = new Scanner(System.in);

	void push(char v) {
		System.out.println("pushed :" + v);

		array[++top] = v;
		System.out.println("array[top] : " + array[top]);

	}

	void pop(char v) {
		if (isPair(array[top], v)) {
			System.out.println("popped :" + v);
			top = top - 1;
			if (!(top == -1))
				System.out.println("array[top] : " + array[top]);

		} else {
			System.out.println("unbalanced...");
			System.exit(0);
		}
	}

	boolean isPair(char a, char b) {
		System.out.println("Comparing :" + a + " and " + b);
		switch (a) {

		case '{':
			System.out.println("paired with " + '{');
			return a == b;

		case '[':
			System.out.println("paired with " + '[');

			return a == b;

		case '(':
			System.out.println("paired with " + '(');

			return a == b;

		default:
			return false;
		}

	}

	public static void main(String[] args) {

		System.out.println("enter input stream of brackets..");
		String brackets = scanner.nextLine();
		CheckingParanthesis cc = new CheckingParanthesis();
		for (int i = 0; i < brackets.length(); i++) {
			char v = brackets.charAt(i);
			if (v == '(' || v == '{' || v == '[')
				cc.push(v);
			else
				cc.pop(v);
		}

		if (cc.top == -1)
			System.out.println("balanced..");
		else
			System.out.println("unbalanced..");

	}

}
