/*题目描述:某校大门外长度为L的马路上有一排树。我们把马路看成一个数轴，马路的一端在数轴0的位置，另一端在L的位置；数轴上的每个整数点都种有一棵树。
           马路上有一些区域要用来建地铁。已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域中（包括区域端点处）的树移走。
		   你的任务是计算将这些树都移走后，马路上还有多少棵树。
  输入描述:输入第一行有两个整数L（1<=L<=10000）和M（1<=M<=100），L代表马路的长度，M代表区域的数目，L和M之间用一个空格隔开。
           接下来的M行每行包含两个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。
  输出描述:输出包括一行，这一行只包含一个整数，表示马路上剩余的树的数目。
  样例输入:500 3
           150 300
		   100 200
		   470 471
  样例输出:298*/

#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int L,M,a=0,b=0,n[10001],i,j,p=0;

int main()
{
	cin>>L>>M;
	for(i=0;i<=L;i++)   n[i]=i;
	for(i=1;i<=M;i++)
	{
		cin>>a>>b;
		for(j=a;j<=b;j++)  n[j]=-1;
	}
	for(i=0;i<=L;i++)  if(n[i]!=-1) p++;
	cout<<p;
	
	return 0;
}
