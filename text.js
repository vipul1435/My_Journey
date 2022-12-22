var a=[1,2,3,-1,2,3,-9,40]
var d = fun(a);
function fun(a){
    var le=a.length;
    var ans=0;
    var temp=0;
    var res=[];
    var se=[];
    for(var  i=0;i<le;i++){
        if(a[i]<0){
            if(temp>ans){
                ans=temp;
                res=[];
                res=se
            }
            se=[];
            temp=0;
        } else{
            temp+=a[i];
            se.push(a[i]);
        }
    } 
    if(temp>ans){
        res=[];
        res=se;  
    }
    return res;
}
for(var i=0;i<d.length;i++){
    console.log(d[i]);
}