import java.util.*;

class Solution {
    private TreeMap<Integer, Integer> map;
    
    public int[] solution(String[] operations) {
        map = new TreeMap<>();
        
        for (String operation : operations) {
            String[] command = operation.split(" ");
            
            switch (command[0].charAt(0)) {
                case 'I' -> insert(Integer.parseInt(command[1]));
                case 'D' -> delete(Integer.parseInt(command[1]));
            }
        }
        
        if (map.isEmpty()) {
            return new int[] {0, 0};
        }
        
        return new int[] {map.lastKey(), map.firstKey()};
    }
    
    private void insert(int num) {
        map.put(num, map.getOrDefault(num, 0) + 1);
    }
    
    private void delete(int num) {
        if (map.isEmpty()) return;
        
        if (num == 1) {
            int max = map.lastKey();
            
            if (map.get(max) == 1) {
                map.remove(max);
            } else {
                map.put(max, map.get(max) - 1);
            }
        }
        
        if (num == -1) {
            int min = map.firstKey();
            
            if (map.get(min) == 1) {
                map.remove(min);
            } else {
                map.put(min, map.get(min) - 1);
            }
        }
        
        return;
    }
}