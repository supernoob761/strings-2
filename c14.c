#include <stdio.h>
#include <string.h>
#define MAX_TACHE 100
#define MAX_COLAB 10




int count_collab;

struct Collaborateur{

char nom[30];
char prenom[30];
char email[30];
};
struct Tache{
    int id;
    char titre[30];
    char deadline[30];
    char description [30];
    char statut[30];
    struct Collaborateur c[MAX_COLAB];
    int nbCollab;

};

struct Tache tache[MAX_TACHE];
int nbtache=0;

void ajouter_Tache()
{
    struct Tache t;
  
    t.id=nbtache;
    printf("Titre : ");
    fgets(t.titre,sizeof(t.titre),stdin);
    t.titre[strcspn(t.titre, "\n")] = '\0';

    printf("description : ");
    fgets(t.description, sizeof(t.description), stdin);
    t.description[strcspn(t.description, "\n")] = '\0';

    printf("deadline : ");
    fgets(t.deadline, sizeof(t.deadline), stdin);
    t.deadline[strcspn(t.deadline, "\n")] = '\0';

    printf("status : ");
    fgets(t.statut, sizeof(t.statut), stdin);
    t.statut[strcspn(t.statut, "\n")] = '\0';
    
    printf("saisir le nombre de collaborateur ");
    scanf("%d",&t.nbCollab);
    getchar();
    
    for (int i = 0; i < t.nbCollab; i++)
    {
       if (t.nbCollab<MAX_COLAB)
       {
        printf("nom de collab   : ");
        fgets(t.c[i].nom, sizeof(t.c[i].nom), stdin);
        t.c[i].nom[strcspn(t.c[i].nom, "\n")] = '\0';
 
        printf("prenom collab   :");
        fgets(t.c[i].prenom, sizeof(t.c[i].prenom), stdin);
        t.c[i].prenom[strcspn(t.c[i].prenom,"\n")]='\0';
        
        printf("email de collab : ");
        fgets(t.c[i].email, sizeof(t.c[i].email), stdin);
        t.c[i].email[strcspn(t.c[i].email, "\n")] = '\0';

       }

         
    }
    


 
  
    tache[nbtache]=t;
    nbtache++;

    
    }

void ajouter_plusieurs_tache(){
    
    
    int nb;
    printf("saisir le nombre des tache:");
    scanf("%d",&nb);

    for (int i = 0; i < nb; i++)
    {
       ajouter_Tache();
    }
    

}

int suprimerTacheparId(){
    int id;
    printf("donner le id de tache :");
    scanf("%d",&id);
    for (int i = 0; i < nbtache; i++)
    {
       if (tache[i].id==id)
       {
        for (int j = i; i < nbtache-1; j++)
        {
             tache[j] = tache[j + 1];
        }
        nbtache--;
        printf("tache supprimer avec succes");
        return 1;
        
       }
       
    }
    return 0;
    

}


void afficher_tache() {

    printf("\n\n-----------Affichage-------------------\n\n");

    for (int i = 0; i < nbtache; i++) {
        printf("ID          : %d\n", tache[i].id);
        printf("Titre       : %s\n", tache[i].titre);
        printf("Description : %s\n", tache[i].description);
        printf("Deadline    : %s\n", tache[i].deadline);
        printf("Statut      : %s\n", tache[i].statut);

        
        if (tache[i].nbCollab > 0) {
            printf("Collaborateurs :\n");
            for (int j = 0; j < tache[i].nbCollab; j++) {
                printf("   - %s %s (%s)\n", 
                       tache[i].c[j].prenom, 
                       tache[i].c[j].nom, 
                       tache[i].c[j].email);
            }
        } else {

            printf("Aucun collaborateur assigné.\n");
        }

        printf("-------------------------------------------\n");
    }
}






void rechercherparid(){
    int id;
    printf("donner le id de tache :");
    scanf("%d",&id);
    for (int i = 0; i < nbtache; i++)
    {
       if (tache[i].id==id){
         printf("ID          : %d\n", tache[i].id);
        printf("Titre       : %s\n", tache[i].titre);
        printf("Description : %s\n", tache[i].description);
        printf("Deadline    : %s\n", tache[i].deadline);
        printf("Statut      : %s\n", tache[i].statut);

        
        if (tache[i].nbCollab > 0) {
            printf("Collaborateurs :\n");
            for (int j = 0; j < tache[i].nbCollab; j++) {
                printf("   - %s %s (%s)\n", 
                       tache[i].c[j].prenom, 
                       tache[i].c[j].nom, 
                       tache[i].c[j].email);
            }
        } else {

            printf("Aucun collaborateur assigné.\n");
        }

        printf("-------------------------------------------\n");
        


       }
       
       
       
       
       }

    
}
void modifier_Tache()
{
    int id;

    printf("Donner l'ID de la tâche à modifier : ");
    scanf("%d", &id);

    int i = 0;

    while(i <= nbtache)
    {
        
        if (tache[i].id == id)
        {
            int choix;
            printf("Que voulez-vous modifier ?\n");
            printf("1. Titre\n");
            printf("2. Description\n");
            printf("3. Deadline\n");
            printf("4. Status\n");
            scanf("%d", &choix);
            getchar();

            switch (choix)
            {
            case 1:
                printf("Entrez le nouveau Titre : ");
                fgets(tache[i].titre, sizeof(tache[i].titre), stdin);
                tache[i].titre[strcspn(tache[i].titre, "\n")] = '\0';
                printf("\n------------------Titre modifier avec succes !--------------------\n");
                break;
            case 2:
                printf("Entrez le nouveau Description : ");
                fgets(tache[i].description, sizeof(tache[i].description), stdin);
                tache[i].description[strcspn(tache[i].description, "\n")] = '\0';
                printf("\n---------------Description modifier avec succes !----------------\n");
                break;
            case 3:
                printf("entrez le nouveau deadline : ");
                fgets(tache[i].deadline, sizeof(tache[i].deadline), stdin);
                tache[i].deadline[strcspn(tache[i].deadline, "\n")] = '\0';
                printf("\n---------------Deadline modifier avec succes !--------------------\n");
                break;
            case 4:
                printf("entrez le nouveau Status : ");
                fgets(tache[i].statut, sizeof(tache[i].statut), stdin);
                tache[i].statut[strcspn(tache[i].statut, "\n")] = '\0';
                printf("\n----------------Status modifier avec succes !----------------------\n");
                break;
            default:
                printf("Choix invalide.\n");
            }
        }

        i++;
    }
}


int main()
{
    int choix;

    do {
        printf("\n===== Gestion des Tâches =====\n");
        printf("1. ajouter une tache \n");
        printf("2. ajouter plusieurs taches \n");
        printf("3. afficher toute les taches\n");
        printf("4. suprimmer une tache par ID\n");
        printf("5. rechercher une tache par ID\n");
        printf("6. modifier une tache\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");

        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
        case 1:
            ajouter_Tache();
            break;
        case 2:
            ajouter_plusieurs_tache();
            break;
        case 3:
            afficher_tache();
            break;
        case 4:
            suprimerTacheparId();
            break;
        case 5:
            rechercherparid();
            break;
        case 6: 
            modifier_Tache();
            break;
        case 0: 
            printf("Au Revoir !!!!\n");
            break;
        default:
            printf("Choix invalide, veuillez réessayer.\n");
        
        }
    } while (choix != 0);

    return 0;
}