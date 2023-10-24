#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char *s) {
    int max_length = 0;
    int n = strlen(s);
    int stack[n + 1];
    int top = -1;
    stack[++top] = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                max_length = max(max_length, i - stack[top]);
            }
        }
    }
    return max_length;
}

int main() {
    char s[] = "(()())";
    int result = longestValidParentheses(s);
    printf("Length of the longest valid parentheses substring: %d\n", result);
    return 0;
}
