#include <iostream>
#include <fstream>

using namespace std;

int contenuto(int, int, int, int);
bool overlap (int, int, int, int);

int main(int argc, char const *argv[])
{
    /****************************************************************/
    /*PARTE 1*/
    /****************************************************************/
    fstream in; 
    in.open("../input/day4.txt", ios::in);
    if(!in.is_open()){
        cerr << "Impossibile aprire il file" << endl; 
        exit(1);
    }

    // questi sono gli estremi del range
    int min1 = 0, max1 = 0, 
        min2 = 0, max2 = 0;
    int primo = 1, inf = 1;
    int counter = 0;
    char c;
    int overlaps = 0;

    while (in.get(c)){
        if(c >= '0' && c <= '9'){
            if(inf == 1){
                if(primo == 1){
                    min1 = 10*min1;
                    min1 += c-'0';
                }
                else if(primo == 0){
                    min2 = 10*min2;
                    min2 += c -'0';
                }
            } else if (inf == 0){
                if(primo == 1){
                    max1 = 10*max1;
                    max1 += c-'0';
                }
                else if(primo == 0){
                    max2 = 10*max2;
                    max2 += c-'0';
                }
            } else {
                cout << "Errore riga 37" << endl; 
            }
        } 
        else if (c == '-'){
            inf = 0;
        }
        else if (c == ','){
            primo = 0;
            inf = 1;
        }
        else if (c == '\n'){
            if(contenuto(min1, min2, max1, max2) != 0){
                counter++;
            }
            if(overlap(min1, min2, max1, max2) == true){
                overlaps++;
            }
            primo = 1;
            inf = 1;
            min1 = min2 = max1 = max2 = 0;
        }
        /*
        - se c == numero
            - se inf = 1 allora aggiungilo al minimo (traslando il numero precedente)
                - se primo == 1 allora stai leggendo cifre del minimo del primo elfo
                - se primo == 0 allora stai leggendo cifre del minimo del secondo elfo
            - se inf = 0 (false) allora aggiungilo al massimo (traslando il numero precedente)
                - se primo == 1 allora stai leggendo cifre del massimo del primo elfo
                - se primo == 0 allora stai leggendo cifre del massimo del secondo elfo
        - se c == '-' => inf = 0 (false)
        - se c == ',' => primo = 0 (false) && inf = 1 (true)
        - se c == '\n' => primo = 1 (true) && inf = 1 (true) min1=min2=max1=max2=0
        */
    }
    

    
    cout << "Counter: " << counter << endl;
    cout << "Overlaps: " << overlaps << endl;


    /****************************************************************/
    /*PARTE 2*/
    /****************************************************************/
    
    
    in.close();
    return 0;
}

int contenuto(int min1, int min2, int max1, int max2){

    if(min1 >= min2 && max1 <= max2){
        return 1;
    }
    if(min1 <= min2 && max1 >= max2){
        return 2;
    }
    return 0; 
    /* CONTROLLARE CHE I DUE RANGE SIANO CONTENUTI UNO NELL'ALTRO:
        - controllo se min1 >= min2 e max1<= max2 
            - se lo è return 1;
            - se non lo è vado avanti
        - controllo se min2 >= min1 e max2 <= max1
            - se lo è return 2;
            - se non lo è vado avanti
        - se sono arrivato qui nessuno è contenuto => return 0

        VALORI DI RITORNO: 
        - 0 nessuno è contenuto
        - 1 il primo è contenuto nel secondo
        - 2 il secondo è contenuto nel primo
    */    
}
bool overlap (int min1, int min2, int max1, int max2){
    if(min1 <= max1 && max1 < min2){
        return false;
    }
    if(min2 <= max2 && max2 < min1){
        return false; 
    }
    return true;
}