import java.util.Scanner;

/*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
*/
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while(T-- > 0) {
            char[] list = in.next().toCharArray();
            int l = list.length;
            int cnt0, cnt1;
            int ans = 0x3f3f3f3f;
            for(int i=0; i<=l; ++i) {
                cnt0 = cnt1 = 0;
                for(int j=i-1; j>=0; --j) {
                    if(list[j] == '0')
                        cnt0 += 0;
                    else cnt0 += 1;
                }
                for(int j=i; j<l; ++j) {
                    if(list[j] == '1')
                        cnt1 += 0;
                    else cnt1 += 1;
                }
                if(ans > cnt0+cnt1)
                    ans = cnt0+cnt1;
            }
            System.out.println(ans);
        }
        in.close();
    }
}
