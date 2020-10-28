#define mod 1000000007

int Solution::maxSpecialProduct(vector<int> &A) {
    
    int n = A.size();
    if(n==0) return 0;
    
    vector<int> leftSp(n,-1),rightSp(n,-1);
    stack<int> s1,s2;
    int i,tmp;
    long long int max_p=0,cur_p;
    
    s1.push(0);
    s2.push(0);
    for(i=1;i<n;i++){
        while(s1.size()>0 && A[ s1.top() ]<=A[i]) s1.pop();
        if(s1.size()>0){ 
            tmp=s1.top();
            if(A[i]<A[tmp]) leftSp[i]=tmp;
        }
        s1.push(i);
        
        tmp=s2.top();
        while(A[ tmp ]<A[i]){
            rightSp[tmp]=i;
            s2.pop();
            if(s2.size()>0) tmp=s2.top();
            else break;
        }
        s2.push(i);
    }
    
    for(i=0;i<n;i++){
        if(leftSp[i]!=-1 && rightSp[i]!=-1){
            cur_p=(long long int)leftSp[i]*(long long int)rightSp[i];
            if(cur_p>max_p) max_p=cur_p;
        }
    }
    
    max_p=max_p%mod;
    
    return max_p;
}
