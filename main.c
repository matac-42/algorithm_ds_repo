
#include<stdio.h>
#include <stdlib.h>

int find_key();
void delete_key();

struct vertex{
    int name, key;
    struct vertex *next;
} *top;/**/


int main(){
    struct vertex *new;
    int n, k, ans;

    printf("\n");
    printf("::::::::リストへのデータ入力::::::::: \n");
    printf("\n");

    printf("各要素を入力してください\n");
    top = NULL;
    while(1){
        printf("  nameの値を入力してください：　");
        scanf("%d", &n);
        if(n < 0) break;
        printf(" keyの値を入力してください：　");
        scanf("%d", &k);
        if(find_key(k) == 1){
            printf("  key: %d は既登録です\n", k);
            printf("    keyが %d のものを削除しますか？\n", k);
            printf("      YES: 1 / No: 0 ==");
            scanf("%d",& ans);
            if(ans == 1) delete_key(k);
            else printf("  もう一度 name の値から入力してください\\n");
        }
        else {
            new = (struct vertex *) malloc(sizeof(struct vertex));
            /*malloc関数はメモリを確保する機能を持つ。
             * vertex型構造体をメモリ上に置くために必要なメモリ領域をsizeof関数で求め, その分だけメモリ領域を確保する。
             * 左側の丸括弧でstruct vertex * 型のデータ型を持つポインタ値にすることを指定している。
             * */
            new->name = n;
            new->key = k;
            new->next = top;
            top = new;
        }
    }

    printf("\n");
    printf("--------------------------------------\n");
    printf("入力したデータ([name, key]の順番でヘッドに近い構造体から出力\n");
    while(top != NULL){
        printf("[%d, %d] ", top->name, top->key);
        top = top->next;

    }
    printf("\n");
}

/*
 * ユーザーが入力したkeyの値が既出であったとき(被りが出たとき)1を返し,
 * そうでなければ0を返す関数
 * */
int find_key(int k)
{
    struct vertex *w;

    w = top;
    while(w != NULL){
        /*リストの頭から最後まで探索できる*/
        if(k == w->key)
            /* keyがユーザーの入力であるkと一致した場合*/
            return 1;
        w = w->next;/*次の構造体に移動*/
    }
    return 0;/*一致することがなかった場合*/
}

/*
 * keyが被ったvertex構造体を削除する関数
 * */
void delete_key(int k)
{
    struct vertex *w, *prev, *tmp;
    if(k == top->key){
        /*リストの先頭のkeyを削除*/
        tmp = top; /*メモリ解放のためにtopのアドレスをtmpに控えておく*/
        top = top->next;/*　topを次の構造体のアドレスに変更　*/
        free(tmp);/*　使われなくなった、tmpに控えてあるアドレスで指定されている構造体のメモリを解放　*/
    }
    else{
        /*リストの先頭以外のkeyを削除*/
        prev = top;
        w = prev->next;/* wが削除したい(keyが一致する)構造体のアドレスになるように次のwhile文で探索する　*/
        while(w != NULL){
            /*リストの頭から最後まで探索できる*/
            if(k ==  w->key){
                /*削除したい構造体に到達した場合*/
                prev->next = w->next;
                /* wの前の構造体が次の構造体のアドレスを指している
                 * prev->nextをwの次の構造体のアドレスに置き換えている*/
                free(w);/*使われなくなったwのアドレスの構造体のメモリを解放*/
                break;
            }
            /*削除したい構造体に到達していない場合*/
            prev = w;
            w = w->next;/*次の構造体に進む*/
        }
    }
}






