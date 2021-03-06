/*题目描述:A 点有一个过河卒，需要走到目标 B 点。卒行走规则：可以向下、或者向右。
           同时在棋盘上的任一点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。卒不能通过对方马的控制点。
           棋盘用坐标表示，A 点（0，0）、B 点（n,m）(n,m 为不超过 20 的整数，并由键盘输入)，同样马的位置坐标是需要给出的。
		   现在要求你计算出卒从 A 点能够到达 B 点的路径的条数。1<=n,m<=15
  输入描述:B点的坐标（n,m）以及对方马的坐标（X,Y）{不用判错}
  输出描述:一个整数（路径的条数）。
  样例输入:6 6 3 2
  样例输出:17*/

#include<iostream>

using namespace std;

int m,n,x,y,g[20][20];
long long f[20][20];

int main()
{
	cin>>m>>n>>x>>y;
	g[x][y]=g[x-2][y+1]=g[x-2][y-1]=g[x-1][y+2]=g[x-1][y-2]=g[x+1][y+2]=g[x+1][y-2]=g[x+2][y-1]=g[x+2][y+1]=1;
	f[0][0]=1;
	for(int i=1;i<=m;i++)	if(g[i][0]==0)  f[i][0]=f[i-1][0];
	for(int i=1;i<=n;i++)	if(g[0][i]==0)  f[0][i]=f[0][i-1];
	for(int i=1;i<=m;i++)  for(int j=1;j<=n;j++)  if(g[i][j]==0)  f[i][j]=f[i-1][j]+f[i][j-1];
	cout<<f[m][n];
	
	return 0;
}
