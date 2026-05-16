#include <stdio.h>
int main() {
    int n,f,pf=0,ph=0,t=0,c=0;
    scanf("%d",&n);
    int p[n]; for(int i=0;i<n;i++) scanf("%d",&p[i]);
    scanf("%d",&f);

    int fr[f],lu[f];
    for(int i=0;i<f;i++) fr[i]=lu[i]=-1;

    for(int i=0;i<n;i++){
        int idx=-1;
        for(int j=0;j<f;j++)
            if(fr[j]==p[i]) { idx=j; break; }

        if(idx!=-1){
            ph++; lu[idx]=t++;
        } else {
            pf++;
            if(c<f){
                fr[c]=p[i]; lu[c++]=t++;
            } else {
                int lru=0;
                for(int j=1;j<f;j++)
                    if(lu[j]<lu[lru]) lru=j;
                fr[lru]=p[i]; lu[lru]=t++;
            }
        }
    }
    printf("Page Faults: %d\nPage Hits: %d",pf,ph);
}
