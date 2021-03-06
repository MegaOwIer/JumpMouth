/*题目描述:津津如果一天上课超过八个小时就会不高兴，而且上得越久就会越不高兴。假设津津不会因为其它事不高兴，并且她的不高兴不会持续到第二天。
           请你帮忙检查一下津津的日程安排，看看下周她会不会不高兴；如果会的话，哪天最不高兴。
  输入描述:输入包括七行数据，分别表示周一到周日的日程安排。每行包括两个小于10的非负整数，用空格隔开，分别表示津津在学校上课的时间和妈妈安排她上课的时间。
  输出描述:输出包括一行，这一行只包含一个数字。如果不会不高兴则输出0，如果会则输出最不高兴的是周几(用1, 2, 3, 4, 5, 6, 7分别表示周一，周二，周三，周四，周五，周六，周日)。
           如果有两天或两天以上不高兴的程度相当，则输出时间最靠前的一天。
  样例输入:5 3
           6 2
		   7 2
		   5 3
		   5 4
		   0 4
		   0 6
  样例输出:3*/

#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int a[2],i,n[7],p=0;
	for(i=0;i<=6;i++)
	{
		cin>>a[0]>>a[1];
		if(a[0]+a[1]<=8)  n[i]=0;
		else n[i]=a[0]+a[1]-8;
	}
	for(i=1;i<=6;i++)
	{
		if(n[0]<n[i])  p=i,n[0]=n[i];
	}
	if(p==0)  cout<<p;
    else  cout<<p+1;
	
	return 0;
}
 
