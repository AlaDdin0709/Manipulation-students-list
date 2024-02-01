struct element
{
    char name [20];
    struct element *suivant;
};
struct liste
{
    struct element *premier;
    struct element *dernier;
    int dim;
};
struct liste *cree_liste();
void inserer_vide(struct liste*,char*);
void inserer_debut(struct liste * ,char*);
void inserer_fin(struct liste * ,char*);
void inserer_pos(struct liste *,char*,int );
unsigned vide (struct liste*);
void suppression_seul_element(struct liste*);
void suppression_premier_element(struct liste*);
void supprimer_element(struct liste *,int);
void suppression_dernier_element(struct liste*);
void suppression_toute_liste(struct liste *);
void afficher(struct liste* );
