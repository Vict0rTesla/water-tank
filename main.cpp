#include<iostream>
using namespace std;
int localMax(int x[],int i,int n);
int waterBlocks(int x[],int max1,int max2,int n);


int main() {
  int arr[] = {5,3,2,6,4,2,3,5};
  int n=8;
  cout<<"the water block are ";
  cout<<waterBlocks(arr,0,localMax(arr,0,n),n)<<endl;

  
  return 0;
}

int waterBlocks(int x[],int max1,int max2,int n){
  int min;
  if(x[max1]>x[max2]){
    min=x[max2];
  } else {
    min=x[max1];
  }
  int water = 0;
  for(int i=max1+1;i<max2;i++){
    water += min-x[i];
  }
  if(max2+1==n){
    return (water);
  }
  int local = localMax(x,max2,n);
  return (water+(waterBlocks(x,max2,local,n)));
}

int localMax(int x[],int i,int n){
  for(i++;;i++){
    if(i==n){
      return i;
    }
    if(x[i-1]<x[i]&&x[i]>x[i+1]){
      return i;
    }
  }
}
