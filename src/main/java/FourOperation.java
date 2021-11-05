import java.util.*;
public class FourOperation {


    public int solution(String arr[]) {
        int answer = -1;

        int num_count = arr.length/2 + 1;
        int oper_count = num_count -1;
        // 0 은 최댓값 1은 최솟값
        int[][][] dp = new int[num_count][num_count][2];
        for(int i = 0; i < num_count; i++) {
            dp[i][i][0] = Integer.parseInt(arr[i*2]);
        }


        for(int i = 2; i < num_count; i++) {
        }

        return answer;
    }

}
