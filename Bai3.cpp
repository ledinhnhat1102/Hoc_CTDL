#include<iostream>
using namespace std;

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

//khoi tao cau truc danh sach don
void KhoiTaoDSLK(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

//Ham khoi tao 1 cai node
NODE *KhoiTaoNODE(int x){
    NODE *p = new NODE;
    if(p==NULL){
        cout<<"Khong du bo nho de cap phat";
        return NULL;
    }
    else{
        p->data = x;
        p->pNext = NULL;
    }
    return p;
}

//Ham them node vao dau danh sach lien ket
void themVaoDauDS(LIST &l, NODE*p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }else{
        p->pNext= l.pHead;//cho con tro p tro den noi dau(l.phead)
        l.pHead=p;// cap nhat lai l.phead luc nay la p
    }
}

//Ham them node vao cuoi danh sach
void themVaoCuoiDS(LIST &l, NODE *p){
    //danh sach luc nay dang rong
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }else{
        l.pTail->pNext = p;
        l.pTail = p;

    }
}

//ham hien thi danh sach lien ket
void hienThiDS(LIST l){
    for(NODE *k=l.pHead; k!=NULL; k=k->pNext){
        cout<<k->data<<" ";
    }
}



//Ham them node p vao sau node q trong danhs ach lien ket don
void them_p_sau_q(LIST &l, NODE *p){
    int x;
    cout<<"Nhap gia tri cua node q: ";
    cin>>x;
    NODE *q = KhoiTaoNODE(x);

    //neu danh sach chi co 1 phan tu => them vao cuoi danh sach
    if(q->data==l.pHead->data && l.pHead->pNext==NULL){
        themVaoCuoiDS(l,p);
    }else{
        //duyet tu dau danh sach
        for(NODE *k=l.pHead; k!=NULL; k=k->pNext){
            //neu q co ton tai thi
            if(q->data==k->data){
                NODE *h = KhoiTaoNODE(p->data);//khoi tao h
                NODE *g = k->pNext; //cho g lam trung gian , nam sau q(k)
                h->pNext=g; //b1: tao moi lien ket tu p den g;
                k->pNext=h; //b2: tao moi lien ket tu q den p (do k la q)
            }
        }
    }

}

//menu
void MENU(LIST &l){
    int luaChon;
    while(69){
        system("cls");
        cout<<"=============MOI BAN LUA CHON============="<<endl;
        cout<<"1.Them NODE vao danh sach"<<endl;
        cout<<"2.Xuat danh sach lien ket don"<<endl;
        cout<<"3.Them node p vao sau node p trong danh sach lien ket don"<<endl;
        cout<<"0.Thoat"<<endl;
        cout<<"----------------------------------------------------------"<<endl;
    
    cout<<"Moi ban nhap lua chon: ";
    cin>>luaChon;

    if(luaChon<0 || luaChon>3){
        cout<<"Lua chon khong hop le. Vui long kiem tra lai";
        system("pause");
    }else if(luaChon==1){
        int x;
        cout<<"Nhap gia tri so nguyen: ";
        cin>>x;
        NODE *p= KhoiTaoNODE(x);
        themVaoCuoiDS(l,p);
    }else if(luaChon==2){
        hienThiDS(l);
        system("pause");
    }else if(luaChon==3){
        int x;
        cout<<"Nhap gia tri cua node p: ";
        cin>>x;
        NODE *p = KhoiTaoNODE(x);
        them_p_sau_q(l,p);
    }
    else{
        break;
    }
    }

}

int main(){
    LIST l;
    KhoiTaoDSLK(l);
    MENU(l);

    system("pause");
    return 0;
}