#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include<cstdio>
#include<windows.h>


using namespace std;
struct onc
{
     int mat;
    char nobb[20], date[20]; 
    char nom[20] , prenom[20];
};
struct bijou
{   int mat;
    char nobb[20], date[20]; 
    char nom[20] , prenom[20], matiere[20] ,type[20];
    char poids[20];
};
struct pm
{     int mat;
    char nobb[20],date[20]; 
    char nom[20] , prenom[20], matiere[20],prd[20] ;
    char poids[20],valeurs[20];
};
struct man
{    int mat;
    char nobb[20], date[20]; 
    char nom [20] , prenom [20],no[20],langue[20],po[20];
     char npage[20] ;
};
struct obj
{      int mat;
    char nobb[20], date[20]; 
    char nom[20] , prenom[20];
    
};
void showMenuAccueil();
void showMenuONC();
void showMenuBPMD(string);
int objetClasse(string);
int ObjetNonClasse();
void readfile(string);
string getnamefile(int);
void ajoutonc();
void ajoutonc(onc ,string );
void classer();
void supponc(onc);
void supper(string);
void modifier(string);
void rechercher(string);
void settting();


//intttttttttttttt*t*****************************************
int main()
{

     
    char c;
    do
    {   system("Color 6C");
        showMenuAccueil();
        cin>>c;
        switch(c)
        {
        case '1':
            system("cls");
            system("Color 0D");
            ObjetNonClasse();
            break;
        case '2':
            system("cls");
            system("Color 0E");
            objetClasse("Bijou");
            break;
        case '3':
            system("cls");
             system("Color 0B");
            objetClasse("Piéce");
            break;
        case '4':
            system("cls");
            system("Color 0A");
            objetClasse("Manuscrit");
            break;
        case '5':
            system("cls");
             system("Color 0B");
            objetClasse("Objet");
            break;
        case '6':
            system("cls");
            settting();
            system("PAUSE");
            break;
        case '7':
            cout<<"voulez vous quitter le programme o/n ??\n"<<endl;
            cin>>c;
            system("EXIT");
            break;
        }
        system("cls");
    }
    while(c!='o');
    return 0;
}


void showMenuAccueil()
{
    
    cout<<"\n\n\n\n";
    cout<<"  #####################################################\n";
    cout<<"\t\t MENU PRINCIPAL \n";
    cout<<"  #####################################################\n";
    cout<<"     1.  OBJET RECU"<<endl;
    cout<<"     2.  LES BIJOUX "<<endl;
    cout<<"     3.  LES PIECES DE MONNAIS"<<endl;
    cout<<"     4.  LES MANUSCRITES."<<endl;
    cout<<"     5.  LES OBJETS DIVERS"<<endl;
    cout<<"     6.  PARAMETRES"<<endl;
    cout<<"     7.  QUITTER"<<endl;
    cout<<"  #####################################################"<<endl;
    cout<<"\t Votre choix :   "<<endl;
}
void showMenuONC()
{     
    cout<<"\n\n\n\n";
    cout<<"  #####################################################\n";
    cout<<"\t\t Menu Objet reçu \n";
    cout<<"  #####################################################\n";
    cout<<"     1.  Ajouter un objet."<<endl;
    cout<<"     2.  Classer un objet. "<<endl;
    cout<<"     3.  Afficher les objets."<<endl;
    cout<<"     4.  Supprimer un Objet."<<endl;
    cout<<"     5.  Retour."<<endl;
    cout<<"  #####################################################"<<endl;
    cout<<"\t Votre choix :   "<<endl;
}
int ObjetNonClasse()
{char c;
    do
    {   system("Color 7B");
        showMenuONC();
        cin>>c;
        switch(c)
        {
        case '1':
            system("cls");
            ajoutonc();
            system("PAUSE");
            break;
        case '2':
            system("cls");
            classer();
            system("PAUSE");
            break;
        case '3':
            system("cls");
            readfile("oonncc");
            system("PAUSE");
            break;
        case '4':
            system("cls");
            supper("oonncc");
            system("PAUSE");
            break;
        case '5':
            return 1;
        }
        system("cls");
    }
    while(true);
}

void showMenuBPMD(string type)
{
    cout<<"\n\n\n\n";
    cout<<"  #####################################################\n";
    cout<<"\t\t  Menu "<<type<<endl;
    cout<<"  #####################################################\n";
    cout<<"     1.  Afficher les "<<type<<"s."<<endl;
    cout<<"     2.  Rechecher un "<<type<<endl;
    cout<<"     3.  Modifier un "<<type<<endl;
    cout<<"     4.  Supprimer un "<<type<<endl;
    cout<<"     5.  Retour."<<endl;
    cout<<"  #####################################################"<<endl;
    cout<<"\t Votre choix :   "<<endl;
}

int objetClasse(string type)
{char c;
    do
    {
        showMenuBPMD(type);
        cin>>c;
        switch(c)
        {
        case '1':
            system("cls");
            readfile(type);
            system("PAUSE");
            break;
        case '2':
            system("cls");
            rechercher(type);
            system("PAUSE");
            break;
        case '3':
            system("cls");
            modifier(type);
            system("PAUSE");
            break;
        case '4':
            system("cls");
            supper(type);
            system("PAUSE");
            break;
        case '5':
            return 1;
        }
        system("cls");
    }
    while(true);
};



 string getnamefile(int n )
 {
  string line ;
  ifstream fich;
  fich.open("setting.txt");
  
   int i=1;
   if(!fich.is_open()){
    return"errour";
   } else 
   { while(i<=n && getline(fich, line))
{
   i=i+1;
}
}
 fich.close();
return line;
}

