#include<stdio.h>


struct stack{
    int arr[30];
    int Csize;
    int Msize;
};

struct stack createStack(int size){
    struct stack st;
    st.Csize=0;
    st.Msize=size;
    return st;
}

void popStack(struct stack* st){
    if(st->Csize==0){
        printf("no element to delete");
    }
    else{
        int idx=st->Csize;
        st->Csize=st->Csize-1;
    }
}

void pushStack(struct stack* st,int val ){
    if(st->Csize==st->Msize){
        printf("stack is full \n");
    }
    int idx=st->Csize;
    st->arr[idx]=val;
    st->Csize=st->Csize+1;
}


int main(){
    struct stack st = createStack(10);
    pushStack(&st,10);
    pushStack(&st,20);
    popStack(&st);
    int len=st.Csize-1;
    while(len>=0){
        printf("%d \n",st.arr[len]);
        len--;
    }
}