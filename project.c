#include <assert.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "project.h"

struct liste *cree_liste()
{
    struct liste *l;
    l=(struct liste*) malloc(sizeof(struct liste));
    assert (l!=NULL);
    l->premier=NULL;
    l->dernier=NULL;
    l->dim=0;
    return l;
}

void inserer_vide(struct liste* l,char* nom)
{
    struct element *e;
    assert (l!=NULL);
    e=(struct element *) malloc (sizeof(struct element));
    assert (e!=NULL);
    strcpy(e->name,nom);
    e->suivant=NULL;
    l->premier=e;
    l->dernier=e;
    l->dim=1;
}

void inserer_debut(struct liste * l,char *nom)
{
    struct element *e;
    assert (l!=NULL);
    e=(struct element *) malloc (sizeof(struct element));
    assert (e!=NULL);
    strcpy(e->name,nom);
    e->suivant=l->premier;
    l->premier=e;
    l->dim=l->dim+1;
}

void inserer_fin(struct liste *l ,char* nom)
{
    struct element *e;
    assert (l!=NULL);
    e=(struct element *) malloc (sizeof(struct element));
    assert (e!=NULL);
    strcpy(e->name,nom);
    e->suivant=NULL;
    l->dernier->suivant=e;
    l->dernier=e;
    l->dim=l->dim+1;
}

void inserer_pos(struct liste *l ,char* nom,int pos )
{
    struct element *e,*q;
    int nb=1;
    assert (l!=NULL);
    e=(struct element *) malloc (sizeof(struct element));
    assert (e!=NULL);
    q=l->premier;
    while(q && nb!=pos-1)
    {
    q=q->suivant;
        nb++;
    }
    if (nb==pos-1)
    {
    strcpy(e->name,nom) ;
    e->suivant=q->suivant;
    q->suivant=e;
    l->dim++;
    }
}

unsigned vide (struct liste *l)
{
    return (l->dernier==NULL && l->premier==NULL);

}

void suppression_seul_element(struct liste*l)
{
    struct element *e;
    if (vide(&l)==1)
    {
        printf("liste vide");
    }
    else
    {
    assert(l!=NULL);
    e=l->premier;
    l->premier=NULL;
    l->dernier=NULL;
    free(e);
    l->dim=l->dim-1;;
    }

}

void suppression_premier_element(struct liste*l)
{
    struct element *e;
    if (vide(&l)==1)
    {
        printf("liste vide");
    }
    else
    {
    assert(l!=NULL);
    e=l->premier;
    l->premier=l->premier->suivant;
    free(e);
    l->dim=l->dim-1;

    }
}
//NB: a retenir?????????????????????????????????????????
void supprimer_element(struct liste *l,int pos)
{
    struct element *p,*q;int nb=1;
if (vide(&l))
    {
        printf("liste vide");
    }
    else
    {
        q=l->premier;
        while(q && nb!=pos)
    {
        p=q;
        nb++;
        q=q->suivant;
    }
    if (q)
    {
    p->suivant=q->suivant;
    free(q);
    l->dim=l->dim-1;

    }
    }
}

void suppression_dernier_element(struct liste*l)
{
    struct element *e1;
struct element *e2;
assert (l!=NULL);
e1= l->premier;
while(e1->suivant!= NULL)
{
e2= e1;
e1= e1->suivant;
}
e2->suivant=NULL;
free(e1);

l->dim=l->dim-1;
}



void suppression_toute_liste(struct liste *l)
{
    assert (l!=NULL);
    struct element *e;
    e=l->premier;
    free(e);
    l->dernier=NULL;
    l->premier=NULL;

    l->dim=0;
}

void afficher(struct liste *l)
{
    struct element *p;
    assert(l!=NULL);
     p=l->premier;
        while(p)
    {
        printf("%s\n",p->name);
        p=p->suivant;
    }
}

