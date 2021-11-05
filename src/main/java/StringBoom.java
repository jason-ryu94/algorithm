import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.management.BufferPoolMXBean;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class StringBoom {


    static class Node{
        int idx;
        int val;

        public Node(int idx, int val) {
            this.idx = idx;
            this.val = val;
        }
    }

    public static void main(String[] args) throws IOException {


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String SL = br.readLine();
        String ST = br.readLine();

        int[] arr = new int[SL.length()];

        Node[] list = new Node[SL.length()];
        for(int i = 0; i < SL.length(); i++) {
            arr[i] = -1;
            for(int j = 0; j < ST.length(); j++) {
                if(SL.charAt(i) == ST.charAt(j)) {

                    arr[i] = j;
                }
            }
        }

        Stack<Integer> s = new Stack<>();
        Stack<Node> ss = new Stack<>();
        boolean[] tt = new boolean[arr.length];
        for(int i = 0; i < arr.length; i++) {
            if(i == 7) {
                int k = 0;
            }
            if(arr[i] == -1) {
                s.clear();
                ss.clear();
                continue;
            }
            if(arr[i] == 0) {
                s.push(arr[i]);
                ss.push(new Node(i, arr[i]));
                tt[i] = true;
                continue;
            }
            if(!s.empty() && ((s.peek()+1) == arr[i])) {
                s.push(arr[i]);
                ss.push(new Node(i, arr[i]));
                if(arr[i] == ST.length() -1) {
                    for(int j = 0; j < ST.length(); j++) {
                        s.pop();
                        Node temp = ss.pop();
                        tt[temp.idx] = true;
                    }
                }

            }
        }
        for(int i = 0; i < tt.length; i++) {
        }

        String answer = "";
        StringBuilder sb = new StringBuilder(answer);

        for(int i = 0; i < SL.length(); i++) {
            if(tt[i]) {
                continue;
            }else {
                sb.append(SL.charAt(i));
            }
        }
        if(sb.length() == 0) {
            System.out.println("FRULA");
        }else {
            System.out.println(sb);
        }



    }
}
