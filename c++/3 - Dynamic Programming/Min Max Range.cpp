Devuelve el el minimo de los maximos entre pares de rangos consecutivos haciendo cortes en el Array.

const int MAX = 1005;
long long dp[MAX][MAX];
long long sum_ran[MAX][MAX];
int N;

long long f(int i, int cuts){
	if(cuts == 0) return sum_ran[i][N-1];
	if(i == N) return 0;
	long long &ans = dp[i][cuts];
	if(ans != - 1) return ans;
	for(int j = i; j < N; j++){
		ans = min(ans, max(sum_ran[i][j], f(i + 1, cuts - 1)));
	}
}
