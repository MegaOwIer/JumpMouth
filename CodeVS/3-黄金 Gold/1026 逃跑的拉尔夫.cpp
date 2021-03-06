/*题目描述:拉尔夫从小镇上偷走了一辆车,他没想到车上装有用于发射车子移动路线的装置,但那个装置太旧了,只能发射关于那辆车的移动方向的信息
		   编写程序,通过使用一张小镇的地图帮助警察局找到那辆车.程序必须能表示出该车最终所有可能的位置
		   小镇的地图是矩形的,上面的符号用来标明哪儿可以行车哪儿不行."."表示小镇上那块地方是可以行车的,而符号"X"表示此处不能行车
		   拉尔夫所开小车的初始位置用字符的"*"表示,且汽车能从初始位置通过
		   汽车能向四个方向移动:向北(向上),向南(向下),向西(向左),向东(向右)
		   拉尔夫所开小车的行动路线是通过一组给定的方向来描述的.在每个给定的方向,拉尔夫驾驶小车通过小镇上一个或更多的可行车地点
  输入描述:第一行包含两个用空格隔开的自然数R和C,1≤R≤50,1≤C≤50,分别表示小镇地图中的行数和列数
           以下的R行中每行都包含一组C个符号("."或"X"或"*")用来描述地图上相应的部位
		   接下来的第R+2行包含一个自然数N,1≤N≤1000,表示一组方向的长度
		   接下来的N行幅行包含下述单词中的任一个:NORTH(北),SOUTH(南),WEST(西)和EAST(东),表示汽车移动的方向,任何两个连续的方向都不相同
  输出描述:输出文件应包含用R行表示的小镇的地图(像输入文件中一样)，字符"*"应该仅用来表示汽车最终可能出现的位置
  样例输入:4 5
           .....
		   .X...
		   ...*X
		   X.X..
		   3
		   NORTH
		   WEST
		   SOUTH
  样例输出:.....
           *X*..
		   *.*.X
		   X.X..  */

#include<iostream>
#include<cstring>
using namespace std;

char a[100][100];
int m,n,p,xx,yy,dx[]={0,-1,0,1,0},dy[]={0,0,1,0,-1},cnt,g[100][100],ord;
string st[10000];

int main()
{
	cin>>m>>n;
	for(int i=0;i<100;i++)  for(int j=0;j<100;j++)  g[i][j]=-1;
	for(int i=1;i<=m;i++)  for(int j=1;j<=n;j++)  {cin>>a[i][j];  if(a[i][j]=='*')  {xx=i;  yy=j;  g[i][j]=0;}}
	cin>>p;
	for(int i=1;i<=p;i++)  cin>>st[i];
	for(int i=1;i<=p;i++)
	{
		if(st[i][0]=='N')  ord=1;
		if(st[i][0]=='E')  ord=2;
		if(st[i][0]=='S')  ord=3;
		if(st[i][0]=='W')  ord=4;
		for(int i=1;i<=m;i++)  for(int j=1;j<=n;j++)  if(g[i][j]==cnt) 
		{
			xx=i;yy=j;
		    while(a[xx][yy]!='X'&&xx&&yy&&xx<=m&&yy<=n)
		    {
			    xx+=dx[ord];
			    yy+=dy[ord];
			    g[xx][yy]=cnt+1;
		    }
	    	g[xx][yy]=-1;
	    }
	    cnt++;
	}
	for(int i=1;i<=m;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
		    if(a[i][j]=='X')  {cout<<"X";  continue;}
	    	if(g[i][j]==cnt)  {cout<<"*";  continue;}
	        cout<<".";
	    }
	    cout<<endl;
	}
	return 0;
}
