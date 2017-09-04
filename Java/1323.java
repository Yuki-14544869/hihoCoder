import java.util.Scanner;


public class Main {
    /*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
    */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        char[] s = in.next().toCharArray();
        int dp[][] = new int[1005][1005];
        int len = s.length;
        for(int i=len-1; i>=0; --i) {
            for(int j=i+1; j<len; ++j) {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = Math.min(dp[i+1][j], Math.min(dp[i][j-1], dp[i+1][j-1]) ) + 1;
            }
        }
        System.out.println(dp[0][len-1]);
        in.close();
    }
}
