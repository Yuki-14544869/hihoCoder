import java.util.Scanner;

public class Main {
    /*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
    */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while(T-- > 0) {
            StringBuffer input = new StringBuffer(in.next());
            int ans = 0;
            int len = input.length();
            for(int i=0; i<len; ++i) {
                for(char ch='A'; ch<='C'; ++ch) {
                    StringBuffer tmp = new StringBuffer(input);
                    tmp = tmp.insert(i, ch);
                    ans = Math.max(ans, cal(tmp));
                }
            }
            System.out.println(ans);
        }
        in.close();
    }
    public static int cal(StringBuffer string) {
        int len = string.length();
        if(len<=0)
            return 0;
        StringBuffer buffer = new StringBuffer("");
        int l = 0;
        string.append("*");
        for(int i=1; i<len+1; ++i) {
            if(string.charAt(i) != string.charAt(i-1)) {
                if(l == i-1) {
                    buffer.append(string.charAt(i-1));
                }
                l = i;
            }
        }
        if (buffer.length() == len) {
            return 0;
        }
        return len-buffer.length()+cal(buffer);
    }
}
