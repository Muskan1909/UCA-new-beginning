#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int main(){
  char *str;
  str=(char*)malloc(sizeof(char)*50);
  gets(str);
  //puts(str);
  int n=strlen(str);
  //int maxlength=1;
  int i;
  bool table[n][n];
  memset(table,0,sizeof(table));
  int maxlength=1;
  for(i=0;i<n;i++){
    table[i][i]=true;
  }
  int start=0;
  for(i=0;i<n-1;i++){
    if(str[i]==str[i+1]){
      table[i][i+1]=true;
      start=i;
      maxlength=2;
    }
  }
  //printf("start = %d\n",start);
  int k;
  for(k=3;k<=n;k++){
    for(i=0;i<n-k+1;i++){
      int j=i+k-1;
      if(table[i+1][j-1]&&str[i]==str[i+1]){
        table[i][j]=true;
        if(k>maxlength){
          start=i;
           maxlength=k;
          //start=i;
        }
      }
    }
  }
  printf("%d\n",maxlength);
  int low=start;
  int high=start+maxlength-1;
  for(i=low;i<=high;i++)
    printf("%c",str[i]);
}
