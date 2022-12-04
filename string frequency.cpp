string Solution::solve(string A) {
    map<char,int>mp;
    for(int i=0;i<A.size();i++){
        if(mp.find(A[i])!=mp.end()){
            mp[A[i]]++;
        }else{
            mp[A[i]]=1;
        }
    }
    string ans="";
    vector<int> v(26,0);
    for(int i=0;i<A.size();i++){
        if(v[(A[i]-'a')]==0){
            ans=ans+A[i];
            ans=ans+to_string(mp[A[i]]);
            v[(A[i]-'a')]=1;
        }else{
            continue;
        }
    }
    return ans;
}
