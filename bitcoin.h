#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define today 20191114

//Les declaration des structures

typedef struct Transaction T_Transaction;
struct Transaction{
    int student;
    float montant;
    char * description;
    T_Transaction * next;
};
typedef struct Block T_Block;
struct Block{
    int identifiant;
    long date;
    T_Transaction * trans_jour ;
    T_Block * next;
};

typedef T_Block * BlockChain;

//Les declaration des fonctions de base

extern T_Transaction * ajouterTransaction(int idEtu, float montant, char * descr, T_Transaction * listeTransaction);
extern BlockChain ajouterBlock(BlockChain bc);
extern float totalTransactionEtudiantBlock(int idEtu, T_Block b);
extern float soldeEtudiant(int idEtu, BlockChain bc);
extern void crediter(int idEtu, float montant, char *descr, BlockChain bc);
extern int payer(int idEtu, float montant, char *descr, BlockChain bc);
extern void consulter(int idEtu, BlockChain bc);
extern int transfert(int idSource, int idDestination, float montant, char *descr, BlockChain bc);
/*----------------------------Les functions supplementaires---------------------------------------------------*/
extern void afficherBlockChain(BlockChain bc);
extern void afficherlesTransactionBloc(BlockChain bc,int idbloc);
extern void afficherTransactionJourpouretudiant(int idEtu,int idbloc,BlockChain bc);
extern void afficherHistorique(int idEtu, BlockChain bc);
extern void deleteList (BlockChain bc);

