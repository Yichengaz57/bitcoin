
#include "bitcoin.h"

T_Transaction *ajouterTransaction(int idEtu, float montant, char *descr, T_Transaction *listeTransaction)
{
    T_Transaction *new_trans = (T_Transaction *)malloc(sizeof(T_Transaction));
    new_trans->student = idEtu;
    new_trans->montant = montant;
    new_trans->description = descr;
    new_trans->next = listeTransaction;

    return new_trans;
}

BlockChain ajouterBlock(BlockChain bc)
{
    T_Block *new_block = (T_Block *)malloc(sizeof(T_Block));
    if (bc == NULL)
    {
        new_block->identifiant = 1;
        new_block->date = today;
        new_block->trans_jour = NULL;
    }
    else
    {
        new_block->identifiant = bc->identifiant + 1;
        new_block->date = bc->date + 1;
        new_block->trans_jour = NULL;
    }
    new_block->next = bc;
    return new_block;
}

float totalTransactionEtudiantBlock(int idEtu, T_Bloc k b)
{
    float total = 0;
    T_Transaction *p;
    for (p = b.trans_jour; p != NULL; p = p->next) //while
    {
        if (p->student == idEtu)
        {
            total = total + p->montant;
        }
    }
    return total;
}

float soldeEtudiant(int idEtu, BlockChain bc)
{
    BlockChain b;
    float solde = 0;
    for (b = bc; b != NULL; b = b->next)
    {
        solde = solde + totalTransactionEtudiantBlock(idEtu, *b);
    }
    return solde;
}

void crediter(int idEtu, float montant, char *descr, BlockChain bc)
{
    bc->trans_jour = ajouterTransaction(idEtu, montant, descr, bc->trans_jour);
}

int payer(int idEtu, float montant, char *descr, BlockChain bc)
{
    if (soldeEtudiant(idEtu, bc) >= montant)
    {
        bc->trans_jour = ajouterTransaction(idEtu, (-1) * montant, descr, bc->trans_jour);
        return 1;
    }
    else
    {
        return 0;
    }
}

void consulter(int idEtu, BlockChain bc)
{
    printf("Le solde de l'etudiant %d est %f\n", idEtu, soldeEtudiant(idEtu, bc));
    int dernier = 5;
    BlockChain p = bc;
    while (dernier > 0 && p->next != NULL)
    {
        T_Transaction *t = p->trans_jour;
        while (t != NULL)
        {
            if (t->student == idEtu && dernier > 0)
            {
                printf("la date de la transcription est : %ld ", p->date);
                printf("Montant: %f , description : %s \n", t->montant, t->description);
                dernier--;
            }
            if (dernier == 0)
                return;
            t = t->next;
        }
        if (dernier == 0)
            return;
        p = p->next;
    }
}

int transfert(int idSource, int idDestination, float montant, char *descr, BlockChain bc)
{
    if (payer(idSource, montant, descr, bc))
    {
        crediter(idDestination, montant, descr, bc);
        return 1;
    }
    return 0;
}

/*----------------------------function supplementaire---------------------------------------------------*/

void afficherBlockChain(BlockChain bc)
{
    BlockChain p;
    for (p = bc; p != NULL; p = p->next)
    {
        printf("identifiant de bloc: %d    date: %ld\n-------\n", p->identifiant, p->date);
    }
}

void afficherlesTransactionBloc(BlockChain bc, int idbloc)
{
    BlockChain p = bc;
    for (p = bc; p != NULL; p = p->next)
    {
        if (p->identifiant == idbloc)
        {
            T_Transaction *t = p->trans_jour;
            while (t != NULL)
            {
                printf("le numero d'etudiant: %d\nle montant = %+.2f\ndescription: %s\n-------------------\n", t->student, t->montant, t->description);
                t = t->next;
            }
        }
    }
}

void afficherTransactionJourpouretudiant(int idEtu, int idbloc, BlockChain bc)
{
    BlockChain p = bc;
    for (p = bc; p != NULL; p = p->next)
    {
        if (p->identifiant == idbloc)
        {
            T_Transaction *t = p->trans_jour;
            while (t != NULL)
            {
                if (t->student == idEtu)
                {
                    printf("le numero d'etudiant: %d\nle montant = %+.2f\ndescription: %s\n-------------------\n", t->student, t->montant, t->description);
                }
                t = t->next;
            }
        }
    }
}
void afficherHistorique(int idEtu, BlockChain bc)
{
    BlockChain p;
    for (p = bc; p != NULL; p = p->next)
    {
        afficherTransactionJourpouretudiant(idEtu, p->identifiant, bc);
    }
}
void deleteList(BlockChain bc)
{

    BlockChain tempbc1 = bc;
    BlockChain tempbc2;
    while (tempbc1 != NULL)
    {
        tempbc2 = tempbc1;
        T_Transaction *temptr1 = tempbc2->trans_jour;
        T_Transaction *temptr2;
        while (temptr1 != NULL)
        {
            temptr2 = temptr1;
            temptr1 = temptr1->next;
            free(temptr2);
        }

        tempbc1 = tempbc1->next;
        free(tempbc2);
    }
}
