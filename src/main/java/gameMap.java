import java.util.*;

public class gameMap {

    public static void main(String[] args) {
        int[] cc = new int[4];
        for(int i = 0; i < 2; i++) {
            System.out.println(cc[i]);
        }
        int[][] test = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};

        System.out.println(solution(test));
    }





        public static int solution(int[][] maps) {
            int answer = 0;
            class P{
                int x;
                int y;
                P(int x, int y) {
                    this.x = x;
                    this.y = y;
                }
            }
            int dx[] = {0, 0, 1, -1};

            int dy[] = {1, -1, 0, 0};
            int n = maps.length;
            int m = maps[0].length;
            int[][] chk = new int[n][m];

            Queue<P> q = new LinkedList<>();

            chk[0][0] = 1;


            q.add(new P(0, 0));

            while(!q.isEmpty()) {
                P now = q.poll();
                for(int i = 0; i < 4; i++) {
                    int nx = now.x + dx[i];
                    int ny = now.y + dy[i];
                    if(nx <0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(maps[nx][ny] == 0) continue;
                    if(chk[nx][ny] != 0) continue;
                    chk[nx][ny] = chk[now.x][now.y] + 1;
                    q.add(new P(nx, ny));
                    if(nx == n-1 && ny == m-1) {
                        answer = chk[nx][ny];
                        break;
                    }
                }
                if(answer != 0) break;
            }
            if(answer == 0) answer = -1;


            return answer;

        }



}
