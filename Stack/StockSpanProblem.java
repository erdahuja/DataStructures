package Stack;

import java.util.Scanner;

public class StockSpanProblem {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n;
		n = scanner.nextInt();
		int[] array = new int[n];
		for (int i = 0; i < n; i++)
			array[i] = scanner.nextInt();

		int[] stock = new int[n];
		stock[0] = 1;

		for (int j = 1; j < n; j++) {
			
			stock[j]=1;
			for (int i=j;array[j - i] <= array[j]&&i<j;i--) {
				stock[j]++;
				
			}
			

		}
		for (int i = 0; i < n; i++)
			System.out.println(stock[i]);

	}

}
