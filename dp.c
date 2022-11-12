#include <stdio.h>

int max(int a, int b) {
    return a >= b ? a : b;
}

int main() {
    int arr[] = {2,7,9,3,1}, size = 5, result;
    int dp[5];

    dp[0] = arr[0];
    for (int i = 1; i < 5; ++i) {
        dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
    }
    for (int j = 0; j < 5; ++j) {
        printf("%d\t", dp[j] );
    }


}