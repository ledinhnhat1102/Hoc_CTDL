#include<iostream>
using namespace std;
//nhap danh sach lien ket don cac so nguyen sau do tim ra so lon nhat
//khai bao cau truc 1 cai node
struct node
{
    int data;
    struct node *pNext;
    
};
typedef struct node NODE;

//khai bao cau truc danh sach lien ket don
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

//KHOI TAO CAU TRUC DANH SACH LIEN KET
void KhoiTao(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

//HAM KHOI TAO 1 CAI NODE
NODE *KhoitaoNODE(int x){
    NODE *p = new NODE;
    if(p== NULL){
        cout<<"Khong du bo nho !"<<endl;
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

//ham them node vao dau danh sach lien ket
void themVaoDau(LIST &l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }else{
        p->pNext=l.pHead;//cho con tro p tro den phead
       l.pHead=p;// cap nhat l.phead thanh p;
    }
}

//ham them node vao cuoi danh sach lien ket
void themVaoCuoi(LIST &l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }else{
        l.pTail->pNext = p;
        l.pTail=p;

    }
}

//xuat
void xuatDanhSach(LIST l){
    for(NODE *k = l.pHead; k!= NULL; k=k->pNext){
        cout<<k->data<<" ";
    }
}

//tim max
int timMax(LIST l){
    int max = l.pHead->data;//gia su phan tu dau la max
    for(NODE *k = l.pHead->pNext; k!=NULL;k=k->pNext){
        if(max < k->data){
            max = k->data;
        }
    }
    return max;
    

}




int main()
{
    LIST l;
    KhoiTao(l);
    int n;
    cout<<"Nhap so luong node can them : "<<endl;
    cin>>n;
    for(int i = 1; i<=n; i++){
        int x;
        cout<<"Nhap gia tri thu "<<i<<" : ";
        cin>>x;
        NODE *p = KhoitaoNODE(x);
        themVaoDau(l,p);

    }
    cout<<"DANH SACH LIEN KET DON: "<<endl;
    xuatDanhSach(l);
    cout<<endl;
    cout<<"GIA TRI MAX: "<<timMax(l)<<endl;
    


    system("pause");
    return 0;
}