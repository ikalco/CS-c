import java.util.*;

public class TwoSum {
	public static int[] solve(int[] nums, int target) {
		int left = 0;
		int right = nums.length - 1;

		int sum = nums[left] + nums[right];

		while (left < right && sum != target) {
			if (sum > target)
				right--;
			if (sum < target)
				left++;

			sum = nums[left] + nums[right];
		}

		return new int[] { left + 1, right + 1 };
	}

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);

		int n = kb.nextInt();
		kb.nextLine();

		for (int i = 0; i < n; i++) {
			int target = kb.nextInt();
			kb.nextLine();
			int[] nums = Arrays.stream(kb.nextLine().split(",")).mapToInt(Integer::parseInt).toArray();
			int[] sol = solve(nums, target);
			System.out.println(Arrays.toString(sol));
		}
	}
}
