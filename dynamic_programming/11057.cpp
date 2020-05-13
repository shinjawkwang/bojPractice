/*
 * 11057. 오르막 수
 * 오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.
 * 예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.
 * 수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.
 *
 * 첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.
 *
 * 첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.
 *
 * Silver 1
 */
#include <stdio.h>

long long dp[1001][10];
int n;

int main() {
    scanf("%d", &n);
    dp[1][0]=1; dp[1][1]=1; dp[1][2]=1; dp[1][3]=1; dp[1][4]=1;
    dp[1][5]=1; dp[1][6]=1; dp[1][7]=1; dp[1][8]=1; dp[1][9]=1;
    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
            for(int k=j; k>=0; k--)
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % 10007;
        }
    }
    printf("%lld\n", (dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4]+dp[n][5]+dp[n][6]+dp[n][7]+dp[n][8]+dp[n][9]) % 10007);
    return 0;
}