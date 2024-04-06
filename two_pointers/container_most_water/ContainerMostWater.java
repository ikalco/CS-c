import java.util.*;

public class ContainerMostWater {
	public static int solve(int[] heights) {
		// most water in container

		int left = 0;
		int right = heights.length - 1;
		int max = 0;

		while (left < right) {
			max = Math.max(max, Math.min(heights[left], heights[right]) * (right - left));
			if (heights[left] >= heights[right]) {
				right--;
			} else {
				left++;
			}
		}

		return max;
	}

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);

		int n = kb.nextInt();
		kb.nextLine();

		for (int i = 0; i < n; i++) {
			int[] nums = Arrays.stream(kb.nextLine().split(",")).mapToInt(Integer::parseInt).toArray();
			int sol = solve(nums);
			System.out.println(sol);
		}
	}
}
