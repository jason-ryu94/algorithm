import java.util.Scanner;

public class RisingTrend {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);



        while(sc.hasNext()) {
            int answer = 0;
            int t = sc.nextInt();
            int cnt = 0;
            int len = 0;
            for(int i = 0; i < t; i++) {
                int tmp = sc.nextInt();
                if(cnt == 0) {
                    cnt = tmp;
                    len++;
                    continue;
                }
                if(cnt < tmp) {
                    len++;

                }else {
                    if(len >= answer) {
                        answer = len;
                    }
                    len = 1;
                }
                cnt = tmp;
            }
            System.out.println(answer);

        }
    }
}
