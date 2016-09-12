package Stack;

import java.util.Scanner;

public class InfixToPostFix {

	static char[] postfix = new char[100];
	static char[] array = new char[100];
	static int top1 = -1;
	static int top2 = -1;
	static Scanner scanner = new Scanner(System.in);

	static void pushToP(char v) {
		System.out.println("added to postfix exp :" + v);
		postfix[++top1] = v;

	}

	static void push(char v) {

		if (top2 != -1) {

			/*
			 * if (v == '(' || v == '{' || v == '[') {
			 * 
			 * array[++top2] = v;
			 * 
			 * } else if (v == '+' || v == '-' || v == '*' || v == '/') {
			 */
			if (v == ')') {
				while (top2 != -1 && array[top2] != '(' || array[top2] != '{' || array[top2] != '[') {

					if (array[top2] == '(') {

						char k = pop();
						System.out.println("popped :" + k);
						if (top2 == -1) {
							break;
						}

					} else {
						char k = pop();
						System.out.println("popped :" + k);
						if (top2 == -1) {
							break;
						}
						pushToP(k);

					}
				}
			} else {
				while (top2 != -1 && precedence(array[top2]) >= precedence(v)) {
					pushToP(array[top2]);
					pop();
				}

				System.out.println("added to stack " + v);
				array[++top2] = v;
				System.out.println("top of stack :" + top2);
			}
		}

		else {
			System.out.println("added to stack :" + v);
			array[++top2] = v;
		}
	}

	static char pop() {
		char k;
		k = array[top2--];
		System.out.println("top of stack is " + top2);
		return k;

	}

	static int precedence(char symbol) {
		int result = 0;
		switch (symbol) {
		case '(':
			result = 0;
			break;

		case '+':
			result = 1;
			break;
		case '-':
			result = 1;
			break;
		case '*':
			result = 2;
			break;
		case '/':
			result = 2;
			break;
		}
		return result;
	}

	public static void main(String[] args) {

		System.out.println("enter the string...");
		String string = scanner.nextLine();
		for (int i = 0; i < string.length(); i++) {

			char c = string.charAt(i);
			System.out.println("character :" + c);
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'z') {
				pushToP(c);

			} else {

				push(c);

			}
		}

		while (top2 != -1) {
			pushToP(array[top2]);
			top2--;
		}
		System.out.println("postfix :");
		for (int i = 0; i < postfix.length; i++)
			System.out.print(postfix[i] + " ");

	}

}
