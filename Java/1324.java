import java.util.Scanner;

public class Main {
    /*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
    */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();

        System.out.println(HilbertNumber(n, x, y));
        in.close();
    }
    public static long HilbertNumber(int n, int x, int y) {
        if(n==0)
            return 1;
        int m = 1<<(n-1);

        if(x<=m) {
            if(y<=m)
                return HilbertNumber(n-1, y, x);
            else
                return 1L*m*m + HilbertNumber(n-1, x, y-m);
        } else {
            if(y>m)
                return 2L*m*m + HilbertNumber(n-1, x-m, y-m);
            else
                return 3L*m*m + HilbertNumber(n-1, m+1-y, 2*m+1-x);
        }
    }
}
