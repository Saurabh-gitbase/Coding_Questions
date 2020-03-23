/*
Given an number in form of string convert to int.
e.g "5432" to 5432
using recursion
*/

#include<bits/stdc++.h>
using namespace std;

//Iterate to LMD mul it by 10 and add current to it.
int convert(string num[],int index)
{
  if(index == 0)
  {
    return ( char(num[index]) - '0' ); //LMD
  }
  
  return ( convert(num,index-1)*10 + char(num[index])-'0' );
}

int main()
{
  string num; cin>>num;
  int index = num.length();
  cout<<convert(num,index-1);
}
