#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int converttoint(char c) {
  return (int)(c - 48);
}

static char converttochar(int n) {
  return (char)(n + 48);
}

 
static char* removeZeros(char *a, int n) 
{ 
    int ind = -1; 
    for (int i = 0; i < n; i++) { 
        if (a[i] != '0') { 
            ind = i; 
            break; 
        } 
    } 
    if (ind == -1) { 
	strcpy(a,"0");
	return a;
    } 
char b[n-ind];
	int i=0;
    for (i = 0; i < n - ind; i++) 
        b[i] = a[ind + i]; 
b[i]='\0';
strcpy(a,b);
    return a;
} 

char* intal_add(char* intal1, char* intal2) {
  int len1 = strlen(intal1);
  int len2 = strlen(intal2);

  int r = (len1 > len2)? len1 + 1: len2 + 1;
  int s = (len1 > len2)? len2: len1;
  
  int i, d1, d2, rd, c = 0;
  char* result = (char*)malloc((r + 1) * sizeof(char));

  for(i = 0 ; i < s; ++i) {
    d1 = converttoint(intal1[len1 - 1 - i]);
    d2 = converttoint(intal2[len2 - 1 - i]);

    rd = d1 + d2 + c;
    c = (rd > 9)? 1: 0;
    rd = (rd > 9)? rd - 10: rd;

    result[r - 1 - i] = converttochar(rd);
  }

  while(i < r - 1) {
    if(len1 > len2) {
      rd = converttoint(intal1[len1 - 1 - i]) + c;
      c = (rd > 9)? 1: 0;
      rd = (rd > 9)? rd - 10: rd;

      result[r - 1 - i] = converttochar(rd);
    } else {
      rd = converttoint(intal2[len2 - 1 - i]) + c;
      c = (rd > 9)? 1: 0;
      rd = (rd > 9)? rd - 10: rd;

      result[r - 1 - i] = converttochar(rd);
    }

    ++i;
  }

  if(c != 0) {
    result[0] = converttochar(c);
    result[r] = '\0';
  } else {
    for(i = 0; i < r - 1; ++i) {
      result[i] = result[i + 1];
    }

    result = (char*)realloc(result, r * sizeof(char));
    result[r - 1] = '\0';
  }

  return result;
}




int intal_compare(const char* intal1, const char* intal2)
{
int p=strlen(intal1);
int q=strlen(intal2);
int x=0;
if(p>q)
	x=1;
if(p<q)
	x=-1;
if(p==q)
{
int i=0;
while(i<p)
{
if(intal1[i]>intal2[i])
{x=1;
break;}
if(intal1[i]<intal2[i])
{
x=-1;
break;
}
i++;
}
if(i==p)
	x=0;
}
return x;
}




