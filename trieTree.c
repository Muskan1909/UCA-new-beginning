#include<stdbool.h>

//typedef struct trieTree trie;

typedef struct trieTree{
   struct trieTree *arr[26];
   bool isEndOfWord;
}trie;

trie* createNode(){
   trie *nn = (trie*)malloc(sizeof(trie));
   int i;
   for(i=0;i<26;i++)
     nn->arr[i] = NULL;
   nn->isEndOfWord = false;
   return nn;
}

void insert(trie* root, char str[]){
   int i;
   for(i=0;i<strlen(str);i++){
      int j = str[i] - 'a';
      if(root->arr[j]!=NULL)
        root = root->arr[j];
      else{
        root->arr[j] = createNode();
        root = root->arr[j];
      }
     root->isEndOfWord = true;
   }
}

bool search(trie *root,char str[],int index){
   if(index == strlen(str)){
      if(!root->isEndOfWord)
         return false;
      return true;
   }
   int j = str[index]-'a';
   if(!root->arr[j])
     return false;
   return search(root,str,index+1);
}

int main(){
  trie *root = createNode();
   int n;
   scanf("%d",&n);
   char str[n][10];
   int i;
   for(i=0;i<n;i++){
        scanf("%s",*(str + i));
        insert(root,str[i]);
   }
   //char **str = malloc(sizeof(char*)*n);
   char* searchStr = (char*)malloc(sizeof(char)*50);
   scanf("%s",searchStr);
   if(search(root,searchStr,0))
     printf("present");
   else
     printf("not present");
}
                
