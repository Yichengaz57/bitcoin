//#include <time.h>
#include "bitcoin.h"

int main()
{
// Initialisation_les opérations élémentaires
    BlockChain bloc1=NULL;
    BlockChain bloc2;
    bloc1=ajouterBlock(bloc1);
    bloc1->trans_jour=ajouterTransaction(1,100,"recharger 100 euro",bloc1->trans_jour);
    bloc1->trans_jour=ajouterTransaction(2,100,"recharger 100 euro",bloc1->trans_jour);
    bloc1->trans_jour=ajouterTransaction(3,100,"recharger 100 euro",bloc1->trans_jour);
    crediter(1,50,"test crediter",bloc1);
    payer(2,20,"test payer",bloc1);
    transfert(1,3,40,"test trans",bloc1);
    bloc2=ajouterBlock(bloc1);
    bloc2->trans_jour=ajouterTransaction(4,99.99,"recharger 99.99 euro",bloc2->trans_jour);
    transfert(2,4,15.7,"test trans",bloc2);

    int opt=0;
    int opt1;
    int opt2;
    int opt3;
    int opt4;
    int opt5;
    float opt6;
    char opt7[256];
    int opt8;
    float opt9;
    char opt10[256];
    int opt11;
    int opt12;
    float opt13;
    char opt14[256];
    while (opt!=8)
    {
        printf("-------------------------------------------------Menu-------------------------------------------------\n");
        printf("1)Afficher la liste des blocs de la BlockChain\n");
        printf("2)Afficher toutes les transactions d'un bloc\n");
        printf("3)Afficher toutes les transactions du jour pour un etudiant\n");
        printf("4)Afficher l'historique pour un etudiant\n");
        printf("5)Crediter un compte\n");
        printf("6)Payer un repas\n");
        printf("7)Transferer des EATCoins entre deux etudiants\n");
        printf("8)Quitter\n");
        printf("\nAttention par default : Tous les operations que vous voulez faire sont a reservees sur bloc2 \n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1 :    printf("*********************************Affichahge la liste des blocs de la BlockChain !*****************\n\n");
                    afficherBlockChain(bloc2);
                    break;
        case 2 :
                    printf("Veuillez-vous entrer le id_bloc dont vous voulez consulter!\n");
                    scanf("%d",&opt1);
                    printf("*********************************Affichahge toutes les transactions d'un bloc %d!*******************\n\n",opt1);
                    afficherlesTransactionBloc(bloc2,opt1);
                    break;
        case 3 :
                    printf("Veuillez-vous entrer le id_bloc(date) que vous voulez consulter!\n");
                    scanf("%d",&opt2);
                    printf("Veuillez-vous entrer le id_etudiant que vous voulez consulter!\n");
                    scanf("%d",&opt3);
                    printf("*********************************Affichahge toutes les transactions du bloc(jour)%d pour un etudiant %d!*******************\n\n",opt2,opt3);
                    afficherTransactionJourpouretudiant(opt3,opt2,bloc2);
                    break;
        case 4 :
                    printf("Veuillez-vous entrer le id_etudiant que vous voulez consulter!\n");
                    scanf("%d",&opt4);
                    printf("*********************************Affichahge l'historique pour un etudiant%d!*******************\n\n",opt4);
                    afficherHistorique(opt4,bloc2);
                    break;
        case 5 :
                    printf("Veuillez-vous entrer le id_etudiant dont vous voulez charger!\n");
                    scanf("%d",&opt5);
                    printf("veuillez-vous entrer le montant que vous voulez charger!\n");
                    scanf("%f",&opt6);
                    printf("veuillez-vous entrer la description pour cette operation!\n");
                    scanf("%s",opt7);
                    crediter(opt5,opt6,opt7,bloc2);
                    break;
        case 6 :
                    printf("Veuillez-vous entrer le id_etudiant que vous voulez lui depenser!\n");
                    scanf("%d",&opt8);
                    printf("veuillez-vous entrer le montant que vous voulez depenser !\n");
                    scanf("%f",&opt9);
                    printf("veuillez-vous entrer la description pour cette operation!\n");
                    scanf("%s",opt10);
                    payer(opt8,opt9,opt10,bloc2);
                    break;
        case 7 :
                    printf("Veuillez-vous entrer le id_etudiant en tant que l'origine!\n");
                    scanf("%d",&opt11);
                    printf("Veuillez-vous entrer le id_etudiant en tant que la destination!\n");
                    scanf("%d",&opt12);
                    printf("veuillez-vous entrer le montant que vous voulez depenser c!\n");
                    scanf("%f",&opt13);
                    printf("veuillez-vous entrer la description pour cette operation!\n");
                    scanf("%s",opt14);
                    transfert(opt11,opt12,opt13,opt14,bloc2);
                    break;
        case 8 :    printf("Bye-Bye!!!\n");
                    break;
        default :   printf("veuillez-vous entrer correctement!!!\n");
                    break;
            }
    }
    deleteList(bloc2);
    return 0;
}
//    BlockChain bloc1=NULL;
//    BlockChain bloc2;
//    bloc1=ajouterBlock(bloc1);
//    bloc1->trans_jour=ajouterTransaction(1,100,"recharger 100 euro",bloc1->trans_jour);
//    bloc1->trans_jour=ajouterTransaction(2,100,"recharger 100 euro",bloc1->trans_jour);
//    bloc1->trans_jour=ajouterTransaction(3,100,"recharger 100 euro",bloc1->trans_jour);
//    crediter(1,50,"test crediter",bloc1);
//    payer(2,20,"test payer",bloc1);
//    transfert(1,3,40,"test trans",bloc1);
//    bloc2=ajouterBlock(bloc1);
//    bloc2->trans_jour=ajouterTransaction(4,99.99,"recharger 99.99 euro",bloc2->trans_jour);
//    transfert(2,4,15.7,"test trans",bloc2);
//    printf("*********************************Affichahge la liste des blocs de la BlockChain !*****************\n\n");
//    afficherBlockChain(bloc2);
//    printf("*********************************Affichahge toutes les transactions d'un bloc 2!*******************\n\n");
//    afficherlesTransactionBloc(bloc2,2);
//    printf("*********************************Affichahge toutes les transactions d'un bloc 1!*******************\n\n");
//    afficherlesTransactionBloc(bloc2,1);
//    printf("*********************************Affichahge toutes les transactions du jour(bloc1) pour un etudiant(2)!*******************\n\n");
//    afficherTransactionJourpouretudiant(2,1,bloc2);
//    printf("*********************************Affichahge l'historique pour un etudiant(1)!*******************\n\n");
//    afficherHistorique(1,bloc2);
//    printf("\n-----\nsolde de etu 1: %f\n\n",soldeEtudiant(1,bloc2));
//    printf("*********************************Affichahge l¡¯historique pour un etudiant(3)!*******************\n\n");
//    afficherHistorique(3,bloc2);
//    printf("\n-----\nsolde de etu 3: %f\n\n",soldeEtudiant(3,bloc2));
//
//    deleteList(bloc2);
//    printf("*********************************Affichahge la liste des blocs de la BlockChain !*****************\n\n");
//    afficherBlockChain(bloc2);
//
//
//
//    return 0;
//
//}

