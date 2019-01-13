#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
  char *c,*s,*ss;
  s=(char*)malloc(sizeof(char)*50);
  c=(char*)malloc(sizeof(char)*50);
  ss=(char*)malloc(sizeof(char)*50);
  gets(s);
  gets(ss);
  strcpy(c,ss);
  strcat(ss,"$");
  strcat(ss,s);
  int x=strlen(s);
  int y=strlen(c);
  int i;
  int Z[x+y+1];
  int l,r=0;
  //Z[0]=0;
  for(i=1;i<x+y+1;i++){
    if(i>r){
      l=i;
      r=i;
      while((r<x+y+1)&& (ss[r-l]==ss[r]))
       r++;
    Z[i]=r-l;
    r--;
    }
    else{
      if(Z[i-l]<r-i+1){
        Z[i]=Z[i-l];
      }
      else{
       l=i;
       while((r<x+y+1)&&(ss[r-l]==ss[r]))
         r++;
       Z[i]=r-l;
       r--;
      }
    }
  }
   //printf("%d\n",y);
   for(i=0;i<x+y+1;i++)
     printf("%d ",Z[i]);
  for(i=0;i<x+y+1;i++){
    if(Z[i]==y){
      printf("\n%d",i-y-1);
      break;
    }
  }
}
