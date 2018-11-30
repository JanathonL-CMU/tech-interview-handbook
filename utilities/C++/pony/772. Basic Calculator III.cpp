772. Basic Calculator III
Hard
136
43


Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

Note: Do not use the eval built-in library function.

class Solution {
public:
    /*
    pre_sum, pre_op
    for (c : s){
        if(c == '('){
            find match right and cal calculate recursively
        } else if c is digit{
            num = num*10 + c-'0';
        } else {
            update_presum
            if(c=='+'||c=='-'){
                sum += pre_sum
                pre_sum = 0;
            }
            num = 0;
            pre_op = c;
        }
    }
    sum += pre_sum;
    return sum;
    */
    bool is_digit(char c){
        if(c>='0' && c<='9'){
            return true;
        } else {
            return false;
        }
    }
    void update_presum(int& pre_sum, char pre_op, int num){
        switch(pre_op){
            case '+': pre_sum += num;
                return;
            case '-': pre_sum -= num;
                return;
            case '*': pre_sum *= num;
                return;
            case '/': pre_sum /= num;  // assume num != 0
                return;
                
        }
    }
    bool is_op(char c){
        if(c=='-' || c=='+' || c=='*' || c=='/'){
            return true;
        } else {
            return false;
        }
        
    }
    int calculate(string s) {
        int pre_sum = 0;
        char pre_op = '+';
        int num = 0;
        int res = 0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c=='('){
                int left = 0;
                int right = 0;
                int index = i;
                for(index=i;index<s.size();index++){
                    if(s[index]=='('){
                        left++;
                    } else if(s[index]==')'){
                        left--;
                        if(left==0){
                            break;
                        }
                    }
                }
                num = calculate(s.substr(i+1, index-i-1));
                i = index;
            } else if(is_digit(c)){
                num = num*10 + c-'0';
            } else if(is_op(c)) {
                char op = c;
                update_presum(pre_sum, pre_op, num);
                if(op=='+'||op=='-'){
                    res += pre_sum;
                    pre_sum = 0;
                }
                pre_op = op;
                num = 0;
            }
        }
        update_presum(pre_sum, pre_op, num);
        res += pre_sum;
        return res;
    }
};
// two stacks 
// class Solution {
// public:
//     int calculate(string s) {
//         if(s.size()==0) return 0;
//         stack<int> nums;
//         stack<char> ops;
//         int num = 0;
//         for(int i=0;i<s.size();i++){
//             char c = s[i];
//             if(c==' ') continue;
//             if(c>='0' && c<='9'){
//                 num = c-'0';
//                 while(i<s.size()-1 && s[i+1]>='0' && s[i+1]<='9'){
//                     num = num*10 + (s[i+1]-'0');
//                     i++;
//                 }
//                 nums.push(num);
//                 num = 0; // reset the number to 0 before next calculation
//             } else if(c== '('){
//                 ops.push(c);
//             } else if(c == ')'){
//                 while(ops.top()!='('){
//                     operation(ops,nums);
//                 }
//                 ops.pop(); // get rid of '(' in the ops stack
//             } else if(c=='+' || c=='-' || c=='*' || c=='/'){
//                 while(!ops.empty() && precedence(c, ops.top())){
//                     operation(ops,nums);
//                 }
//                 ops.push(c);
//             }
//         }
//         while(!ops.empty()){
//             operation(ops,nums);
//         }
//         return nums.top();
//     }
//     void operation(stack<char>& ops, stack<int>& nums){
//         int first = nums.top();
//         nums.pop();
//         int second = nums.top();
//         nums.pop();
//         char op = ops.top();
//         ops.pop();
//         nums.push(cal(op, first, second));
//     }
//     int cal(char op, int b, int a) {
//         switch (op) {
//             case '+': return a + b;
//             case '-': return a - b;
//             case '*': return a * b;
//             case '/': return a / b; // assume b is not 0
//         }
//         return 0;
//     }
//     bool precedence(char op1, char op2) { // cal precedence
//         if (op2 == '(' || op2 == ')') return false;
//         if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) return false;
//         return true;
//     }
// };

