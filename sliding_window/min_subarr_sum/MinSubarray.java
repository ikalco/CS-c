import java.util.*;

public class MinSubarray {
	public static int solve(int[] nums, int target) {
		int min_len = Integer.MAX_VALUE;
		int start = 0;
		int end = 0;

		int sum = 0;
		for (end = 0; end < nums.length; end++) {
			int num = nums[end];
			sum += num;

			while (sum >= target) {
				if (end - start + 1 < min_len)
					min_len = end - start + 1;
				sum -= nums[start];
				start++;
			}
		}

		if (min_len == Integer.MAX_VALUE)
			return 0;

		return min_len;
	}

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);

		int n = kb.nextInt();
		kb.nextLine();

		for (int i = 0; i < n; i++) {
			int target = kb.nextInt();
			kb.nextLine();
			int[] nums = Arrays.stream(kb.nextLine().split(",")).mapToInt(Integer::parseInt).toArray();
			int sol = solve(nums, target);
			System.out.println(sol);
		}
	}
}
