import java.util.*;

public class LongestSubstring {
	public static int solve(String str) {
		HashMap<Character, Boolean> map = new HashMap<Character, Boolean>();

		int start = 0;
		int end = 0;
		int max_len = 0;

		for (char c : str.toCharArray()) {
			if (map.get(c) == null || map.get(c) == false) {
				map.put(c, true);
				if (end - start + 1 > max_len)
					max_len = end - start + 1;
			} else {
				// c already in map

				while (map.get(c)) {
					map.put(str.charAt(start), false);
					start++;
				}

				map.put(c, true);
			}

			end++;
		}

		return max_len;
	}

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);

		int n = kb.nextInt();
		kb.nextLine();

		for (int i = 0; i < n; i++) {
			String str = kb.nextLine();
			int sol = solve(str);
			System.out.println(sol);
		}
	}
}
