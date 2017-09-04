import java.util.ArrayList;
import java.util.List;
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
        int[][] mat = new int[4][4];
        while(T-- > 0) {
            for(int i=0; i<4; ++i) {
                for(int j=0; j<4; ++j) {
                    mat[i][j] = in.nextInt();
                }
            }
            if(!judgePoint(mat)) {
                System.out.println("NO");
                continue;
            }
            if(!judgeRect(mat))
                System.out.println("NO");
            else System.out.println("YES");
        }
        in.close();
    }

    public static boolean judgePoint(int[][] mat) {
        List<String> points = new ArrayList<String>();
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; j+=2) {
                String point = String.valueOf(mat[i][j]) + "," + String.valueOf(mat[i][j+1]);
                if(!points.contains(point)) {
                    points.add(point);
                }
            }
        }
        return (points.size() == 4);
    }

    public static boolean judgeRect(int[][] mat) {
        for(int i=1; i<4; ++i) {
            //判断是否垂直
            if((mat[0][1]-mat[0][3])*(mat[i][1]-mat[i][3]) == -(mat[0][0]-mat[0][2])*(mat[i][0]-mat[i][2])){
                continue;
            }
            //判断是否平行
            if((mat[0][1]-mat[0][3])*(mat[i][0]-mat[i][2]) == (mat[0][0]-mat[0][2])*(mat[i][1]-mat[i][3])) {
                continue;
            }
            return false;
        }
        return true;
    }
}