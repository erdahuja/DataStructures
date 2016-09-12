package Stack;

import java.util.Scanner;

public class InfixToPrefix {

	static int top = -1;
	static int top2 = -1;
	static char[] stack = new char[100];
	static char[] postfix = new char[100];

	static void push(char c) {
		stack[++top] = c;

	}

	static char pop() {
		char k = stack[top--];
		return k;
	}

	static boolean isoperand(char a) {
		if (a >= 'a' && a <= 'z') {
			return true;
		} else
			return false;

	}

	static boolean isoperator(char a) {

		if (a == '+' || a == '-' || a == '/' || a == '*') {
			return true;
		} else
			return false;
	}

	static int precedence(char a) {
		int result = 0;
		switch (a) {
		case '(':
			result = 0;
			break;
		case '+':
		case '-':
			result = 1;
			break;
		case '*':
		case '/':
			result = 2;
			break;
		}
		return result;
	}

	static String reverse(char str[]) {
		int i, j, k;
		k = str.length;
		char t;
		for (i = 0, j = k - 1; i < k / 2; i++, j--) {
			t = str[i];
			str[i] = str[j];
			str[j] = t;
		}
		for (i = 0; i < str.length; i++) {
			if (str[i] == '(')
				str[i] = ')';
			else if (str[i] == ')')
				str[i] = '(';

		}
		return String.valueOf(str);

	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String string = scanner.nextLine();

		String string2 = reverse(string.toCharArray());

		System.out.println("Reverse is :");
		for (int i = 0; i < string2.length(); i++) {
			System.out.print(string2.charAt(i) + " ");
		}
		System.out.println();

		push('(');

		for (int i = 0; i < string2.length(); i++) {

			if (isoperand(string2.charAt(i))) {
				postfix[++top2] = string2.charAt(i);
			}

			if (string2.charAt(i) == '(')
				push('(');

			if (isoperator(string2.charAt(i))) {
				while (precedence(stack[top]) >= precedence(string2.charAt(i))) {

					postfix[++top2] = pop();
				}

				push(string2.charAt(i));
			}

			if (string2.charAt(i) == ')') {
				while (stack[top] != '(') {
					postfix[++top2] = pop();
				}
				pop();
			}

		}

		while (stack[top] != '(') {

			postfix[++top2] = pop();

		}

		System.out.println("postfix is :");
		for (char a : postfix) {
			if (a != '\0')
				System.out.print(a + " ");
		}
		System.out.println();

		String string3 = reverse(postfix);
		char b[] = string3.toCharArray();
		System.out.println("prefix is :");
		for (char a2 : b) {
			if (a2 != '\0')
				System.out.print(a2 + " ");
		} // TODO Auto-generated method stub

	}
}
