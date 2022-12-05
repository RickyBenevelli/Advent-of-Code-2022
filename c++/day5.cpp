#include <iostream>
#include <fstream>

#include "./TDA/stack.h"

#define DIM_BASE 9

using namespace std;


int main(int argc, char const *argv[])
{
    fstream in; 
    in.open("../input/day5.txt", ios::in);
    if(!in.is_open()){
        cerr << "Impossibile aprire il file" << endl; 
        exit(1);
    }
    
    char c, e; 
    int indice_stack = 1, parentesi = 0, spazi = 0, acapi = 0;
    int lettura_mappa = 0, i_numero = 0, numeri[3]={}; 
    nodo_s * base_supporto[DIM_BASE];
    nodo_s * base[DIM_BASE];

    for (int i = 0; i < DIM_BASE; i++){
        init_stack(base[i]);
    }
    for (int i = 0; i < DIM_BASE; i++){
        init_stack(base_supporto[i]);
    }
    

    while (in.get(c)){

        if(lettura_mappa == 0){
            if(c == ' '){
                if (spazi == 4){
                    indice_stack += 1;
                    spazi = 0;
                }
                spazi += 1;
                acapi = 0;
                continue;
            }
            else if(c == '['){
                if(acapi != 1){
                    indice_stack += 1;
                }
                acapi = 0;
                spazi = 0;
                parentesi += 1;
                continue;
            }
            else if(c == ']'){
                parentesi -= 1;
                continue;
            }
            else if (c == '\n'){
                acapi += 1;
                indice_stack = 1;
                spazi = 0;
            }
            else { // c allora è una lettera

                if(parentesi == 1){
                    if(push_stack(c, base_supporto[indice_stack-1]) == FAIL){
                        cerr << "Errore di inserimento dell'elemento " << c << "della colonna" << indice_stack << " nello stack" << endl; 
                        exit(2);
                    }
                } 
                else {
                    acapi = 0;
                    lettura_mappa = 1;

                    char elemento; // da uno stack all'altro
                    for (int j = 0; j < DIM_BASE; j++){
                        while (top_stack(elemento, base_supporto[j]) == OK){
                            if(push_stack(elemento, base[j]) == FAIL){
                                cerr << "Errore di inserimento dell'elemento nel secondo stack" << endl; 
                            }
                            pop_stack(base_supporto[j]);
                        }
                    }
                }
            }
        }
        else if (lettura_mappa == 1){
            if(c == '\n'){
                acapi += 1;
                if(acapi == 2){
                    spazi = 0; 
                    lettura_mappa = 2;
                    for (int i = 0; i < DIM_BASE; i++)
                    {
                        print_stack(base_supporto[i]);
                        cout << "********" << endl; 
                    }
                    
                }
            }
        }
        else if (lettura_mappa == 2){
            if(c >= '0' && c <= '9'){
                if(spazi == 2){
                    i_numero += 1;
                } 
                if(i_numero >= 0 && i_numero < 3){
                    numeri[i_numero] = numeri[i_numero]*10 + (c-'0');
                    spazi = 0; 
                }
            }
            else if(c == ' '){
                spazi += 1; 
            }
            else if(c == '\n'){
                i_numero = 0; 
                for (int i = 0; i < numeri[0]; i++){
                    /********************************/
                    /********PRIMA PARTE*************/
                    /********************************/
                    // if(top_stack(e, base[numeri[1]-1]) == FAIL){
                    //     cout << "how many: " << numeri[0] << " from: " << numeri[1] << " to: " << numeri[2] << endl; 
                    // }
                    // if(push_stack(e, base[numeri[2]-1]) == FAIL){
                    //     cout << "how many: " << numeri[0] << " from: " << numeri[1] << " to: " << numeri[2] << endl; 
                    // }
                    // if(pop_stack(base[numeri[1]-1]) == FAIL){
                    //     cout << "how many: " << numeri[0] << " from: " << numeri[1] << " to: " << numeri[2] << endl; 
                    // }
                    /********* fine prima parte *************/

                    /*********************************************/
                    /*************SECONDA PARTE*******************/
                    /*********************************************/
                    if(top_stack(e, base[numeri[1]-1]) == FAIL){
                        cout << "how many: " << numeri[0] << " from: " << numeri[1] << " to: " << numeri[2] << endl; 
                    }
                    if(push_stack(e, base_supporto[0]) == FAIL){
                        cout << "how many: " << numeri[0] << " from: " << numeri[1] << " to: " << numeri[2] << endl; 
                    }
                    if(pop_stack(base[numeri[1]-1]) == FAIL){
                        cout << "how many: " << numeri[0] << " from: " << numeri[1] << " to: " << numeri[2] << endl; 
                    }
                    /********* fine seconda parte *************/
                }
                /*********************************************/
                /*************SECONDA PARTE*******************/
                /*********************************************/
                for (int i = 0; i < numeri[0]; i++){
                    if(top_stack(e, base_supporto[0]) == FAIL){
                        cout << "how many: " << numeri[0] << " from: " << numeri[1] << " to: " << numeri[2] << endl; 
                    }
                    if(push_stack(e, base[numeri[2]-1]) == FAIL){
                        cout << "how many: " << numeri[0] << " from: " << numeri[1] << " to: " << numeri[2] << endl; 
                    }
                    if(pop_stack(base_supporto[0]) == FAIL){
                        cout << "how many: " << numeri[0] << " from: " << numeri[1] << " to: " << numeri[2] << endl; 
                    }
                }
                /********* fine seconda parte *************/
                for (int i = 0; i < 3; i++)
                {
                    numeri[i] = 0; 
                }
                
            }
        }
    }
    
    for (int i = 0; i < DIM_BASE; i++){
        print_stack(base[i]);
        cout << "****-" << i << "-********" << endl; 
    }
    
    

    for (int i = 0; i < DIM_BASE; i++){
        if((deinit_stack(base[i]) == FAIL) || (deinit_stack(base_supporto[i]) == FAIL)){
            cerr << "Errore nella deallocazione" << endl;
            exit(5);
        }
    }
    
    in.close();
    return 0;
}

