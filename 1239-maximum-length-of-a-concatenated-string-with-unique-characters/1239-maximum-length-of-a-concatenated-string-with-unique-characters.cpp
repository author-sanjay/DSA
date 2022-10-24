class Solution {
public:
    bool repeat(vector<int> selected,string &curr){
        vector<int> self(26,0);
        for(int i=0;i<curr.size();i++){
            if((self[curr[i]-'a' ])==1){
                return false;
            }
            
            self[curr[i]-'a']=1;
            
        }
        for(int i=0;i<curr.size();i++){
            if(selected[curr[i]-'a'])
                return false;
            
        }
        
        return true;
        
    }
    int solve(vector<string> arr,vector<int> &selected,int index,int len){
        if(index==arr.size()){
            return len;
        }
        string curr=arr[index];
        
            if(repeat(selected,curr)==false){
                return solve(arr,selected,index+1,len);
            }else{
                for(int j=0;j<curr.size();j++){
                    selected[curr[j]-'a']=1;
                }
                len+=curr.size();
                
                int opt1=solve(arr,selected,index+1,len);
                for(int j=0;j<curr.size();j++){
                    selected[curr[j]-'a']=0;
                }
                len-=curr.size();
                int opt2=solve(arr,selected,index+1,len);


                

            return max(opt1,opt2);
            }
        return 0;
        }
        

    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
        return solve(arr,selected,0,0);
    }
};