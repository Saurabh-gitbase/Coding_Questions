int longestUniqueSubString(string str){
  if(str.size() == 0 )
    return 0;
    
  int ans = 0;
  vector<int> index(255,0);
  // i represents start of unique string and j represent end.
  for(int j=0,i=0;j<n;j++)
  {
    i = max(index[str[j]],i);
    ans = max(ans,j-i+1);
    index[str[j]] = j+1;
   }
   
   return ans;
}
