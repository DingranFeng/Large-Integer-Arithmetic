#include<stdio.h>
#include<string.h>
#define N 200

int main()
{ 
	int SubStract(int *p1,int *p2,int len1,int len2);
	int add(int *a,int *b,int l1,int l2); 
	int sub(int *a,int *b,int l1,int l2); 
	int mul(int *a,int *b,int l1,int l2); 
	int div(int *a,int *b,int l1,int l2);
	
	long i,j;
	unsigned long len1,len2;
	int A[N],B[N];
	char str1[N],str2[N],op;
	
	scanf("%s",&op);
	scanf("%s %s",str1,str2);
	len1=strlen(str1); 
	len2=strlen(str2);
	for(j=0,i=len1-1;i>=0;j++,i--) A[j]=str1[i]-'0'; 
	for(j=0,i=len2-1;i>=0;j++,i--) B[j]=str2[i]-'0';
	switch(op)
	{
	case '+':add(A,B,len1,len2);break;
	case '-':sub(A,B,len1,len2);break;
	case '*':mul(A,B,len1,len2);break;
	case '/':div(A,B,len1,len2);break;
	default:printf("illegal");break;
	}
	return 0;
}

int add(int *a,int *b,int l1,int l2) 
{
	int m,len,i,ans[N]={0}; 
	if(l1>l2) len=l1; else len=l2; 
	for(m=0;m<len;m++) ans[m]=a[m]+b[m];
	for(m=0;m<len;m++) if(ans[m]>9) 
	{
	ans[m]%=10;
	ans[m+1]++;
	}
	if(ans[len]>0) len++;
	for(i=N-1;ans[i]==0&&i>=0;i--);
	if(i>=0) for(;i>=0;i--) printf("%d",ans[i]);
	else printf("0");
	printf("\n");
	return 0;
}

int sub(int *a,int *b,int l1,int l2)
{
	int m,flag=0,len,ans[N]={0},i; 
	if(l1>l2) len=l1; else len=l2; 
	if(l1==l2) 
	{
	flag=1; 
	for(m=l1-1;m>=0;m--)
	if(a[m]<b[m]) {flag=0;break;} 
	}
	if(l1>l2||(l1==l2&&flag==1)) for(m=0;m<len;m++) ans[m]=a[m]-b[m]; 
	else if(l1<l2||(l1==l2&&flag==0)) {printf("-");for(m=0;m<len;m++) ans[m]=b[m]-a[m];}
	for(m=0;m<len;m++) if(ans[m]<0) 
	{
	ans[m]+=10;
	ans[m+1]--;
	}
	for(i=N-1;ans[i]==0&&i>=0;i--);
	if(i>=0) for(;i>=0;i--) printf("%d",ans[i]);
	else printf("0");
	printf("\n");
	return 0;
}

int mul(int *a,int *b,int l1,int l2)
{
	int m,n,len,ans[N]={0},i;
	len=l1+l2; 
	for(m=0;m<l2;m++)
	for(n=0;n<l1;n++) ans[n+m]+=b[m]*a[n]; 
	for(m=0;m<len;m++) 
	if(ans[m]>9)
	{
	ans[m+1]+=ans[m]/10;
	ans[m]%=10;
	}
	for(i=N-1;ans[i]==0&&i>=0;i--);
	if(i>=0) for(;i>=0;i--) printf("%d",ans[i]);
	else printf("0");
	printf("\n");
	return 0;
}

int SubStract(int *p1,int *p2,int l1,int l2)
{
	int i;
	if(l1<l2) return -1;
	if(l1==l2)
	{	
	for(i=l1-1;i>=0;i--)
	{
	if(p1[i]>p2[i]) break;
	else if(p1[i]<p2[i]) return -1;
	}
	}
	for(i=0;i<=l1-1;i++) 
	{
	p1[i]-=p2[i];
	if(p1[i]<0) 
	{
	p1[i]+=10;
	p1[i+1]--;
	}
	}
	for(i=l1-1;i>=0;i--)
	if(p1[i]) return(i+1); 
	return 0;
}

int div(int *a,int *b,int l1,int l2)
{
	long i,j,nTemp;
	unsigned long nTimes;
	int ans[N]={0};
	if(l1<l2) {printf("0\n");return 0;}
	nTimes=l1-l2; 
	for(i=l1-1;i>=0;i--) 
	{
	if(i>=nTimes) b[i]=b[i-nTimes];
	else b[i]=0;
	}
	l2=l1;
	for(j=0;j<=nTimes;j++) 
	{
	while((nTemp=SubStract(a,b+j,l1,l2-j))>=0)
	{
	l1=nTemp; 
	ans[nTimes-j]++;
	}
	}
	for(i=N-1;ans[i]==0&&i>=0;i--);
	if(i>=0) for(;i>=0;i--) printf("%d",ans[i]);
	else printf("0");
	printf("\n");
	return 0;
}