char* intal_diff(const char* intal1, const char* intal2)
{ 

int z= intal_compare(intal1,intal2); 
    int n1 = strlen(intal1), n2 = strlen(intal2);

if(z==1){
int j=0;
    int diff = n1 - n2; 
    int carry = 0; 
  char result[n1];
    for (int i=n2-1; i>=0; i--) 
    { 
        int sub = ((intal1[i+diff]-'0') - 
                   (intal2[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        result[j]=sub+'0';
	j++; 
    } 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (intal1[i]=='0' && carry) 
        { 
            result[j]='9';
		j++; 
            continue; 
        } 
        int sub = ((intal1[i]-'0') - carry); 
        if (i>0 || sub>0) {
            result[j]=sub+'0';
		j++; 
	}
        carry = 0; 
  
    } 
result[j]='\0';
char *result1=(char *)malloc((sizeof(char))*(n1));
int k=0;
for(int i=(strlen(result))-1;i>=0;i--)
{
result1[k]=result[i];
k++;
}
result1[k]='\0';
result1=removeZeros(result1,strlen(result1));
return result1;
}
if(z==-1){
int j=0;
    int diff = n2 - n1; 
    int carry = 0; 
  char result[n2];
    for (int i=n1-1; i>=0; i--) 
    { 
        int sub = ((intal2[i+diff]-'0') - 
                   (intal1[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        result[j]=sub+'0';
	j++; 
    } 
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        if (intal2[i]=='0' && carry) 
        { 
            result[j]='9';
		j++; 
            continue; 
        } 
        int sub = ((intal2[i]-'0') - carry); 
        if (i>0 || sub>0) {
            result[j]=sub+'0';
		j++; 
	}
        carry = 0; 
  
    } 
result[j]='\0';
char *result1=(char *)malloc((sizeof(char))*(n2));
int k=0;
for(int i=(strlen(result))-1;i>=0;i--)
{
result1[k]=result[i];
k++;
}
result1[k]='\0';
result1=removeZeros(result1,strlen(result1)); 
return result1;
}
else
{
if(z==0)
{
char *b=(char *)malloc((sizeof(char))*2);
strcpy(b,"0");
return b;
}
}
char *res=(char *)malloc(sizeof(char)*2);
strcpy(res,"0");
return res;
}




char* intal_multiply(const char* intal1, const char* intal2)
{ 
	if (intal1[0]=='0' || intal2[0]=='0') 
   	{
	char *b=(char *)malloc((sizeof(char))*2);
	strcpy(b,"0");
	return b; 
	}
    int len1 = strlen(intal1);	
    int len2 = strlen(intal2); 

int result[len1+len2+1];
for(int i=0;i<len1+len2+1;i++)
	result[i]=0;
    int i_n1 = 0;  
    int i_n2 = 0;  
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = intal1[i] - '0'; 
        i_n2 = 0;               
        for (int j=len2-1; j>=0; j--) 
        {  
            int n2 = intal2[j] - '0'; 
            int sum = n1*n2 + (result[i_n1 + i_n2]) + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = (sum % 10); 
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] =(result[i_n1 + i_n2]+carry); 
        i_n1++; 
    }   
    
  
int result1[len1+len2+1];
	int k=0;
	int i;
	for(int i=len1+len2-1;i>=0;i--)
	{
	result1[k]=result[i];
	k++;
	}

	
	char* result2 = (char *)calloc((len1+len2+1),(sizeof(char)));
	for(i=0;i<(len1+len2);i++)
	{
	result2[i]=result1[i]+'0';
	}
	result2[i]='\0';
	result2=removeZeros(result2,strlen(result2)); 
	return result2;
} 


static char* exten_mod(const char* intal1,const char* intal2,char* num)
{
    char* temp;
    strcpy(num,intal1);
    while(intal_compare(num,intal2)==1)
    {
        temp = intal_diff(num,intal2);
		strcpy(num,temp);
        free(temp);
    }
    return num;
}

char* intal_mod(const char* intal1, const char* intal2)
{
    char* result = (char*)malloc(sizeof(char)*1001);
    strcpy(result,"0");
    if((0==strcmp(intal1,"0")) || (0==strcmp(intal2,"0")) || (0==strcmp(intal1,intal2)) || (0==strcmp(intal2,"1")) )
	{
		return result;
	}
    if(intal_compare(intal1,intal2)==-1)
    {
    strcpy(result,intal1);
    return result;
    }
    int n1 = strlen(intal1);
    char* temp;
	char* temp1;
	char* temp2;
	char num[1001];
    for(int i = 0; i < n1 ; i++)
    {
        char c[2];
        c[0] = intal1[i];
        c[1] = '\0';
        temp = intal_multiply(result,"10");
		temp1= intal_add(temp,c);
		temp2=exten_mod(temp1,intal2,num);
		strcpy(num,temp2);
		strcpy(result,num);
		free(temp);
		free(temp1);
    }
    return result;
}





char* intal_pow(char* intal1, unsigned int n) {
  if(n == 0) {
    char* result = (char*)malloc(2 * sizeof(char));
    result[0] = '1';
    result[1] = '\0';
    return result;
  }
  if(n == 1) {
    char* result = (char*)malloc(1001* sizeof(char));
    strcpy(result,intal1);
    return result;
  }

  char* result = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
  strcpy(result,"1");
char* result1 = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
  strcpy(result1, intal1);

  for(int i = n;i>0; i=i/2) {
if(i&1)
{
    char* temp = result;
    result = intal_multiply(result, result1);
    free(temp);
}
    char* temp1 = result1;
    result1 = intal_multiply(result1, result1);
    free(temp1);
  }
free(result1);
  return result;
}

char* intal_gcd(const char* intal1, const char* intal2)
{
	char* result = (char*)malloc(sizeof(char)*1001);
    strcpy(result,"0");
	if((0==strcmp(intal1,"0")) && (0==strcmp(intal2,"0")) )
	{
		return result;
	}
	if((0==strcmp(intal1,"0")))
	{
		strcpy(result,intal2);
		return result;
	}
	if((0==strcmp(intal2,"0")))
	{
		strcpy(result,intal1);
		return result;
	}
	char a[1001];
	char b[1001];
	strcpy(a,intal1);
	strcpy(b,intal2);
	char* temp;
	while(strcmp(b,"0")!=0)
	{
		temp=intal_mod(a,b);
		strcpy(a,b);
		strcpy(b,temp);
		free(temp);
		
	}
	strcpy(result,a);
	return result;
}





char* intal_factorial(unsigned int n)
{
if(n==0 || n==1)
{
	char *res=(char *)malloc(2*sizeof(char));
	strcpy(res,"1");
	return res;
}
char a[1001]="1";
char imm[10];
char *res;
int i;
for(i=2;i<=n;i++)
{
	sprintf(imm,"%d",i);
	res=intal_multiply(a,imm);
	strcpy(a,res);
	free(res);
}
char *res1=(char*)malloc(1001*sizeof(char));
strcpy(res1,a);
return res1;
}



char* intal_fibonacci(unsigned int n)
{
if(n==0)
{
	char *res=(char *)malloc(2*sizeof(char));
	strcpy(res,"0");
	return res;
}
if(n==1)
{
	char *res=(char *)malloc(2*sizeof(char));
	strcpy(res,"1");
	return res;
}
char prev[1001]="0";
char cur[1001]="1";
for(int i=2;i<=n;i++)
{
char *res=intal_add(prev,cur);
strcpy(prev,cur);
strcpy(cur,res);
free(res);
}
char *res1=(char *)malloc(sizeof(char)*1001);
strcpy(res1,cur);
return res1;
}




char* intal_bincoeff(unsigned int n, unsigned int k) {
int m=n-k;
if(m<k)
 k=m;
  char** c = (char**)malloc((k+1) * sizeof(char*));
  for(int i = 0; i < k + 1; ++i) {
    c[i] = (char*)malloc(2 * sizeof(char));
    c[i][0] = '0';
    c[i][1] = '\0';
  }

  c[0][0] = '1';

  for(int i = 1; i < n + 1; ++i) {
    int j = (i > k)? k: i;
    while(j > 0) {
      char* tmp = c[j];
      c[j] = intal_add(c[j], c[j - 1]);
      free(tmp);
      --j;
    }
  }

  char* result = (char*)malloc((strlen(c[k]) + 1) * sizeof(char));
  strcpy(result, c[k]);
  
  for(int i = 0; i < k + 1; ++i) {
    free(c[i]);
  }
  free(c);

  return result;
}


int intal_max(char **arr, int n)
{
	if(n==0)
		return -1;
	int i; 
	int maxi=0;
    for (i = 1; i < n; i++) 
	{
       int z=intal_compare(arr[i],arr[maxi]);
	   if(z==1)
		maxi=i;
	}
    return maxi;
}


int intal_min(char **arr, int n)
{
	if(n==0)
		return -1;
	int i; 
	int min=0;
    for (i = 1; i < n; i++) 
	{
       int z=intal_compare(arr[i],arr[min]);
	   if(z==-1)
		min=i;
	}
    return min;
}


int intal_search(char **arr, int n, const char* key)
{
	int i; 
    for (i = 0; i < n; i++) 
	{
		int z=intal_compare(arr[i],key);
        if(z==0) 
           return i; 
	}
    return -1; 
}



int intal_binsearch(char **arr, int n, const char* key)
{
  int low = 0;
  int high = n;
  int out = -1;
  while (high > low) {
    int mid = low + (high-low) / 2;
	int z=intal_compare(key,arr[mid]);
    if (z==1) {
      low = mid + 1;
    } else if (z==-1) {
      high = mid;
    } else {
      out = mid;
      high = mid;
    }
  }
  return out;
}


static void Merge(char* arr[],int low,int mid,int high)
{
    int nL= mid-low+1;
    int nR= high-mid;
    char L[nL][1001];
    char R[nR][1001];
    int i;
    for(i=0;i<nL;i++)
    {
        strcpy(L[i],arr[low+i]);
    }
    for(i=0;i<nR;i++)
    {
        strcpy(R[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
	int z=intal_compare(L[i],R[j]);
        if(z==-1)
			strcpy(arr[k++],L[i++]);
        else
			strcpy(arr[k++],R[j++]);
    }
    while(i<nL)
		strcpy(arr[k++],L[i++]);
    while(j<nR)
		strcpy(arr[k++],R[j++]);
}

static void MergeSort(char* arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
	return;
}

void intal_sort(char **arr, int n)
{
	MergeSort(arr,0,n-1);
	return;
}


char* coin_row_problem(char **arr, int n)
{
	if(n==0)
	{
		char *res=(char *)malloc(2*sizeof(char));
		strcpy(res,"0");
		return res;
	}
	char* prev=(char *)malloc(1001*sizeof(char));
	strcpy(prev,"0");
	char* curr=(char *)malloc(1001*sizeof(char));
	strcpy(curr,arr[0]);
	int i;
	for(i=2;i<=n;i++)
	{
		char *next=intal_add(prev,arr[i-1]);
		int z=intal_compare(next,curr);
		if(z==-1)
			strcpy(next,curr);
		strcpy(prev,curr);
		strcpy(curr,next);
		free(next);		
	}
	free(prev);
	return curr;
}