#include <iostream>
using namespace std;

struct Block{
    int key;
    int size;
    Block *pre;
    Block *next;
    Block(int k,int s):key(k),size(s),pre(NULL),next(NULL){}
};

class Memory{
public:
    Memory(int m){
        head = new Block(-1,0);
        Block *p = new Block(0,m);
        tail = new Block(-1,0);
        head->next = p;
        tail->pre = p;
        p->pre = head;
        p->next = tail;
    }

    Block* findEmpty(int length){
        Block *p = head->next;
        while(p!=tail){
            if(p->key == 0 && p->size >=length)
                return p;
            p = p->next;
        }
        return NULL;
    }

    void insert(Block* cur, int key, int length){
        if( cur->size == length) cur->key = key;
        Block *p =new Block(0,cur->size - length);
        p->pre = cur;
        p->next = cur->next;
        p->next->pre = p;

        cur->key = key;
        cur->size = length;
        cur->next = p;
    }

    Block * pos(int k){
        Block *p=head->next;
        while(p!=tail){
            if(p->key == k) return p;
            p = p->next;
        }
        return NULL;
    }

    void deleteBlock(int k){
        Block *p = pos(k);

        Block *tp = p->pre;

        if(tp->key == 0){
            p->size = p->size + tp->size;
            p->pre = tp->pre;
            tp->pre->next = p;
            delete tp;
        }

        tp = p->next;
        if(tp->key == 0){
            p->size = p->size + tp->size;
            p->next = tp->next;
            p->next->pre = p;
        }
        p->key = 0;
    }

    void print(int lastDelete,int n){
        int start = 0;
        for(int i=lastDelete+1;i<=n;i++){
            Block*p = pos(i);
            cout<<p->key<<" "<<start<<endl;
            start = start+p->size;
        }
    }

private:
    Block *head;
    Block *tail;
    int size;
};

int main(){
    int n,m;
    while(cin>>n>>m){
        Memory myMemory(m);
        int lastDeleteData = 0;
        for(int i=1;i<=n;i++){
            int size;
            Block *p;
            cin>>size;
            while(1){
                p = myMemory.findEmpty(size);
                if(p!=NULL){
                    myMemory.insert(p,i,size);
                    break;
                }
                else{
                    lastDeleteData++;
                    myMemory.deleteBlock(lastDeleteData);
                }
            }
        }
        myMemory.print();
    }
    return 0;
}
