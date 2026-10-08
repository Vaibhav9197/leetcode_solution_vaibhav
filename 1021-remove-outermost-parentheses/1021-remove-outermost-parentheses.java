class Solution {
    public String removeOuterParentheses(String s) {

        int count = 0;
      
        StringBuilder st = new StringBuilder();

        for(int i=0 ; i<s.length();i++)
        {
            char ch = s.charAt(i);
            if(ch == '(') count++;
            else if(ch ==')') count--;
            if(count > 1 && ch == '(') st.append(ch);
            else if(count >=1 && ch == ')')  st.append(ch);
        }

        return st.toString();
        
    }
}