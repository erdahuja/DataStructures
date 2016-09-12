package Stack;

import java.util.Scanner;

public class DecimalToBinaryStack {
	int array[] = new int[10];
	int top = -1;
	static Scanner scanner = new Scanner(System.in);

	void push(int v) {
		array[++top] = v;
	}

	int pop() {

		return array[top--];
	}

	public static void main(String[] args) {

		DecimalToBinaryStack s = new DecimalToBinaryStack();
		System.out.println("Enter number :");
		int num = scanner.nextInt();
		while(num!=0){
			int d=num%2;
			s.push(d);
			num=num/2;
		}
		
		System.out.println("binary is :");
		while(s.top!=-1){
			System.out.print(s.pop()+" ");
		}
		
	}

}
