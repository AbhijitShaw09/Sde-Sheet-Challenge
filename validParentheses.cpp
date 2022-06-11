bool isValidParenthesis(string expression)
{
    // Write your code here.
    int n = expression.size();
    stack<char> st;
    bool ans = true;
    for(int i=0; i<n; i++){
        if(expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
            st.push(expression[i]);
        else if(expression[i] == ')'){
            if(!st.empty() && st.top() == '(')
                st.pop();
            else{
                ans = false;
                break;
            }
        }
        else if(expression[i] == ']'){
            if(!st.empty() && st.top() == '[')
                st.pop();
            else{
                ans = false;
                break;
            }
        }
        else if(expression[i] == '}'){
            if(!st.empty() && st.top() == '{')
                st.pop();
            else{
                ans = false;
                break;
            }
        }
    }
    if(!st.empty())
        return false;

    return ans;
}