void  readfile(string type)
{
 
   if(type=="oonncc")
     {  ifstream myfileeea;
    myfileeea.open(getnamefile(1),ios::binary |ios:: in);
    if(myfileeea.is_open()){
    onc oonc;
    while(myfileeea.read((char*)&oonc,sizeof(oonc)))
    {
     cout<<"****************nv objet************"<<endl;
   cout<<"nom d'objet : " << oonc.nobb<<endl;
   cout<<"date  : " <<oonc.date<<endl; 
   cout<<"prenom de donneur : " <<oonc.prenom<<endl;
   cout<<"nom de donneur : "<<oonc.nom<<endl ;
   cout<<"lee matricule : " <<oonc.mat<<endl;
    }  
    myfileeea.close();   
    
   }else{cout<<"fichier introuvable,";};

   }
   
    if (type=="Bijou") 
     {  ifstream myfile22;
    myfile22.open(getnamefile(2),ios::binary |ios:: in);
    if(myfile22.is_open()){
    bijou bij;
    while(myfile22.read((char*)&bij,sizeof(bij)))
    {
     cout<<"****************nv objet************"<<endl;
   cout<<"nom d'objet : " << bij.nobb<<endl;
   cout<<"date  : " <<bij.date<<endl; 
   cout<<"prenom de donneur : " <<bij.prenom<<endl;
   cout<<"nom de donneur : "<<bij.nom<<endl ;
   cout<<"nom de matricule : " <<bij.mat<<endl;
   cout<<"la matière de bijoux : "<<bij.matiere<<endl;
   cout<<"le poids de bijoux : "<<bij.poids<<endl;
   cout<<"le type de bijoux : "<<bij.type<<endl;
    }  
    myfile22.close();   
    
   }else{cout<<"fichier introuvable,";};
   }
   
    if (type=="Piéce") 
     {  ifstream myfile22;
    myfile22.open(getnamefile(3),ios::binary |ios:: in);
    if(myfile22.is_open()){
    pm pmmm;
    while(myfile22.read((char*)&pmmm,sizeof(pm)))
    {
     cout<<"****************nv objet************"<<endl;
   cout<<"nom d'objet : " << pmmm.nobb<<endl;
   cout<<"date  : " <<pmmm.date<<endl; 
   cout<<"prenom de donneur : " <<pmmm.prenom<<endl;
   cout<<"nom de donneur : "<<pmmm.nom<<endl ;
   cout<<"nom de matricule : " <<pmmm.mat<<endl;
   cout<<"la matière de piéce : "<<pmmm.matiere<<endl;
   cout<<"la valeur de piéce : "<<pmmm.valeurs<<endl;
   cout<<"la période de piéce : "<<pmmm.prd<<endl;
    }  
    myfile22.close();   
    
   }else{cout<<"fichier introuvable,";};
   }

 if (type=="Manuscrit") 
     {  ifstream myfile22;
    myfile22.open(getnamefile(4),ios::binary |ios:: in);
    if(myfile22.is_open()){
    man mann;
    while(myfile22.read((char*)&mann,sizeof(mann)))
    {
    cout<<"****************nv objet******************"<<endl;
   cout<<"nom d'objet : " << mann.nobb<<endl;
   cout<<"date  : " <<mann.date<<endl; 
   cout<<"prenom de donneur : " <<mann.prenom<<endl;
   cout<<"nom de donneur : "<<mann.nom<<endl ;
   cout<<"nom de matricule : " <<mann.mat<<endl;
   cout<<"la langue  : "<<mann.langue<<endl;
   cout<<"le nombre des page : "<<mann.npage<<endl;
   cout<<"nom  de l'auteur : "<<mann.no<<endl;
   cout<<"nom  de l'auteur : "<<mann.po<<endl;
    }  
    myfile22.close();   
    
   }else{cout<<"fichier introuvable,";};
   }
   if(type=="Objet")
     {  ifstream myfile99;
    myfile99.open(getnamefile(5),ios::binary |ios:: in);
    if(myfile99.is_open()){
    obj objj;
    while(myfile99.read((char*)&objj,sizeof(obj)))
    {
     cout<<"****************nv objet d'evers****************"<<endl;
   cout<<"nom d'objet : " << objj.nobb<<endl;
   cout<<"date  : " <<objj.date<<endl; 
   cout<<"prenom de donneur : " <<objj.prenom<<endl;
   cout<<"nom de donneur : "<<objj.nom<<endl ;
   cout<<"nom de matricule : " <<objj.mat<<endl;
    }  
    myfile99.close();   
    
   }else{cout<<"fichier introuvable,";};

   }
   
   };
   


  
 void ajoutonc(onc e,string chemin){
  ofstream myfile;
  myfile.open(chemin,ios::out |ios:: binary|ios::app);
  if(myfile.is_open()){  myfile.write((char*)&e,sizeof(onc)) ; 
  myfile.close();
  cout<<"ajout terminé avec succes :)"<<endl;}
  else cout<<", création de fichier échouée"<<endl;
  }


