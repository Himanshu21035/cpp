let promise=new Promise((resolve,reject)=>{
    let success=true;
    if(success){
        resolve(200);
    }
    else{
        reject(400);
    }
});
console.log(promise);