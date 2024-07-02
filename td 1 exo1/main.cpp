#include <iostream>

using namespace std;
struct produit{
    string code_pro;
    string designation;
    string um;
    float pua_ht ;
    float qte;
    float tva;
};
struct element{
    produit product;
    element *suiv;
};

element *liste=nullptr;
void ajouter(){
    if(liste==nullptr){
        liste=new element;
        cout<<"entrez lecode_pro:";
        cin>>liste->product.code_pro;
        cout<<"entrez designation:";
        cin>>liste->product.designation;
        cout<<"entrez um:";
        cin>>liste->product.um;
        cout<<"entrez pua_ht:";
        cin>>liste->product.pua_ht;
        cout<<"entrez qte:";
        cin>>liste->product.qte;
        cout<<"entrez tva:";
        cin>>liste->product.tva;
   } else {
    element *E;
    E = new element;
    cout << "entrez lecode_pro:";
    cin >> E->product.code_pro;
    cout << "entrez designation:";
    cin >> E->product.designation;
    cout << "entrez um:";
    cin >> E->product.um;
    cout << "entrez pua_ht:";
    cin >> E->product.pua_ht;
    cout << "entrez qte:";
    cin >> E->product.qte;
    cout << "entrez tva:";
    cin >> E->product.tva;
    E->suiv = liste; // Link the new element to the existing list
    liste = E; // Update the 'liste' pointer to the new element
}
}
void afficher() {
    element* e = liste; // Start from the beginning of the list

    while (e != nullptr) {
        cout << endl << endl << "code_pro: " << e->product.code_pro << endl;
        cout << "designation: " << e->product.designation << endl;
        cout << "um: " << e->product.um << endl;
        cout << "pua_ht: " << e->product.pua_ht << endl;
        cout << "qte: " << e->product.qte << endl;
        cout << "tva: " << e->product.tva << endl << endl << endl;
        e = e->suiv; // Move to the next element
    }
}
void afficher_total(){
    int num=0,ht=0,tva=0;
    element *e;
    e=liste;
    while (e!=nullptr)
    {
        num++;
        ht=ht+(e->product.pua_ht*e->product.qte);
        tva=tva+((e->product.pua_ht*e->product.qte)*e->product.tva);
        e=e->suiv;
    }
    int ttc=ht+tva;
    cout<<"nommbre des produit acheté: "<<num<<endl<<"total tva:"<<tva<<endl<<"montant totale avant tax"<<ht<<endl<<"ttc:"<<ttc<<endl;
}
void difference_n(){
    int a;
    int num=0,ht=0,tva=0;
    element *e;
    e=liste;
    while (e!=nullptr)
    {
        num++;
        ht=ht+(e->product.pua_ht*e->product.qte);
        tva=tva+((e->product.pua_ht*e->product.qte)*e->product.tva);
        e=e->suiv;
    }
    int ttc=ht+tva;
    cout<<"ttc:"<<ttc<<endl;
    cout<<"entrez le montant payé: ";
    cin>>a;
    int dif;
    if(a<ttc){
        cout<<"nn";
    }else{
        dif=a-ttc;
        cout<<"prend:"<<dif<<endl;
    }

}
void supprimer(){
    element *e;
    e=liste;
    element *s;
    cout<<"entrez code:"<<endl;
    string code;
    cin>>code;
    bool found=false;
    while((!found)&&((e->suiv!=nullptr)||(liste->suiv==nullptr)))
    {
        if(e==liste&&e->product.code_pro==code){
            found=true;
            s=e;
            liste=liste->suiv;
           }else{
               if(e->suiv->product.code_pro==code)
                {
                    found=true;
                    s=e->suiv;
                    e->suiv=s->suiv;

                }else{
                   e=e->suiv;
                }
           }


    }
    if(found==true){
            delete(s);
    }else{
        cout<<"code pas";
    }
}



void vider(){
    element *e;
    while(liste!=nullptr){

    e=liste;
    liste=liste->suiv;
    delete e;
    }
}
int main()
{
    int choice;
    while(choice!=8){
            cout<<"enter your choice\n1.ajouter\n2.afficher\n3.afficher le nombre et ttc\n4.difference\n5.supprimer\n6.afficher le prix max et le prix min\n7.vider la liste\n8.arret\n votre choix:";
        cin>>choice;
        switch(choice){
    case 1 :
        ajouter();break;
    case 2 :
        afficher();break;
    case 3 :
        afficher_total();break;
    case 4 :
        difference_n();break;
    case 5 :
        supprimer();break;
    case 7 :
        vider();break;
    }
    }
    return 0;
}