void ajoutonc(){
    int maat;
   onc oonc;
   cout<<"nom d'objet : " ;
   cin>>oonc.nobb;
   cout<<"date  : " ;
   cin>>oonc.date;
   cout<<"prenom de donneur : " ;
   cin>>oonc.prenom;
    cout<<"nom de donneur : " ;
    cin>>oonc.nom;
      fstream myfile33;
     myfile33.open("mat.bin",ios::out |ios:: binary|ios::app);
     myfile33.seekg(0,ios::end);
     if(myfile33.tellg()==0){
        maat=1;
     myfile33.seekg(0,ios::beg);
     myfile33.write((char*)&maat,sizeof( int)) ; 
     myfile33.seekg(0,ios::beg);
     myfile33.close();
     oonc.mat=1;
      } else {myfile33.close();
        fstream myfileeea;
    myfileeea.open(getnamefile(1),ios::binary |ios:: in);
    onc rj;
    while(myfileeea.read((char*)&rj,sizeof(onc))){};
      maat=rj.mat;
      maat=maat+1;
      oonc.mat=maat;
      myfileeea.close();
      };

     
    string ONC=getnamefile(1);
  ajoutonc(oonc,ONC);}





    void classer(){
    bool vv=false;
     int nn; 
    char nuum;
   readfile("oonncc");
    fstream myfileeea;
    myfileeea.open(getnamefile(1),ios::binary |ios:: in);
            if(!myfileeea.is_open()){goto exit_loop878;}
    cout<<endl;
    cout<<"donner le matricule de l'objet que vous voulez classer: ";cin>>nn;
    cout<<endl;
    cout<<"vous voulez le classer en quelle catégorie : "<<endl;
    cout<<"     1.  Les bijoux. "<<endl;
    cout<<"     2.  Les pièces de monnaie."<<endl;
    cout<<"     3.  Les manuscrits."<<endl;
    cout<<"     4.  Objets divers."<<endl;
    system("color 81");
    cout<<"taper un num: ";cin>>nuum;
    do{ 
     
     switch (nuum)  
     {   
           case '1': 
          {  system("cls");
          

            ifstream myfile55;
            myfile55.open(getnamefile(1),ios::binary |ios:: in);
            if(myfile55.is_open()){
            onc oonc;
             while(myfile55.read((char*)&oonc,sizeof(onc)))
              {
               if(oonc.mat==nn){
                  bijou bij;
            cout<<"avant de classer l'objet a la classe bijou vous  devez ajouter des informations supplimentaires";
            cout<<endl;
            cout<<"donnez la matiere de la bijou: "; cin>>bij.matiere;cout<<endl;
            cout<<" donnez le poids de bijou : ";cin>>bij.poids;cout<<endl;
            cout<<" donnez le type de bijou : ";cin>>bij.type;cout<<endl;
           
                strcpy(bij.prenom,oonc.prenom);
                strcpy(bij.date,oonc.date);
                strcpy(bij.nobb,oonc.nobb);
                strcpy(bij.nom,oonc.nom);
                strcpy(bij.matiere,bij.matiere);
                strcpy(bij.poids,bij.poids);
                strcpy(bij.type,bij.type);
                
                bij.mat=nn;
                vv=true;
                ofstream myfile33;
                myfile33.open(getnamefile(2),ios::out |ios:: binary|ios::app);
                if(myfile33.is_open())
                {  myfile33.write((char*)&bij,sizeof(bijou)) ; 
                 myfile33.close();
                  //tura azdnkhdem les suppresssion ilkeeel
                  supponc(oonc);
                 cout<<"classification terminé avec succes :)"<<endl;
                  myfile55.close();
                goto exit_loop114;
                 break;
                 }
                 else {cout<<", création de fichier échouée"<<endl;}   
               } 
              } if(vv==false){myfile55.close();cout<<"le matricule n'existe pas"<<endl; goto exit_loop114;};
                 myfile55.close();
            } else {cout<<" fichier objet non classé n'existe pas"<<endl;};
            system("PAUSE");

            break;
            } 
         
          case '2': 
          {  system("cls");
          

            ifstream myfile55;
            myfile55.open(getnamefile(1),ios::binary |ios:: in);
            if(myfile55.is_open()){
            onc oonc;
             while(myfile55.read((char*)&oonc,sizeof(onc)))
              {
               if(oonc.mat==nn){
                  pm pmmm;
            cout<<"avant de classer l'objet a la classe piéces monnais vous  devez ajouter des informations supplimentaires";
            cout<<endl;
            cout<<"donnez la matiere de la piéce: "; cin>>pmmm.matiere;cout<<endl;
            cout<<" donnez le poids de piece : ";cin>>pmmm.poids;cout<<endl;
            cout<<" donnez le valeurs de piece : ";cin>>pmmm.valeurs;cout<<endl;
            cout<<"période de son utilisation. :";cin>>pmmm.prd; cout<<endl;
                strcpy(pmmm.prenom,oonc.prenom);
                strcpy(pmmm.date,oonc.date);
                strcpy(pmmm.nobb,oonc.nobb);
                strcpy(pmmm.nom,oonc.nom);
                strcpy(pmmm.matiere,pmmm.matiere);
                strcpy(pmmm.poids,pmmm.poids);
                strcpy(pmmm.valeurs,pmmm.valeurs);
                
                pmmm.mat=nn;
                vv=true;
                ofstream myfile33;
                myfile33.open(getnamefile(3),ios::out |ios:: binary|ios::app);
                if(myfile33.is_open())
                {  myfile33.write((char*)&pmmm,sizeof(pm)) ; 
                 myfile33.close();
                  //tura azdnkhdem les suppresssion ilkeeel
                  supponc(oonc);
                 cout<<"classification terminé avec succes :)"<<endl;
                  myfile55.close();
                goto exit_loop114;
                 break;
                 }
                 else {cout<<", création de fichier échouée"<<endl;}   
               } 
              } if(vv==false){myfile55.close();cout<<"le matricule n'existe pas"<<endl; goto exit_loop114;};
                 myfile55.close();
            } else {cout<<" fichier objet non classé n'existe pas"<<endl;};
            system("PAUSE");

            break;
            }

         case '3': 
          {  system("cls");
          

            ifstream myfile55;
            myfile55.open(getnamefile(1),ios::binary |ios:: in);
            if(myfile55.is_open()){
            onc oonc;
             while(myfile55.read((char*)&oonc,sizeof(onc)))
              {
               if(oonc.mat==nn){
                  man mann;
            cout<<"avant de classer l'objet a la classe manuscrits vous  devez ajouter des informations supplimentaires";
            cout<<endl;
           cout<<"donnez prenom  de l'auteur : ";cin>>mann.po;cout<<endl;
           cout<<"donnez nom  de l'auteur : ";cin>>mann.no;cout<<endl;
            cout<<" donnez le nombre de pages: ";cin>>mann.npage;cout<<endl;
            cout<<" donnez le langue d'edition : ";cin>>mann.langue;cout<<endl;
                strcpy(mann.nobb,oonc.nobb);
                strcpy(mann.no,mann.no);
                strcpy(mann.po,mann.po);
                strcpy(mann.prenom,oonc.prenom);
                strcpy(mann.date,oonc.date);
                strcpy(mann.langue,mann.langue);
              
                strcpy(mann.npage,mann.npage);
                strcpy(mann.nom,oonc.nom);

                mann.mat=nn;
                vv=true;
                ofstream myfile33;
                myfile33.open(getnamefile(4),ios::out |ios:: binary|ios::app);
                if(myfile33.is_open())
                {  myfile33.write((char*)&mann,sizeof(man)) ; 
                 myfile33.close();
                  
                  supponc(oonc);
                 cout<<"classification terminé avec succes :)"<<endl;
                  myfile55.close();
                goto exit_loop114;
                 break;
                 }
                 else {cout<<", création de fichier échouée"<<endl;}   
               } 
              } if(vv==false){myfile55.close();cout<<"le matricule n'existe pas"<<endl; goto exit_loop114;};
                 myfile55.close();
            } else {cout<<" fichier objet non classé n'existe pas"<<endl;};
            system("PAUSE");
            break;
            }    
         case '4': 
          {  system("cls");
          

            ifstream myfile55;
            myfile55.open(getnamefile(1),ios::binary |ios:: in);
            if(myfile55.is_open()){
            onc oonc;
             while(myfile55.read((char*)&oonc,sizeof(onc)))
              {
               if(oonc.mat==nn){
                  obj objj;
            
                strcpy(objj.nobb,oonc.nobb);
                strcpy(objj.prenom,oonc.prenom);
                strcpy(objj.date,oonc.date);
                strcpy(objj.nom,oonc.nom);

                objj.mat=nn;
                vv=true;
                ofstream myfile33;
                myfile33.open(getnamefile(5),ios::out |ios:: binary|ios::app);
                if(myfile33.is_open())
                {  myfile33.write((char*)&objj,sizeof(obj)) ; 
                 myfile33.close();
                  supponc(oonc);
                 cout<<"classification terminé avec succes :)"<<endl;
                  myfile55.close();
                goto exit_loop114;
                 break;
                 }
                 else {cout<<", création de fichier échouée"<<endl;}   
               } 
              } if(vv==false){myfile55.close();cout<<"le matricule n'existe pas"<<endl; goto exit_loop114;};
                 myfile55.close();
            } else {cout<<" fichier objet non classé n'existe pas"<<endl;};
            system("PAUSE");
            break;
            }   
         

     };
     
    }while(nuum<0||nuum>4);
     exit_loop114: ;
       exit_loop878: ;
 };
   
   void supponc(onc e){
    ifstream myfile1;
    myfile1.open(getnamefile(1), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    onc ee;
   while (myfile1.read((char*)&ee,sizeof(onc)))
   {
     if (ee.mat!=e.mat)
     {
         myfile2.write((char*)&ee,sizeof(onc));
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(1), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&ee,sizeof(onc)))
   {
       myfile4.write((char*)&ee,sizeof(onc));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   };
    
    //*******suppressiooonnnnn*******.************************************
  void supper(string type){
   long int jat;
   bool vr=false;

   if(type=="oonncc")
   { 
    readfile("oonncc");
     fstream myfileeea;
    myfileeea.open(getnamefile(1),ios::binary |ios:: in);
            if(!myfileeea.is_open()){goto exit_loop020;}
    cout<<endl<<"donnez le matricule de l'objet que vous voulez supprimer: ";cin>>jat;
    
   ifstream myfile1;
    myfile1.open(getnamefile(1), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    onc ee;
   while (myfile1.read((char*)&ee,sizeof(onc)))
   {
     if (ee.mat!=jat)
     {
         myfile2.write((char*)&ee,sizeof(onc));
     };
      if (ee.mat==jat)
     {
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(1), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&ee,sizeof(onc)))
   {
       myfile4.write((char*)&ee,sizeof(onc));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"vous avez donnez un matricule qui n'existe pas"<<endl;}

   }
  //*********
   if(type=="Bijou")
   { 
    readfile(type);
    
    
   ifstream myfile1;
    myfile1.open(getnamefile(2), ios::in | ios::binary);
    if(!myfile1.is_open()){goto exit_loop2222;}
    cout<<endl<<"donnez le matricule de l'objet que vous voulez supprimer: ";cin>>jat;
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    bijou biij;
   while (myfile1.read((char*)&biij,sizeof(bijou)))
   {
     if (biij.mat!=jat)
     {
         myfile2.write((char*)&biij,sizeof(bijou));
     };
      if (biij.mat==jat)
     {
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(2), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&biij,sizeof(bijou)))
   {
       myfile4.write((char*)&biij,sizeof(bijou));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"vous avez donnez un matricule qui n'existe pas"<<endl;}

   };
   //********
    if(type=="Piéce")
   { 
    readfile(type);
    
   ifstream myfile1;
    myfile1.open(getnamefile(3), ios::in | ios::binary);
    if(!myfile1.is_open()){goto exit_loop2022;}
    cout<<endl<<"donnez le matricule de l'objet que vous voulez supprimer: ";cin>>jat;
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    pm pmm;
   while (myfile1.read((char*)&pmm,sizeof(pm)))
   {
     if (pmm.mat!=jat)
     {
         myfile2.write((char*)&pmm,sizeof(pm));
     };
      if (pmm.mat==jat)
     {
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(3), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&pmm,sizeof(pm)))
   {
       myfile4.write((char*)&pmm,sizeof(pm));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"vous avez donnez un matricule qui n'existe pas"<<endl;}

   };
   //******
    if(type=="Manuscrit")
   { 
    readfile(type);
   
    
   ifstream myfile1;
    myfile1.open(getnamefile(4), ios::in | ios::binary);
    if(!myfile1.is_open()){goto exit_loop2023;}
     cout<<endl<<"donnez le matricule de l'objet que vous voulez supprimer: ";cin>>jat;
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    man mann;
   while (myfile1.read((char*)&mann,sizeof(man)))
   {
     if (mann.mat!=jat)
     {
         myfile2.write((char*)&mann,sizeof(man));
     };
      if (mann.mat==jat)
     {
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(4), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&mann,sizeof(man)))
   {
       myfile4.write((char*)&mann,sizeof(man));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"vous avez donnez un matricule qui n'existe pas"<<endl;}

   };
   //*************************
    if(type=="Objet")
   { 
    readfile(type);
    
   ifstream myfile1;
    myfile1.open(getnamefile(5), ios::in | ios::binary);
    if(!myfile1.is_open()){goto exit_loop2024;}
    cout<<endl<<"donnez le matricule de l'objet que vous voulez supprimer: ";cin>>jat;
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    obj objj;
   while (myfile1.read((char*)&objj,sizeof(obj)))
   {
     if (objj.mat!=jat)
     {
         myfile2.write((char*)&objj,sizeof(obj));
     };
      if (objj.mat==jat)
     {
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(5), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&objj,sizeof(obj)))
   {
       myfile4.write((char*)&objj,sizeof(obj));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"vous avez donnez un matricule qui n'existe pas"<<endl;}

   }
    exit_loop020:;
     exit_loop2222:;
     exit_loop2022:;
     exit_loop2023:;
     exit_loop2024:;
  };
//*****************MODIFIIIIIIIIIIERRRRRRRR*********************
void modifier(string type){
    int  jat;
    bool vr;
    int choix;
 if(type=="Bijou")
   { 
    readfile(type);
     fstream myfileeea;
    myfileeea.open(getnamefile(2),ios::binary |ios:: in);
            if(!myfileeea.is_open()){goto exit_loop477;}
    cout<<endl<<"donnez le matricule de l'objet que vous voulez modifier: ";cin>>jat;
    cout<<endl;
    cout<<"q'est ce que vous voulez modifier"<<endl;
   
    cout<<"     1- le nom du donneur"<<endl;
    cout<<"     2- Le prenom du donneur"<<endl;
    cout<<"     3-  le nom de l'objet"<<endl;
    cout<<"     4-  La date "<<endl;
    cout<<"     5-  la matiere."<<endl;
    cout<<"     6-  le poid"<<endl;
    cout<<"     7-  le type."<<endl;
    cout<<"  *********************************************"<<endl;
    exit_if99: ;
    cout<<"veuillez donnez un chiffre: ";
    cin>>choix;
    if(choix==1){
    ifstream myfile1;
    myfile1.open(getnamefile(2), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    bijou biij;
   while (myfile1.read((char*)&biij,sizeof(bijou)))
   {
     if (biij.mat!=jat)
     {
         myfile2.write((char*)&biij,sizeof(bijou));
     };
      if (biij.mat==jat)
     {  
      cout<<"donner le neuveau nom de donneur: ";cin>>biij.nom;
       myfile2.write((char*)&biij,sizeof(bijou));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
   ofstream myfile4;
   myfile4.open(getnamefile(2), ios::out | ios::binary);
   ifstream myfile8;
   myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&biij,sizeof(bijou)))
   {
       myfile4.write((char*)&biij,sizeof(bijou));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };

   if(choix==2){
    ifstream myfile1;
    myfile1.open(getnamefile(2), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    bijou biij;
   while (myfile1.read((char*)&biij,sizeof(bijou)))
   {
     if (biij.mat!=jat)
     {
         myfile2.write((char*)&biij,sizeof(bijou));
     };
      if (biij.mat==jat)
     {  
      cout<<"donner le neuveau prenom: ";cin>>biij.prenom;
       myfile2.write((char*)&biij,sizeof(bijou));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(2), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&biij,sizeof(bijou)))
   {
       myfile4.write((char*)&biij,sizeof(bijou));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
    if(choix==3){
    ifstream myfile1;
    myfile1.open(getnamefile(2), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    bijou biij;
   while (myfile1.read((char*)&biij,sizeof(bijou)))
   {
     if (biij.mat!=jat)
     {
         myfile2.write((char*)&biij,sizeof(bijou));
     };
      if (biij.mat==jat)
     {  
      cout<<"donner le neuveau nom d'objet: ";cin>>biij.nobb;
       myfile2.write((char*)&biij,sizeof(bijou));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(2), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&biij,sizeof(bijou)))
   {
       myfile4.write((char*)&biij,sizeof(bijou));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==4){
    ifstream myfile1;
    myfile1.open(getnamefile(2), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    bijou biij;
   while (myfile1.read((char*)&biij,sizeof(bijou)))
   {
     if (biij.mat!=jat)
     {
         myfile2.write((char*)&biij,sizeof(bijou));
     };
      if (biij.mat==jat)
     {  
      cout<<"donner la nouvelle date: ";cin>>biij.date;
       myfile2.write((char*)&biij,sizeof(bijou));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(2), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&biij,sizeof(bijou)))
   {
       myfile4.write((char*)&biij,sizeof(bijou));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==5){
    ifstream myfile1;
    myfile1.open(getnamefile(2), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    bijou biij;
   while (myfile1.read((char*)&biij,sizeof(bijou)))
   {
     if (biij.mat!=jat)
     {
         myfile2.write((char*)&biij,sizeof(bijou));
     };
      if (biij.mat==jat)
     {  
      cout<<"donner la nouvelle matière: ";cin>>biij.matiere;
       myfile2.write((char*)&biij,sizeof(bijou));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(2), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&biij,sizeof(bijou)))
   {
       myfile4.write((char*)&biij,sizeof(bijou));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==6){
    ifstream myfile1;
    myfile1.open(getnamefile(2), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    bijou biij;
   while (myfile1.read((char*)&biij,sizeof(bijou)))
   {
     if (biij.mat!=jat)
     {
         myfile2.write((char*)&biij,sizeof(bijou));
     };
      if (biij.mat==jat)
     {  
       cout<<"donner le nouveau poid: ";cin>>biij.poids;
       myfile2.write((char*)&biij,sizeof(bijou));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(2), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&biij,sizeof(bijou)))
   {
       myfile4.write((char*)&biij,sizeof(bijou));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
  if(choix==7){
    ifstream myfile1;
    myfile1.open(getnamefile(2), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    bijou biij;
   while (myfile1.read((char*)&biij,sizeof(bijou)))
   {
     if (biij.mat!=jat)
     {
         myfile2.write((char*)&biij,sizeof(bijou));
     };
      if (biij.mat==jat)
     {  
      cout<<"donner le nouveau type ";cin>>biij.type;
       myfile2.write((char*)&biij,sizeof(bijou));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(2), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&biij,sizeof(bijou)))
   {
       myfile4.write((char*)&biij,sizeof(bijou));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix<1||choix>7){
    cout<<"veuillez redonner un chiffre entre 1 et 7"<<endl;
    goto exit_if99;
    exit_loop477:cout<<"le fichier n'existe memee pas" ;
   }

   
   }
   //**********MODIFIER LES PICESSS MONNAIIIEESS************
   if(type=="Piéce")
   { 
    readfile(type);
    fstream myfileeea;
    myfileeea.open(getnamefile(3),ios::binary |ios:: in);
            if(!myfileeea.is_open()){goto exit_loop333;}
    cout<<endl<<"donnez le matricule de l'objet que vous voulez modifier: ";cin>>jat;
    cout<<endl;
    cout<<"q'est ce que vous voulez modifier"<<endl;
   
    cout<<"     1- le nom du donneur"<<endl;
    cout<<"     2- Le prenom du donneur"<<endl;
    cout<<"     3-  le nom de l'objet"<<endl;
    cout<<"     4-  La date "<<endl;
    cout<<"     5-  la matiere."<<endl;
    cout<<"     6-  le poid"<<endl;
    cout<<"     7-  la valeur."<<endl;
    cout<<"     8-  la période de son utilisation."<<endl;
    cout<<"  *********************************************"<<endl;
    exit_if66: ;
    cout<<"veuillez donnez un chiffre: ";
    cin>>choix;
    if(choix==1){
    ifstream myfile1;
    myfile1.open(getnamefile(3), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    pm pmm;
   while (myfile1.read((char*)&pmm,sizeof(pm)))
   {
     if (pmm.mat!=jat)
     {
         myfile2.write((char*)&pmm,sizeof(pm));
     };
      if (pmm.mat==jat)
     {  
      cout<<"donner le neuveau nom de donneur: ";cin>>pmm.nom;
       myfile2.write((char*)&pmm,sizeof(pm));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(3), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&pmm,sizeof(pm)))
   {
       myfile4.write((char*)&pmm,sizeof(pm));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };

   if(choix==2){
    ifstream myfile1;
    myfile1.open(getnamefile(3), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    pm pmm;
   while (myfile1.read((char*)&pmm,sizeof(pm)))
   {
     if (pmm.mat!=jat)
     {
         myfile2.write((char*)&pmm,sizeof(pm));
     };
      if (pmm.mat==jat)
     {  
      cout<<"donner le neuveau prenom: ";cin>>pmm.prenom;
       myfile2.write((char*)&pmm,sizeof(pm));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(3), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&pmm,sizeof(pm)))
   {
       myfile4.write((char*)&pmm,sizeof(pm));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
    if(choix==3){
    ifstream myfile1;
    myfile1.open(getnamefile(3), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    pm pmm;
   while (myfile1.read((char*)&pmm,sizeof(pm)))
   {
     if (pmm.mat!=jat)
     {
         myfile2.write((char*)&pmm,sizeof(pm));
     };
      if (pmm.mat==jat)
     {  
      cout<<"donner le neuveau nom d'objet: ";cin>>pmm.nobb;
       myfile2.write((char*)&pmm,sizeof(pm));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(3), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&pmm,sizeof(pm)))
   {
       myfile4.write((char*)&pmm,sizeof(pm));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==4){
    ifstream myfile1;
    myfile1.open(getnamefile(3), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    pm pmm;
   while (myfile1.read((char*)&pmm,sizeof(pm)))
   {
     if (pmm.mat!=jat)
     {
         myfile2.write((char*)&pmm,sizeof(pm));
     };
      if (pmm.mat==jat)
     {  
      cout<<"donner la nouvelle date: ";cin>>pmm.date;
       myfile2.write((char*)&pmm,sizeof(pm));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(3), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&pmm,sizeof(pm)))
   {
       myfile4.write((char*)&pmm,sizeof(pm));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==5){
    ifstream myfile1;
    myfile1.open(getnamefile(3), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    pm pmm;
   while (myfile1.read((char*)&pmm,sizeof(pm)))
   {
     if (pmm.mat!=jat)
     {
         myfile2.write((char*)&pmm,sizeof(pm));
     };
      if (pmm.mat==jat)
     {  
      cout<<"donner la nouvelle matière: ";cin>>pmm.matiere;
       myfile2.write((char*)&pmm,sizeof(pm));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(3), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&pmm,sizeof(pm)))
   {
       myfile4.write((char*)&pmm,sizeof(pm));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==6){
    ifstream myfile1;
    myfile1.open(getnamefile(3), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    pm pmm;
   while (myfile1.read((char*)&pmm,sizeof(pm)))
   {
     if (pmm.mat!=jat)
     {
         myfile2.write((char*)&pmm,sizeof(pm));
     };
      if (pmm.mat==jat)
     {  
       cout<<"donner le nouveau poid: ";cin>>pmm.poids;
       myfile2.write((char*)&pmm,sizeof(pm));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(3), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&pmm,sizeof(pm)))
   {
       myfile4.write((char*)&pmm,sizeof(pm));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
  if(choix==7){
    ifstream myfile1;
    myfile1.open(getnamefile(3), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    pm pmm;
   while (myfile1.read((char*)&pmm,sizeof(pm)))
   {
     if (pmm.mat!=jat)
     {
         myfile2.write((char*)&pmm,sizeof(pm));
     };
      if (pmm.mat==jat)
     {  
      cout<<"donner la nouvelle valeurs";cin>>pmm.valeurs;
       myfile2.write((char*)&pmm,sizeof(pm));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(3), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&pmm,sizeof(pm)))
   {
       myfile4.write((char*)&pmm,sizeof(pm));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix<1||choix>7){
    cout<<"veuillez redonner un chiffre entre 1 et 7"<<endl;
    goto exit_if66;

   }
   if(choix==8){
    ifstream myfile1;
    myfile1.open(getnamefile(3), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    pm pmm;
   while (myfile1.read((char*)&pmm,sizeof(pm)))
   {
     if (pmm.mat!=jat)
     {
         myfile2.write((char*)&pmm,sizeof(pm));
     };
      if (pmm.mat==jat)
     {  
      cout<<"donner la nouvelle période de son utilisation";cin>>pmm.prd;
       myfile2.write((char*)&pmm,sizeof(pm));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(3), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&pmm,sizeof(pm)))
   {
       myfile4.write((char*)&pmm,sizeof(pm));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix<1||choix>7){
    cout<<"veuillez redonner un chiffre entre 1 et 7"<<endl;
    goto exit_if66;
    exit_loop333:cout<<"le fichier n'existe memee pas" ;

   }
   
   }
   //**********MODIFIER LES MANUSCRITS******************************
   if(type=="Manuscrit")
   { 
    readfile(type);
    fstream myfileeea;
    myfileeea.open(getnamefile(4),ios::binary |ios:: in);
            if(!myfileeea.is_open()){goto exit_loop888;}
    cout<<endl<<"donnez le matricule de l'objet que vous voulez modifier: ";cin>>jat;
    cout<<endl;
    cout<<"q'est ce que vous voulez modifier"<<endl;
   
    cout<<"     1- le nom du donneur"<<endl;
    cout<<"     2- Le prenom du donneur"<<endl;
    cout<<"     3-  le nom de l'objet"<<endl;
    cout<<"     4-  La date "<<endl;
    cout<<"     5-  le nom et le prénom de l'auteur."<<endl;
    cout<<"     6-  le nombre de pages"<<endl;
    cout<<"     7-  la langue d'édition."<<endl;
    cout<<"  *********************************************"<<endl;
    exit_if55: ;
    cout<<"veuillez donnez un chiffre: ";
    cin>>choix;cout<<endl;
    if(choix==1){
    ifstream myfile1;
    myfile1.open(getnamefile(4), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    man mann;
   while (myfile1.read((char*)&mann,sizeof(man)))
   {
     if (mann.mat!=jat)
     {
         myfile2.write((char*)&mann,sizeof(man));
     };
      if (mann.mat==jat)
     {  
      cout<<"donner le neuveau nom de donneur: ";cin>>mann.nom;
       myfile2.write((char*)&mann,sizeof(man));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(4), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&mann,sizeof(man)))
   {
       myfile4.write((char*)&mann,sizeof(man));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };

   if(choix==2){
    ifstream myfile1;
    myfile1.open(getnamefile(4), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    man mann;
   while (myfile1.read((char*)&mann,sizeof(man)))
   {
     if (mann.mat!=jat)
     {
         myfile2.write((char*)&mann,sizeof(man));
     };
      if (mann.mat==jat)
     {  
      cout<<"donner le neuveau prenom: ";cin>>mann.prenom;
       myfile2.write((char*)&mann,sizeof(man));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(4), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&mann,sizeof(man)))
   {
       myfile4.write((char*)&mann,sizeof(man));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
    if(choix==3){
    ifstream myfile1;
    myfile1.open(getnamefile(4), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    man mann;
   while (myfile1.read((char*)&mann,sizeof(man)))
   {
     if (mann.mat!=jat)
     {
         myfile2.write((char*)&mann,sizeof(man));
     };
      if (mann.mat==jat)
     {  
      cout<<"donner le neuveau nom d'objet: ";cin>>mann.nobb;
       myfile2.write((char*)&mann,sizeof(man));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(4), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&mann,sizeof(man)))
   {
       myfile4.write((char*)&mann,sizeof(man));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==4){
    ifstream myfile1;
    myfile1.open(getnamefile(4), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    man mann;
   while (myfile1.read((char*)&mann,sizeof(man)))
   {
     if (mann.mat!=jat)
     {
         myfile2.write((char*)&mann,sizeof(man));
     };
      if (mann.mat==jat)
     {  
      cout<<"donner la nouvelle date: ";cin>>mann.date;
       myfile2.write((char*)&mann,sizeof(man));
        vr=true;
     };
  
   }
     myfile1.close();
     myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(4), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&mann,sizeof(man)))
   {
       myfile4.write((char*)&mann,sizeof(man));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==5){
    ifstream myfile1;
    myfile1.open(getnamefile(4), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    man mann;
   while (myfile1.read((char*)&mann,sizeof(man)))
   {
     if (mann.mat!=jat)
     {
         myfile2.write((char*)&mann,sizeof(man));
     };
      if (mann.mat==jat)
     {  
      cout<<"donner la nouveau nom  de l'auteur: ";cin>>mann.no;cout<<endl;
      cout<<"donner la nouveau prenom  de l'auteur: ";cin>>mann.po;
       myfile2.write((char*)&mann,sizeof(man));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(4), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&mann,sizeof(man)))
   {
       myfile4.write((char*)&mann,sizeof(man));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==6){
    ifstream myfile1;
    myfile1.open(getnamefile(4), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    man mann;
   while (myfile1.read((char*)&mann,sizeof(man)))
   {
     if (mann.mat!=jat)
     {
         myfile2.write((char*)&mann,sizeof(man));
     };
      if (mann.mat==jat)
     {  
       cout<<"donner la nouvelle valeur de nombre de pages";cin>>mann.npage;
       myfile2.write((char*)&mann,sizeof(man));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(4), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&mann,sizeof(man)))
   {
       myfile4.write((char*)&mann,sizeof(man));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
  if(choix==7){
    ifstream myfile1;
    myfile1.open(getnamefile(4), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    man mann;
   while (myfile1.read((char*)&mann,sizeof(man)))
   {
     if (mann.mat!=jat)
     {
         myfile2.write((char*)&mann,sizeof(man));
     };
      if (mann.mat==jat)
     {  
      cout<<"donner le nouvelle langue d'édition: ";cin>>mann.langue;
       myfile2.write((char*)&mann,sizeof(man));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(4), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&mann,sizeof(man)))
   {
       myfile4.write((char*)&mann,sizeof(man));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix<1||choix>7){
    cout<<"veuillez redonner un chiffre entre 1 et 7"<<endl;
    goto exit_if55;
    exit_loop888:cout<<"le fichier n'existe memee pas" ;

   }


   };
   //************MODIFIER OBJET DIVERS****************************
    if(type=="Objet")
   { 
    readfile(type);
    fstream myfileeea;
    myfileeea.open(getnamefile(5),ios::binary |ios:: in);
            if(!myfileeea.is_open()){goto exit_loop999;}
    cout<<endl<<"donnez le matricule de l'objet que vous voulez modifier: ";cin>>jat;
    cout<<endl;
    cout<<"q'est ce que vous voulez modifier"<<endl;
   
    cout<<"     1- le nom du donneur"<<endl;
    cout<<"     2- Le prenom du donneur"<<endl;
    cout<<"     3-  le nom de l'objet"<<endl;
    cout<<"     4-  La date "<<endl;
    
    cout<<"  *********************************************"<<endl;
    exit_if44: ;
    cout<<"veuillez donnez un chiffre: ";
    cin>>choix;cout<<endl;
    if(choix==1){
    ifstream myfile1;
    myfile1.open(getnamefile(5), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
   obj objj;
   while (myfile1.read((char*)&objj,sizeof(obj)))
   {
     if (objj.mat!=jat)
     {
         myfile2.write((char*)&objj,sizeof(obj));
     };
      if (objj.mat==jat)
     {  
      cout<<"donner le neuveau nom de donneur: ";cin>>objj.nom;
       myfile2.write((char*)&objj,sizeof(obj));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(5), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&objj,sizeof(obj)))
   {
       myfile4.write((char*)&objj,sizeof(obj));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };

   if(choix==2){
    ifstream myfile1;
    myfile1.open(getnamefile(5), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
    obj objj;
   while (myfile1.read((char*)&objj,sizeof(obj)))
   {
     if (objj.mat!=jat)
     {
         myfile2.write((char*)&objj,sizeof(obj));
     };
      if (objj.mat==jat)
     {  
      cout<<"donner le neuveau prenom: ";cin>>objj.prenom;
       myfile2.write((char*)&objj,sizeof(obj));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(5), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&objj,sizeof(obj)))
   {
       myfile4.write((char*)&objj,sizeof(obj));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
    if(choix==3){
    ifstream myfile1;
    myfile1.open(getnamefile(5), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
     obj objj;
   while (myfile1.read((char*)&objj,sizeof(obj)))
   {
     if (objj.mat!=jat)
     {
         myfile2.write((char*)&objj,sizeof(obj));
     };
      if (objj.mat==jat)
     {  
      cout<<"donner le neuveau nom d'objet: ";cin>>objj.nobb;
       myfile2.write((char*)&objj,sizeof(obj));
        vr=true;
     };
  
   }
   myfile1.close();
   myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(5), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&objj,sizeof(obj)))
   {
       myfile4.write((char*)&objj,sizeof(obj));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;}

   };
   if(choix==4){
    ifstream myfile1;
    myfile1.open(getnamefile(5), ios::in | ios::binary);
    ofstream myfile2;
    myfile2.open("temp.bin", ios::out | ios::binary);
   obj objj;
   while (myfile1.read((char*)&objj,sizeof(obj)))
   {
     if (objj.mat!=jat)
     {
         myfile2.write((char*)&objj,sizeof(obj));
     };
      if (objj.mat==jat)
     {  
      cout<<"donner la nouvelle date: ";cin>>objj.date;
       myfile2.write((char*)&objj,sizeof(obj));
        vr=true;
     };
  
   }
     myfile1.close();
     myfile2.close();
    ofstream myfile4;
    myfile4.open(getnamefile(5), ios::out | ios::binary);
    ifstream myfile8;
    myfile8.open("temp.bin", ios::out | ios::binary);
   while (myfile8.read((char*)&objj,sizeof(obj)))
   {
       myfile4.write((char*)&objj,sizeof(obj));
     
   };
   myfile8.close();
   myfile4.close();
    remove("temp.bin");
   if(vr==false){cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;;}

   };
   
   if(choix<1||choix>4){
    cout<<"veuillez redonner un chiffre entre 1 et 7"<<endl;
    goto exit_if44;
     exit_loop999:cout<<"le fichier n'existe memee pas" ;
   }
   };
   
   };
   //************RECHERCHER**************************************************************
   //**************************************************************************************
   void rechercher(string type){
    bool dd=false;
    int jat;
   
   if(type=="Bijou"){
    bijou bij;
    ifstream myfile;
    myfile.open(getnamefile(2),ios::binary|ios::in);
            if(!myfile.is_open()){goto exit_loop322;};
    cout<<"veuillez donnez la matricule de l'objet que vous cherchez: ";cin>>jat;cout<<endl;
    while (myfile.read((char*)&bij,sizeof(bij)))
    { 
      if (bij.mat==jat)
    {
      dd==true;
       cout<<"********objet trouvé*******"<<endl;
       cout<<"nom d'objet : " << bij.nobb<<endl;
       cout<<"date  : " <<bij.date<<endl; 
       cout<<"prenom de donneur : " <<bij.prenom<<endl;
       cout<<"nom de donneur : "<<bij.nom<<endl ;
       cout<<"nom de matricule : " <<bij.mat<<endl;
       cout<<"la matière de bijoux : "<<bij.matiere<<endl;
       cout<<"le poids de bijoux : "<<bij.poids<<endl;
       cout<<"le type de bijoux : "<<bij.type<<endl;
      
    };
      
    };
    if(dd==false){
      cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;
    }

    myfile.close();
    exit_loop322:cout<<"le fichier n'existe memee pas" ;
   };
   //***************************
   if(type=="Piéce"){
    pm pmmm;
    ifstream myfile12;
    myfile12.open(getnamefile(3),ios::binary|ios::in);
    if(!myfile12.is_open()){goto exit_loop223;};
    cout<<"veuillez donnez la matricule de l'objet que vous cherchez: ";cin>>jat;cout<<endl;
    while (myfile12.read((char*)&pmmm,sizeof(pm)))
    { 
      if (pmmm.mat==jat)
    {
      dd==true;
   cout<<"********objet trouvé*******"<<endl;
   cout<<"nom d'objet : " << pmmm.nobb<<endl;
   cout<<"date  : " <<pmmm.date<<endl; 
   cout<<"prenom de donneur : " <<pmmm.prenom<<endl;
   cout<<"nom de donneur : "<<pmmm.nom<<endl ;
   cout<<"nom de matricule : " <<pmmm.mat<<endl;
   cout<<"la matière de piéce : "<<pmmm.matiere<<endl;
   cout<<"la valeur de piéce : "<<pmmm.valeurs<<endl;
   cout<<"la période de piéce : "<<pmmm.prd<<endl;
      
    };
    
      
    };
    myfile12.close();
    if(dd==false){
      cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;
    }
    exit_loop223:cout<<"le fichier n'existe memee pas" ;
   };
   //********************************************
    if(type=="Manuscrit"){
    man mann;
    ifstream myfile12;
    myfile12.open(getnamefile(4),ios::binary|ios::in);
    if(!myfile12.is_open()){goto exit_loop1010;};
    cout<<"veuillez donnez la matricule de l'objet que vous cherchez: ";cin>>jat;cout<<endl;
    while (myfile12.read((char*)&mann,sizeof(man)))
    { 
      if (mann.mat==jat)
    {
      dd==true;
   cout<<"********objet trouvé*******"<<endl;
   cout<<"nom d'objet : " << mann.nobb<<endl;
   cout<<"date  : " <<mann.date<<endl; 
   cout<<"prenom de donneur : " <<mann.prenom<<endl;
   cout<<"nom de donneur : "<<mann.nom<<endl ;
   cout<<"nom de matricule : " <<mann.mat<<endl;
   cout<<"la langue  : "<<mann.langue<<endl;
   cout<<"le nombre des page : "<<mann.npage<<endl;
   cout<<"nom de l'auteur : "<<mann.no<<endl;
    cout<<"prenom de l'auteur : "<<mann.po<<endl;
    };
    
      
    };
    if(dd==false){
      cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;
    }
    myfile12.close();
    exit_loop1010:cout<<"le fichier n'existe memee pas" ;
   };
    //**********************************************
    if(type=="Objet"){
    obj objj;
    ifstream myfile88;
    myfile88.open(getnamefile(5),ios::binary|ios::in);
    if(!myfile88.is_open()){goto exit_loop963;};
    cout<<"veuillez donnez la matricule de l'objet que vous cherchez: ";cin>>jat;cout<<endl;
    while (myfile88.read((char*)&objj,sizeof(obj)))
    { 
      if (objj.mat==jat)
    {
      dd==true;
    cout<<"********objet trouvé*******"<<endl;
    cout<<"nom d'objet : " << objj.nobb<<endl;
    cout<<"date  : " <<objj.date<<endl; 
    cout<<"prenom de donneur : " <<objj.prenom<<endl;
    cout<<"nom de donneur : "<<objj.nom<<endl ;
    cout<<"nom de matricule : " <<objj.mat<<endl;
    };
    
      
    };
    if(dd==false){
      cout<<"LE MATRICULE N'EXISTE PAS OU BIEN LE FICHIER EST VIDE"<<endl;
    }
    myfile88.close();
    exit_loop963:cout<<"le fichier n'existe memee pas" ;
   };

   };
   //**********SETTIIIIIINGGGGGGGGG*********************
  void settting(){
    int choice;
    string qq;
    cout<<"pour changer le nom de fichier veuillez taper lequelle: "<<endl;
    cout<<"     1- le fichier des objet non classé"<<endl;
    cout<<"     2- le fichier des bijou"<<endl;
    cout<<"     3- le fichier des pièces monnaies"<<endl;
    cout<<"     4- le fichier des manuscrits"<<endl;
    cout<<"     5-  le fichier des objet divers"<<endl;
    
    cout<<"  *********************************************"<<endl;  
    exit_if43: ;
    cout<<"veuillez introduire un nombre : ";cin>>choice;
    if(choice==1){
    cout<<"veuillez introduire le nouveau nom de fichier : ";cin>>qq;
  
    ofstream ff("temmp.txt");
    ff<<qq<<endl<<getnamefile(2)<<endl<<getnamefile(3)<<endl<<getnamefile(4)<<endl<<getnamefile(5);
    ff.close();
    remove("setting.txt");
    rename("temmp.txt","setting.txt");
  };
   if(choice==2){
    cout<<"veuillez introduire le nouveau nom de fichier : ";cin>>qq;
  
    ofstream ff("temmp.txt");
    ff<<getnamefile(1)<<endl<<qq<<endl<<getnamefile(3)<<endl<<getnamefile(4)<<endl<<getnamefile(5);
    ff.close();
    remove("setting.txt");
    rename("temmp.txt","setting.txt");
  };
   if(choice==3){
    cout<<"veuillez introduire le nouveau nom de fichier : ";cin>>qq;
  
    ofstream ff("temmp.txt");
    ff<<getnamefile(1)<<endl<<getnamefile(2)<<endl<<qq<<endl<<getnamefile(4)<<endl<<getnamefile(5);
    ff.close();
    remove("setting.txt");
    rename("temmp.txt","setting.txt");
  };
   if(choice==4){
    cout<<"veuillez introduire le nouveau nom de fichier : ";cin>>qq;
  
    ofstream ff("temmp.txt");
    ff<<getnamefile(1)<<endl<<getnamefile(2)<<endl<<getnamefile(3)<<endl<<qq<<endl<<getnamefile(5);
    ff.close();
    remove("setting.txt");
    rename("temmp.txt","setting.txt");
  };
   if(choice==5){
    cout<<"veuillez introduire le nouveau nom de fichier : ";cin>>qq;
  
    ofstream ff("temmp.txt");
    ff<<getnamefile(1)<<endl<<getnamefile(2)<<endl<<getnamefile(3)<<endl<<getnamefile(4)<<endl<<qq;
    ff.close();
    remove("setting.txt");
    rename("temmp.txt","setting.txt");
  };
  if(choice<1||choice>5){
    cout<<"veuillez redonner un chiffre entre 1 et 5"<<endl;
    goto exit_if43;

   }

  };

