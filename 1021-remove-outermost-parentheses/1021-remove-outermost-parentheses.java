class Solution {
    public String removeOuterParentheses(String s) {

        int count = 0;
      
        StringBuilder st = new StringBuilder();

        for(int i=0 ; i<s.length();i++)
        {
            char ch = s.charAt(i);
            if(ch == '(') {
                count++;
                if(count > 1)
                st.append(ch);
                
            }
            else if(ch ==')')  {
                if(count == 1){}
                else
                st.append(ch);
                count--;
            }
           
        }

        return st.toString();
        
    }
}