/*
Given an number in form of string convert to int.
e.g "5432" to 5432
using recursion
*/

#include<bits/stdc++.h>
using namespace std;

//Iterate to LMD mul it by 10 and add current to it.
int convertRecur(string num[],int index)
{
  if(index == 0)
  {
    return ( char(num[index]) - '0' ); //LMD
  }
  return ( convertRecur(num,index-1)*10 + char(num[index])-'0' );
}

int convertNormal(string num,int size)
{
  int number = 0;
  for(int i=0;i<=n;i++)
  {
    number *= 10;
    number += char(num[i])-'0';
  }
  return number;
}

int main()
{
  string num; cin>>num;
  int index = num.length();
  cout<<convertRecur(num,index-1)<<endl;
  cout<<convertNormal(num,index-1);
}
