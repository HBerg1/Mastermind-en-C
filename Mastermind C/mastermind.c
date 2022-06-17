#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int presence(int *tab,int len,int val)
{
    for(int i = 0;i<len;i++)
    {
        if(tab[i]==val)
        {
            return 1;
        }
    }
    return 0;
}

int cas(int n)
{
    int r;
    switch(n)
    {
        case 4 : 
            r = rand()%n+1;
            break;
        case 6 :
            r=rand()%(n+1);
            break;
        case 8 :
            r=rand()%(n+2);
            break;
    }
    return r;
}

int* suitecache(int n)
{
    int *tab = malloc(sizeof(int)*n);
    for(int j = 0;j<n;j++)
    {
      tab[j] = -1;
    }
    
    int ran = cas(n);
    
    for(int i = 0; i < n;i++)
    {
        if(n==4)
        {
            while(presence(tab,n,ran))
            {
                ran = rand()%n+1 ;
            }
            tab[i] = ran;
        }
        else if(n==6)
        {
            while(presence(tab,n,ran))
            {
                ran = rand()%(n+1) ;
            }
            tab[i] = ran;
        }
        else
        {
            if(ran == 9) ran = 0;
            tab[i] = ran;
            ran = rand()%(n+2);
        }
    }
    return tab;
}


int difficulte()
{
    int i;
    printf("Choisir une difficulte ( chiffre de 1 à 4 ):\n 1 - Facile \n 2 - Moyen \n 3 - Difficile \n 4 - Quitter \n\n");
    scanf("%d",&i);
    while (i<1 || i>4)
    {
        scanf("%d",&i);
    }
    
    int n;
    switch(i)
    {
        case 1:
            n = 4;
            printf("Vous avez choisi Facile\n\n\n");
            break;
        case 2: 
            n = 6;
            printf("Vous avez choisi Moyen\n\n\n");
            break;
        case 3 : 
            n = 8;
            printf("Vous avez choisi Difficile\n\n\n");
            break;
        case 4: 
            
            exit(0);
            break;
    }
    return n;
}
int* choisi(int len)
{
    
    int *tab = malloc(sizeof(int)*len);
    for(int i = 0; i <len;i++)
    {
        int n;
        scanf("%d",&n);
        tab[i] = n;
    }
    return tab;
}

void aff(int *tab,int len)
{
    printf("\n");
    for(int i = 0;i<len;i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

int indice(int*tab , int *cache,int len)
{
    char *ind = malloc(sizeof(char)*(len+1));
    int i;
    for(i = 0; i <len ;i++)
    {
        if(tab[i] == cache[i])
        {
            ind[i] = 'A';
        }
        else
        {
            int j =0;
            int trouve = 0;
            for(;j<len ;j++)
            {
                if(cache[j]== tab[i])
                {
                    trouve = 1;
                }
            }
            if(trouve)
            {
                ind[i] = 'B';
            }
            else
            {
                ind[i] = ' ';
            }
        }
    }
    ind[i] = 0;
    char *pind = ind;
    int a = 1;
    while(*pind)
    {
        if(*pind != 'A')
        {
            a = 0;
        }
        printf("%c ",*pind);
        pind++;
    }
    printf("\n\n\n");
    free(ind);
    return a;
}


void jeu(int *oui)
{
    srand(time(NULL));
    int diff = difficulte();
    
        int *cache = suitecache(diff);
        int *tab = choisi(diff);
        aff(tab,diff);
        int jeu = indice(tab,cache,diff);
        int cpt = 0;
        while(jeu !=1)
        {
            int *tab = choisi(diff);
            aff(tab,diff);
            jeu = indice(tab,cache,diff);
            cpt++;
            if(cpt>=5) aff(cache,diff);
        }
        free(cache);
        free(tab);
        
        
        int rejouer;
        printf("Nombre de coup joué : %d\n\n\n",cpt);
        printf("Voulez-vous rejouer ?\n\n\n");
        printf("1.Oui\n2.Non\n\n");
        scanf("%d",oui);
    
    
}
int main()
{
    int oui = 1;
    while(oui==1)
    {
        jeu(&oui);
    };
    return 0;
}
