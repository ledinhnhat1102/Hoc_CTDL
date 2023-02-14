#include<iostream>
using namespace std;

//cau truc 1 cai node
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

//khoi tao danh sach lien ket don
void khoiTaoDSLK(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

//Khoi tao 1 cai node
NODE *khoiTaoNODE(int x){
    NODE *p = new NODE;
    if(p==NULL){
        cout<<"Khong du bo nho de cap phat!";
        return NULL;
    }else{
        p->data = x;
        p->pNext = NULL;
    }
    return p;
}

//ham them node vao dau danh sach lien ket
void themVaoDau(LIST &l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }else{
        p->pNext=l.pHead;
        l.pHead=p;
    }
}

//ham them node vao cuoi danh sach
void themVaoCuoi(LIST &l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}

//hien thi danh sach lien ket don
void hienThiDanhSach(LIST l){
    for(NODE *k=l.pHead; k!=NULL; k=k->pNext){
        cout<<k->data<<" ";
    }
}

//ham them p vao truoc node q trong danh sach lien ket don
void them_p_truoc_q(LIST &l, NODE *p){
    int x;
    cout<<"Nhap gia tri node q: ";
    cin>>x;
    NODE *q = khoiTaoNODE(x);
    if(q->data==l.pHead->data && l.pHead->pNext==NULL){
        themVaoDau(l,p);
    }else{
        // duyet tu dau danh sach 
        NODE *g = new NODE; // tao node g de giu moi lien ket truoc node q(trung gian)
        for(NODE *k=l.pHead; k!=NULL; k=k->pNext){
            //neu co q ton tai thi
            if(q->data==k->data){
                NODE *h = khoiTaoNODE(p->data);
                h->pNext=k;// b1 cho p tro den k(q)
                g->pNext=h;//cho g (trung gian) tro den p
            }
            g=k;//giu lien ket node truoc node q trong danh sach 
        }
    }
}
void MENU(LIST &l){
    int luaChon;
    while (true)
    {
        system("cls");
        cout<<"=============MOI BAN LUA CHON============="<<endl;
        cout<<"1.Them NODE vao danh sach"<<endl;
        cout<<"2.Xuat danh sach lien ket don"<<endl;
        cout<<"3.Them node p vao truoc node q trong danh sach lien ket don"<<endl;
        cout<<"0.Thoat chuong trinh"<<endl;

        cout<<"Moi ban nhap lua chon: ";
        cin>>luaChon;

        if(luaChon<0 || luaChon>3){
            cout<<"Lua chon ban nhap khong hop le. Kiem tra lai";
            system("pause");
        }else if(luaChon==1){
        int x;
        cout<<"Nhap gia tri so nguyen: ";
        cin>>x;
        NODE *p= khoiTaoNODE(x);
        themVaoCuoi(l,p);
        }else if(luaChon==2){
        hienThiDanhSach(l);
        system("pause");
        }else if(luaChon==3){
            int x;
            cout<<"Nhap gia tri cua p: ";
            cin>>x;
            NODE *p = khoiTaoNODE(x);
            them_p_truoc_q(l,p);
        }
    
}
}




int main(){
    LIST l;
    khoiTaoDSLK(l);
    MENU(l);

    system("pause");
    return 0;
}
