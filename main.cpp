#include <iostream>
#include <string>
#include <locale>
using namespace std;

string chiffrement_func(
                const string &texte,
                int key){
                string enregistrementtexte;
                for (char lettre:texte){
                   if (isalpha(lettre)) {
                        char verify = isupper(lettre) ? 'A' : 'a';
                        int index = lettre - verify;
                        int new_index = (index + key) % 26;
                        char new_lettre = verify + new_index;
                        enregistrementtexte += new_lettre;
                    } else {
                        // Si le caractère n'est pas alphabétique, le conserve tel quel
                        enregistrementtexte += lettre;
                    }
                }
                return enregistrementtexte;
}
string dechiffrement_func(
                const string &enregistrementtexte,
                int key){
                string texte;
                for (char lettre:enregistrementtexte){
                   if (isalpha(lettre)) {
                        char base = isupper(lettre) ? 'A' : 'a';
                        int index = lettre - base;
                        int new_index = (index - key + 26) % 26;
                        char new_lettre = base + new_index;
                        texte += new_lettre;
                    } else {
                        // Si le caractère n'est pas alphabétique, le conserve tel quel
                        texte += lettre;
                    }
                }
                return texte;
}

int main()
{
    setlocale(LC_ALL, ""); // Utilisez l'encodage par défaut du système
    string texte;
    string enregistrementtexte;
    int cle,numero;

    cout<<"Veuillez selectionner un numero :"<<endl;
    cout<<"Numéro 1 pour le cryptage 2 pour le decryptage "<<endl;
    cin>>numero;
    if (numero==1){
        cout<<"Entrer le message à crypter: ";
        cin>>texte;
        cout<<"Entrer la clé de cryptage: ";
        cin>>cle;
        string enregistrementtexte=chiffrement_func(texte,cle);
        cout<<"Voici votre message chiffré : "<<enregistrementtexte<<endl;
    }
        else if(numero==2){
            cout<<"Entrer le message à décrypter: ";
            cin>>enregistrementtexte;
            cout<<"Entrer la clé de décryptage: ";
            cin>>cle;
            string dectext=dechiffrement_func(enregistrementtexte,cle);
            cout<<"Voici votre message déchiffré : "<<dectext<<endl;
        }
        else{
            cout<<"Numéro incorrect!!!";

        }

    return 0;
}
