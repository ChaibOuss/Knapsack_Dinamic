#include<stdlib.h>
#include<stdio.h>

#define MAX 1000

// Max between a and b, a and b are integers.
int max(int a, int b) {
	return (a > b) ? a : b;
}


int sacados(int M, int n, int value[], int weight[])
{
    int K[n+1][M+1];
    int j,i;
	for (i=0; i<=n; i++) {
		for (j=0; j<=M; j++) {
			if (i == 0 || j == 0) {
				K[i][j] = 0;
			} else if (weight[i-1] > j) {
				K[i][j] = K[i-1][j];
			} else {
				K[i][j] = max(value[i-1] + K[i-1][j - weight[i-1]], K[i-1][j]);
			}
		}

	}
	for (i = 0; i <= n; ++i)
	{
		for (j = 0; j <= M; ++j)
		{
			printf("%d\n", K[i][j]);
		}
	}
	int x[MAX];
	int c = n, w = M;
	for(i=0;i<=n;i++)
        x[i]=0;
	while(c>0 && w>0)
    {
        if (K[c][w]!= K[c-1][w]){
            x[c]= 1;
            w = w - weight[c];
        }else{
        	x[c] = 0;
        }
        c--;
    }
    for(j=1;j<=n;j++)
    {
        if(x[j]==1)
            {
                printf("object numero %d est dans le sac  ",j);
            }
    }

	return K[n][M];

}
int main()
{
    // value table
	int value[MAX] = {1,4,5,7};
	// weight table
	int weight[MAX] = {1,3,4,5};
	// maximum capacity
	int M = 99;
	// size of the table
	int n=4;
	// elements taken
	printf("%d\n", sacados(M, n, value, weight));


    return EXIT_SUCCESS;
}
