#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
typedef struct node node;

node *current;
node *yeniliste();
void basaekleme(node *list,int sayi);
void sort(node *liste);
int uzunluk(node *liste);
node *duplicate(node *liste);
int sondansilme(node *liste);
node *bastansilme(node *liste);

int main()
{
    node *liste=yeniliste();
    print(liste);
    basaekleme(liste,1453);
    print(liste);
    sort(liste);
    print(liste);
    printf("\n\nToplam dugum sayisi= %d\n",uzunluk(liste));
    printf("\n\nAyný Dugumlerden Birini Silecek\n\n");
    node *liste2=duplicate(liste);
    print(liste2);
    printf("\n\nEn Sondaki dugumu silecek= %d\n\n",sondansilme(liste));
    print(liste);
    printf("\n\nEn bastaki dugumu silecek\n\n");
    node *liste3=bastansilme(liste);
    print(liste3);

    printf("\n\n\nListedeki max sayi= %d\n\n\n",max(liste3));
    return 0;
}
node *yeniliste()
{
    node *head=NULL;
    int sayi;
    while(1)
    {
        printf("Bir sayi girin= ");
        scanf("%d",&sayi);

        if(sayi==-1) break;
        if(head==NULL)
        {
            head=(node *)malloc(sizeof(node)*1);
            head->data=sayi;
            head->next=NULL;
            head->previous=NULL;
            printf("\nListeye %d degeri eklendi...\n\n",sayi);
        }
        else
        {
            current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            node *temp=(node *)malloc(sizeof(node)*1);
            temp->data=sayi;
            temp->next=NULL;
            temp->previous=current;
            current->next=temp;
            current=current->next;
            printf("\nListeye %d degeri eklendi...\n\n",sayi);
        }
    }
    return head;
}
void print(node *liste)
{
    current=liste;
    printf("\nListeyi yazdir...\n\n");
    int i=0;
    while(current!=NULL)
    {
        i++;
        printf("\n%d. dugumde %d degeri var...\n",i,current->data);
        current=current->next;
    }
}
void basaekleme(node *liste,int sayi)
{
    if(liste==NULL)
    {
        printf("Liste bos...");
    }
    else
    {
        current=liste;
        node *temp=(node *)malloc(sizeof(node)*1);
        temp->data=sayi;
        temp->next=current->next;
        current->next=temp;
        temp->previous=current;
        temp->next->previous=temp;
        current=current->next;
        printf("\nListenin basina %d degeri eklendi...\n",current->data);
    }
}
void sort(node *liste)
{
    int i,j,len,temp;

    len=uzunluk(liste);
    current=liste;
    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(current->data>current->next->data)
            {
                temp=current->data;
                current->data=current->next->data;
                current->next->data=temp;
            }
            current=current->next;
        }
        current=liste;

    }
}
int uzunluk(node *liste)
{
    int i=1;
    current=liste;
    while(current->next!=NULL)
    {
        current=current->next;
        i++;
    }
    return i;
}
node *duplicate(node *liste)
{
    current=liste;
    node *temp;
    while(current->next!=NULL)
    {
        if(current->data==current->next->data)
        {
            temp=current->next;
            current->next=temp->next;
            current->next->previous=current;
            free(temp);
        }
        else current=current->next;
    }
    return liste;
}
int sondansilme(node *liste)
{
    if(liste==NULL) printf("\nListe bos...\n");
    else
    {
        current=liste;
        while(current->next->next!=NULL)
        {
            current=current->next;
        }
        node *temp;
        int x;
        temp=current->next;
        x=temp->data;
        current->next=temp->next;
        free(temp);
        return x;
    }
}
node *bastansilme(node *liste)
{
    if(liste==NULL)printf("\nListe bos...\n");
    else
    {
        node *temp;
        temp=liste;
        liste=liste->next;
        liste->previous=NULL;
        free(temp);
        return liste;
    }
}
int max(node *liste)
{
    int sayi;
    current=liste;
    sayi=current->data;
    while(current->next!=NULL)
    {
        if(sayi<current->next->data)
        {
            sayi=current->next->data;
        }
        current=current->next;
    }
    return sayi;
}
