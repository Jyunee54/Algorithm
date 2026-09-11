import java.util.*;

class Solution {
    boolean found = false;
    Deque<String> que = new ArrayDeque<>();
    Map<String, List<Integer>> map = new HashMap<>();
    boolean[] used;
    String[][] tickets;
    
    public String[] solution(String[][] tickets) {
        used = new boolean[tickets.length];
        this.tickets = tickets;
        
        Arrays.sort(tickets, 
                    Comparator.comparing((String[] a) -> a[0])
                    .thenComparing(a -> a[1])
        );
        
        for (int i=0; i<tickets.length; i++) {
            map.computeIfAbsent(tickets[i][0], k -> new ArrayList<>()).add(i);
        }
        
        for (int i=0; i<tickets.length; i++) {
            if (tickets[i][0].equals("ICN")) {
                used[i] = true;
                que.offer(tickets[i][0]);
                que.offer(tickets[i][1]);
                dfs(1);
                if (found) break;
                que.pollLast();
                que.pollLast();
                used[i] = false;
            }
        }
        
        String[] answer = new String[que.size()];
        int index = 0;
        
        while (!que.isEmpty()) {
            String airport = que.poll();
            
            answer[index] = airport;
            index++;
        }
        
        return answer;
    }
    
    private void dfs(int count) {
        if (found) return;
        
        if (count == tickets.length) {
            found = true;
            return;
        }
        
        String current = que.peekLast();
        
        if (!map.containsKey(current)) {
            return;
        }
        
        for (int i : map.get(current)) {
            if (used[i]) continue;
            
            used[i] = true;
            que.offerLast(tickets[i][1]);
            
            dfs(count + 1);
            if (found) return;
            
            que.pollLast();
            used[i] = false;
        }
    }
}