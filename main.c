
#include<stdio.h>
#include <stdlib.h>

int find_key();
void delete_key();

struct vertex{
    int name, key;
    struct vertex *next;
} *top;


main(){
    struct vertex *new;
    int n, k, ans;

    printf("\n");
    printf("::::::::リストへのデータ入力::::::::: \n");
    printf("\n");

    printf("各要素を入力してください");
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


int find_key(int k)
{
    struct vertex *w;

    w = top;
    while(w != NULL){
        if(k == w->key)
            return 1;
        w = w->next;
    }
    return 0;
}

void delete_key(int k)
{
    struct vertex *w, *prev, *tmp;
    if(k == top->key){
        tmp = top;
        top = top->next;
        free(tmp);
    }
    else{
        prev = top;
        w = prev->next;
        while(w != NULL){
            if(k ==  w->key){
                prev->next = w->next;
                free(w);
                break;
            }
            prev = w;
            w = w->next;
        }
    }
}






