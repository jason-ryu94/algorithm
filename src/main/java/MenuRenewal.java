import java.util.*;

public class MenuRenewal {

    public String[] solution(String[] orders, int[] course) {
        String[] answer = {};

        Map<String, Integer> map = new HashMap<>();

        for(String s : orders) {
            for(int i : course) {
                if(s.length() < i) continue;

            }
        }

        return answer;
    }

    public void sol(String temp, int l) {
        for(int i = 0; i < temp.length(); i++) {
            if((temp.length() - i) < l) break;

        }
    }
}
