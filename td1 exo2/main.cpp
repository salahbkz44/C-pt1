#include <iostream>

using namespace std;
struct element{
    int val;
    element *suiv;
    element *prec;
};
element *liste=nullptr;
void inserer(){
    if(liste==nullptr){
        liste=new(element);
        cout<<"entrez la valeur";
        cin>>liste->val;
    }else{
        element *e;
        e=new(element);
        cout<<"entrez la valeur";
        cin>>e->val;
        e->suiv=liste;
        liste=e;
    }
}
void doubleChain(){
    element *l;
    l=liste;
    if(liste!=nullptr){
        while(l->suiv!=nullptr){
            l->suiv->prec=l;
            l=l->suiv;
        }
    }
}
void afficher() {
    element* e = liste; // Start from the beginning of the list
    bool fin=false;

    while (e != nullptr&&!fin) {
        cout <<endl<<e->val;
        if(e->suiv!= nullptr){ // Move to the next element{
            e = e->suiv;}else{
            fin=true;}
    }
    cout<<"\nl3ks\n";
    while(e != nullptr){
        cout<<endl<<e->val;
        e=e->prec;
    }
}

int main()
{
    int c;
    c=0;
    while(c!=4){
        cout<<"\n1.ajouter\n2.l3ks\n3.afficher\n votre choix:";
        cin>>c;
        switch(c){
        case 1:
            inserer();break;
        case 2:
            doubleChain();break;
        case 3:
            afficher();break;
        }
    }

    return 0;
}
