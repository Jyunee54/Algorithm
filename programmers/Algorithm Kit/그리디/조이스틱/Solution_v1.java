class Solution {
    public int solution(String name) {
        int length = name.length();
        
        int horizontalMove = length - 1;
        int verticalMove = 0;
        
        for (int i=0; i<length; i++) {
            verticalMove += calculate(name.charAt(i));
            
            int next = i + 1;
            while (next < length && name.charAt(next) == 'A') {
                next++;
            }
            
            int rightFirst = 2 * i + (length - next);
            int leftFirst = i + 2 * (length - next);
            
            horizontalMove = Math.min(horizontalMove, Math.min(rightFirst, leftFirst));
        }
        
        return verticalMove + horizontalMove;
    }
    
    private int calculate(char ch) {
        int up = ch - 'A';
        int down = 'Z' - ch + 1;
        
        return Math.min(up, down);
    }
}