/* example.c */

#include "arcfour.h"

#define F fflush(stdout)

int main(void);

void printbin(int8 *input, const int16 size){
    int16 i;
    int8 *p;

    assert(size > 0);

    for(i = size, p = input; i; i--, p++){
        if(!(i % 2))
            printf(" ");
        printf("%.02x", *p);
    }
    printf("\n");
    return;
}

int main(){
    Arcfour *rc4;
    int16 skey, stext;
    char *key, *from;
    int8 *encypted, *decrypted;

    key = "tomatoes";   /* 8BITS -> 2048BITS*/
    skey = strlen(key);
    from = "Shall I compare thee to a summer's day";
    stext = strlen(from);

    printf("Initializing encryption..."); F;
    rc4 = rc4init((int8 *)key, skey);
    printf("done\n");

    printf("'%s'\n ->", from);
    encypted = rc4encrypt(rc4, (int8 *)from, stext);
    printbin(encypted, stext);
    rc4unintit(rc4);

    printf("Initializing encryption..."); F;
    rc4 = rc4init((int8 *)key, skey);
    printf("done\n");

    decrypted = rc4decrypt(rc4, encypted, stext);
    printf("    ->'%s'\n ->", decrypted);
    rc4unintit(rc4);

    return 0;
}